#pragma once
#include "MovableSprite.h"

class Bullet : public demo::MovableSprite
{
public:
    Bullet(float x, float y, float speed);
    void tick() override;
    void onCollisionWith(demo::SpritePtr other) override;
private:
    float speed;
};