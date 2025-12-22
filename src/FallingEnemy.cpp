#include "../include/FallingEnemy.h"
#include "../include/Constants.h"
#include <cstdlib>

FallingEnemy::FallingEnemy(const std::string& img, float x, float y, float speed)
    : demo::Sprite(img, x, y), speed(speed) {
    
    rect.w *= 0.10f;
    rect.h *= 0.10f;
}



void FallingEnemy::tick() {
    move(0.0f, speed);

    if (getRect().y > constants::gScreenHeight) {
        float newY = -getRect().h;
        float newX = static_cast<float>(
            std::rand() % (constants::gScreenWidth - 64)
        );

        move(newX - getRect().x, newY - getRect().y);
    }
}
