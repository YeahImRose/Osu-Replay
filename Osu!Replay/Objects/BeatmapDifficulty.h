#pragma once

#include <string>
#include <vector>

#include "../Utils.h"

using namespace std;

typedef struct _Colour {
    int r;
    int g;
    int b;
} Colour;

typedef struct _BeatmapDifficultyType {
    /* https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#general */
    void ParseGeneral(string);

    string AudioFilename;
    int AudioLeadIn;
    int PreviewTime;
    bool Countdown;
    string SampleSet;
    double StackLeniency;
    short Mode;
    bool LetterboxInBreaks;
    bool WidescreenStoryboard;

    /* https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#editor */
    // Really don't need these, but maybe I'll use them somehow
    vector<int> Bookmarks;
    double DistanceSpacing;
    int BeatDivisor;
    int GridSize;
    int TimelineZoom;

    /* https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#metadata */
    string Title;
    string TitleUnicode;
    string Artist;
    string ArtistUnicode;
    string Creator;
    string Version;
    string Source;
    vector<string> Tags;
    int BeatmapID;
    int BeatmapSetID;

    /* https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#difficulty */
    void ParseDifficulty(string);

    double HPDrainRate;
    double CircleSize;
    double OverallDifficulty;
    double ApproachRate;
    double SliderMultiplier = 1.4;
    double SliderTickRate = 1;

    // TODO: Events

    // TODO: TimingPoints

    void ParseColours(string);
    vector<Colour> Colours;

} BeatmapDifficulty;

static double DifficultyRange(double difficulty, double min, double mid, double max)
{
    if (difficulty > 5)
        return mid + (max - mid) * (difficulty - 5) / 5;
    if (difficulty < 5)
        return mid - (mid - min) * (5 - difficulty) / 5;
    return mid;
}