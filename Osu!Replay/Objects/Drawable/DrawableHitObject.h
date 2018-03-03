#pragma once
#include <chrono>
#include <SFML/Graphics/Sprite.hpp>
#include "../HitObject.h"
#include "DrawableShape.h"

class DrawableHitObject
{
public:
    DrawableHitObject(HitObject*, BeatmapDifficulty*, std::chrono::milliseconds);
    ~DrawableHitObject();

    float X, Y;
    sf::Vector2f Position() { return sf::Vector2f(X, Y); };
    
    float Opacity();

    bool IsDead() { return (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch())) > _noteHitTime; };

    DrawableShape shape;
private:
    std::chrono::milliseconds _noteHitTime;
    std::chrono::milliseconds _fadeInDuration;
    int _noteStartTime;
    BeatmapDifficulty *_diff;
    float _opacity = 1.0f;
    bool _created = false;
};

