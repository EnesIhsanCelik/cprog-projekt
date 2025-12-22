#pragma once
#include "Sprite.h"

class Rocketship : public demo::Sprite
{
public:
    Rocketship();
    void tick() override;
    void onKeyDown(const SDL_Event &event) override;

private:
    void shoot();
};