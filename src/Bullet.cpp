#include "Bullet.h"
#include "Constants.h"
#include "Engine.h"

Bullet::Bullet(float x, float y, float speed)
    : demo::Sprite(constants::bullet_str, x, y), speed(speed) {
    
    rect.w *= 0.05f;
    rect.h *= 0.05f;
}

void Bullet::tick() {
    move(0.0f, -speed);

    if (getRect().y + getRect().h < 0) {
        demo::eng.remove(shared_from_this());
    }
};