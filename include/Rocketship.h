#pragma once
#include "MovableSprite.h"
#include <SDL3/SDL.h>

class Rocketship : public demo::MovableSprite
{
public:
    Rocketship();
    ~Rocketship();
    void tick() override;
    void onKeyDown(const SDL_Event &event) override;
    void onResize(int newW, int newH) override;

private:
    void shoot();
    SDL_AudioSpec shotSpec;
    Uint8* shotBuf = nullptr;
    Uint32 shotLen = 0;
    SDL_AudioStream* shotStream = nullptr;
};