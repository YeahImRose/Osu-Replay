#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <chrono>
#include <Windows.h>

#include "../Objects/HitObject.h"
#include "../Objects/Drawable/DrawableHitObject.h"

class ReplayReader
{
public:
    ReplayReader();
    ~ReplayReader();

    bool SetMap(char *filePath);
    bool SetReplay(char *filePath);

    void PlayReplay();

    std::deque<DrawableHitObject>* GetUpcomingObjects();

    BeatmapDifficulty beatmap;

    std::chrono::steady_clock::time_point startTime;
    std::vector<sf::Color> colours;

private:
    /*struct _slider {
        // eep
        int x, y;
        int time;
        DWORD type;
        DWORD hitSounds;
        //_sliderPath path;
        int repeat; // reverse arrows = repeat - 1
        double length; // Relative to 512x384, path length should change to match this
        double duration; // Needs to be set
        std::vector<DWORD> edgeHitsounds; // [0] = first sound, [n] = ..., [last] = last hit sound
        std::vector<std::pair<int, int>> edgeAdditions; // https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#extras
        //_extra extras;

    };*/

    /*struct _spinner {
        int x, y;
        int time;
        DWORD type;
        DWORD hitSounds;
        int endTime;
        //_extra extras;
    };*/
    std::deque<HitObject*> _hitObjects;
    std::deque<DrawableHitObject> _upcomingObjects;
};