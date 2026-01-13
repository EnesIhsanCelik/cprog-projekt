#pragma once
#include "MovableSprite.h"

class FallingEnemy : public demo::MovableSprite {
public:
    FallingEnemy(const std::string& img, float x, float y, float speed);
    void tick() override;
    void onCollisionWith(demo::SpritePtr other) override;

private:
    float speed;
};