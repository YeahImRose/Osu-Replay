#pragma once
#include "HitObject.h"

class CircleObject :
    public HitObject
{
public:
    CircleObject(std::string line) { /*HitObject(line);*/ };
    ~CircleObject();
};

