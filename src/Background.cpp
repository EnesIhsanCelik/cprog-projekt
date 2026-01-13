#include "Background.h"
#include "Engine.h"

namespace demo {
    Background::Background(float y) : MovableSprite(constants::background2_str, 0, y) {
        rect.w = static_cast<float>(constants::gScreenWidth);
        rect.h = static_cast<float>(constants::gScreenHeight) + 2.0f;
    }

    void Background::tick()
    {
        float speed = 1.0f;
        rect.y += speed;
        if (rect.y >= constants::gScreenHeight) {
            rect.y -= constants::gScreenHeight * 2;
        }
    }

    void Background::onResize(int newW, int newH)
    {
        rect.w = static_cast<float>(newW);
        rect.h = static_cast<float>(newH);
    }
}