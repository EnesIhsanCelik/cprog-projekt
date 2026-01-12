#include "Background.h"
#include "Engine.h"


// Implementationen av rörliga bakgrunden
namespace demo {
    Background::Background(float y) : Sprite(constants::background2_str, 0, y) {
        rect.w = static_cast<float>(constants::gScreenWidth);
        rect.h = static_cast<float>(constants::gScreenHeight);
    }

    void Background::tick()
    {
        float speed = 0.3f; //hastighet på scrollning
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