#pragma once
#include "Sprite.h"
#include <SDL3/SDL.h>

class Rocketship : public demo::Sprite
{
public:
    Rocketship();
    ~Rocketship();
    void tick() override;
    void onKeyDown(const SDL_Event &event) override;

private:
    void shoot();
    SDL_AudioSpec shotSpec;
    Uint8* shotBuf = nullptr;
    Uint32 shotLen = 0;
    SDL_AudioStream* shotStream = nullPtr;
};