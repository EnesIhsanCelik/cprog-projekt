#include "Sprite.h"

namespace demo
{
    Sprite::Sprite(float x, float y, float w, float h)
        : rect{x, y, w, h} {}

    Sprite::~Sprite() {}
}