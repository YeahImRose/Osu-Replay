#include "ReplayReader.h"

ReplayReader::ReplayReader()
{
}


ReplayReader::~ReplayReader()
{
}

enum READ_MODES {
    GENERAL,
    EDITOR,
    METADATA,
    DIFFICULTY,
    EVENTS,
    TIMING_POINTS,
    COLOURS,
    HIT_OBJECTS
};

bool ReplayReader::SetMap(char *filePath)
{
    std::deque<HitObject*> _;
    std::swap(_hitObjects, _);

    std::ifstream infile(filePath);

    int readMode = -1;

    std::string line;
    while (std::getline(infile, line))
    {
        // TODO: Find a better way to do this massive IF
        if (line == std::string("[General]")) { readMode = GENERAL; continue; }
        else if (line == std::string("[Editor]")) { readMode = EDITOR; continue; }
        else if (line == std::string("[Metadata]")) { readMode = METADATA; continue; }
        else if (line == std::string("[Difficulty]")) { readMode = DIFFICULTY; continue; }
        else if (line == std::string("[Events]")) { readMode = EVENTS; continue; }
        else if (line == std::string("[TimingPoints]")) { readMode = TIMING_POINTS; continue; }
        else if (line == std::string("[Colours]")) { readMode = COLOURS; continue; }
        else if (line == std::string("[HitObjects]")) { readMode = HIT_OBJECTS; continue; }
        else if (line == std::string("")) { readMode = -1; continue; }

        switch (readMode)
        {
        case GENERAL:
            break;
        case EDITOR:
            break;
        case METADATA:
            break;
        case DIFFICULTY:
            beatmap.ParseDifficulty(line);
            break;
        case EVENTS:
            break;
        case TIMING_POINTS:
            break;
        case COLOURS:
            break;
        case HIT_OBJECTS:
            _hitObjects.push_back(new HitObject(line));
            break;
        default:
            break;
        }
    }
    startTime = std::chrono::steady_clock::now();
    return false;
}

bool ReplayReader::SetReplay(char *filePath)
{
    return false;
}

void ReplayReader::PlayReplay()
{
}

std::deque<DrawableHitObject>* ReplayReader::GetUpcomingObjects()
{
    std::vector<int> toPop;

    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
    //auto fadeInDuration = std::chrono::milliseconds(200);
    //auto fadeOutDuration = std::chrono::milliseconds(100);

    auto preLoadTime = std::chrono::milliseconds(1000);
    auto unLoadTime = std::chrono::milliseconds(200);

    auto songStart = startTime.time_since_epoch();

    int x = 0;
    for (DrawableHitObject object : _upcomingObjects)
    {
        if (object.IsDead())
            _upcomingObjects.pop_front();
        else break;
    }
    for (;;)
    {
        if (x + toPop.size() > _hitObjects.size()) break;

        auto sTime = std::chrono::milliseconds(_hitObjects[x]->StartTime);
        auto noteStartTime = std::chrono::duration_cast<std::chrono::milliseconds>(songStart) + sTime;

        /*if (now >= noteStartTime + unLoadTime) {
            toPop.push_back(x);
            ++x;
            continue;
        }*/

        if (now >= noteStartTime - preLoadTime) {
            //printf("%d\n", now.count());
            //printf("%d\n", x);
            DrawableHitObject dho(_hitObjects[x], &beatmap, std::chrono::duration_cast<std::chrono::milliseconds>(noteStartTime));
            _upcomingObjects.push_back(dho);

            // To ensure no duplicates
            _hitObjects.pop_front();
        }
        else break;

        ++x;
    }

    /*for (int index : toPop)
    {
        _hitObjects.pop_front();
    }*/
    return &_upcomingObjects;
}
