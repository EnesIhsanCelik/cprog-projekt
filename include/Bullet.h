#pragma once
#include "Sprite.h"

class Bullet : public demo::Sprite
{
public:
    Bullet(float x, float y, float speed);
    void tick() override;
    void onCollisionWith(demo::SpritePtr other) override;
private:
    float speed;
};
