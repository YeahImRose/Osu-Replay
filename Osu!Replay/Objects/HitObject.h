#pragma once

enum TYPE_FLAGS {
    CIRCLE,
    SLIDER,
    NEW_COMBO,
    SPINNER,
    COLOR_SKIP_1,
    COLOR_SKIP_2,
    COLOR_SKIP_3,
    MANIA_HOLD
};

enum HITSOUND_FLAGS {
    SOUND_NORMAL, // Irrelevant (always played)
    SOUND_WHISTLE,
    SOUND_FINISH,
    SOUND_CLAP
};

#include <string>
#include <chrono>
#include <bitset>
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>

#include "BeatmapDifficulty.h"
#include "../Utils.h"

class HitObject
{
public:
    // https://osu.ppy.sh/help/wiki/osu!_File_Formats/Osu_(file_format)#hit-objects


    //TODO: SLIDER SUPPORT 


    HitObject(std::string);

    float X, Y; // 0, 1
    sf::Vector2f Position() { return sf::Vector2f(X, Y); };

    int StartTime;
    //int EndTime;

    std::bitset<8> type; // "Bitmap" of hit object attributes
    bool newCombo;
    int colorSkip = 0x0;
    bool maniaHold;

    std::bitset<8> hitSounds; // "Bitmap" of hit sound attributes (multiple flags can overlap)

    int sampleSet = 0;
    int additionSet = 0;
    int customIndex = 0;
    int sampleVolume = 0;
    std::string extraFilename;

    bool readyToDraw = false;
private:
    bool judged = false;
    std::string line;
};