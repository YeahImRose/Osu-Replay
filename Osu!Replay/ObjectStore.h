#pragma once
#include <chrono>

class ObjectStore
{
public:
    std::chrono::steady_clock *steadyClock;
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::milliseconds> startTime;


    static ObjectStore GetInstance()
    {
        static ObjectStore inst;
        return inst;
    }

private:
    ObjectStore() {
        steadyClock = new std::chrono::steady_clock();
        startTime = std::chrono::time_point_cast<std::chrono::milliseconds>(steadyClock->now());
    };
public:
    ObjectStore(ObjectStore const&)     = delete;
    void operator=(ObjectStore const&)  = delete;
};

