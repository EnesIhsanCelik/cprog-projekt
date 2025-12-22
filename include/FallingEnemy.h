#pragma once
#include "Sprite.h"

class FallingEnemy : public demo::Sprite {
public:
    FallingEnemy(const std::string& img, float x, float y, float speed);
    void tick() override;

private:
    float speed;
};
