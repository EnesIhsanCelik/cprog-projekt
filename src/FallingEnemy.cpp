#include "FallingEnemy.h"
#include "Constants.h"
#include "Bullet.h"
#include "CountHits.h"
#include <cstdlib>

FallingEnemy::FallingEnemy(const std::string &img, float x, float y, float speed)
    : demo::MovableSprite(img, x, y), speed(speed)
{
    rect.w *= 0.10f;
    rect.h *= 0.10f;
}

void FallingEnemy::tick()
{
    move(0.0f, speed);

    if (rect.y > constants::gScreenHeight)
    {
        float newY = -rect.h;
        float newX = static_cast<float>(
            std::rand() % (constants::gScreenWidth - 64));

        move(newX - rect.x, newY - rect.y);
    }
}

void FallingEnemy::onCollisionWith(demo::SpritePtr other)
{
    if (std::dynamic_pointer_cast<::Bullet>(other))
    {
        game::CountHits::funk();
        rect.y = -rect.h;
        rect.x = static_cast<float>(std::rand() % (constants::gScreenWidth - 64));
    } 
}