#include "HitObject.h"

HitObject::HitObject(std::string line)
{
    std::vector<std::string> args = Split(line, ",");
    X = stof(args[0]);
    Y = stof(args[1]);
    StartTime = stoi(args[2]);

    std::bitset<8> type(stoi(args[3]));
    std::bitset<8> hitSounds(stoi(args[4]));

    if (type[CIRCLE])
    {
        std::vector<std::string> extraArgs = Split(args[5], ":");
        sampleSet = stoi(extraArgs[0]);
        additionSet = stoi(extraArgs[1]);
        customIndex = stoi(extraArgs[2]);
        sampleVolume = stoi(extraArgs[3]);
        if(extraArgs.size() < 5) extraFilename = "";
        else extraFilename = extraArgs[4];
    }
    else if (type[SLIDER])
    {
        int repeat = stoi(args[6]);
        int pixelLength = stoi(args[7]);

    }
    else if (type[SPINNER])
    {

    }
    maniaHold = (type[MANIA_HOLD]);
    if (type[COLOR_SKIP_1]) colorSkip += 0x1;
    if (type[COLOR_SKIP_2]) colorSkip += 0x10;
    if (type[COLOR_SKIP_3]) colorSkip += 0x100;
}