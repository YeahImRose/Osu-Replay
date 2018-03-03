#include "BeatmapDifficulty.h"

void _BeatmapDifficultyType::ParseGeneral(string in)
{
}

void _BeatmapDifficultyType::ParseDifficulty(string in)
{
    std::vector<std::string> i = Split(in, ":");
    if (i[0] == "HPDrainRate") HPDrainRate = stof(i[1]);
    if (i[0] == "CircleSize") CircleSize = stof(i[1]);
    if (i[0] == "OverallDifficulty") OverallDifficulty = stof(i[1]);
    if (i[0] == "ApproachRate") ApproachRate = stof(i[1]);
    if (i[0] == "SliderMultiplier") SliderMultiplier = stof(i[1]);
    if (i[0] == "SliderTickRate") SliderTickRate = stof(i[1]);
}

void _BeatmapDifficultyType::ParseColours(string)
{

}
