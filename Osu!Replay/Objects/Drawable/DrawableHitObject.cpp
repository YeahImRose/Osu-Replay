#include "DrawableHitObject.h"


DrawableHitObject::DrawableHitObject(HitObject *hitObject, BeatmapDifficulty *diff, std::chrono::milliseconds noteHitTime)
{
    X = hitObject->X;
    Y = hitObject->Y;
    //shape(hitObject->)
    _diff = diff;
    _noteStartTime = hitObject->StartTime;
    _noteHitTime = noteHitTime;
    int _fadeInTime = DifficultyRange(_diff->ApproachRate, 1200, 800, 300);
    _fadeInDuration = std::chrono::milliseconds(_fadeInTime);
    
}

DrawableHitObject::~DrawableHitObject()
{
}

float DrawableHitObject::Opacity()
{
    //TODO: Reduce math here
    auto songStart = _noteHitTime - std::chrono::milliseconds(_noteStartTime);
    auto fadeInStart = _noteHitTime - _fadeInDuration;
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
    if(now.count() < fadeInStart.count()) return 0.0f;;
    //printf("%.2f\n", (diff / _fadeInDuration.count()));
    auto _n = now.count();
    auto _f = fadeInStart.count();
    float _o = ((_n - _f) / (float)_fadeInDuration.count());
    if (_o > (float)0.2) return 1.0;
    else return _o;
}
