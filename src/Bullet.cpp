#include "Bullet.h"
#include "Constants.h"
#include "Engine.h"
#include "FallingEnemy.h"


namespace demo {
    class Explosion : public Sprite {
    public:
        Uint64 spawnTime;
        const Uint64 duration = 250; 

        Explosion(float x, float y) : Sprite(constants::explosion_str, x, y) {
            spawnTime = SDL_GetTicks();
            rect.w = 40; 
            rect.h = 40;

            SDL_SetTextureBlendMode(getTexture(), SDL_BLENDMODE_BLEND);
        }

        void tick() override {
            Uint64 elapsed = SDL_GetTicks() - spawnTime;

            // Fading
            float progress = (float)elapsed / duration;
            int alpha = (int)(255 * (1.0f - progress));
            if (alpha < 0) alpha = 0;
            SDL_SetTextureAlphaMod(getTexture(), (Uint8)alpha);

            // Växning av explosionen
            rect.w += 0.8f;
            rect.h += 0.8f;
            rect.x -= 0.4f; 
            rect.y -= 0.4f;

            // Ta bort sig själv när tiden är ute
            if (elapsed >= duration) {
                eng.remove(shared_from_this());
            }
        }
    };
}

Bullet::Bullet(float x, float y, float speed)
    : demo::Sprite(constants::bullet_str, x, y), speed(speed)
{
    rect.w *= 0.05f;
    rect.h *= 0.05f;
}

void Bullet::tick()
{
    move(0.0f, -speed);

    if (getRect().y + getRect().h < 0)
    {
        demo::eng.remove(shared_from_this());
    }
}

void Bullet::onCollisionWith(demo::SpritePtr other)
{
    if (std::dynamic_pointer_cast<::FallingEnemy>(other))
    {
        // Skapa explosionen precis där kollisionen sker
        auto explosion = std::make_shared<demo::Explosion>(rect.x, rect.y);
        demo::eng.add(explosion);

        demo::eng.remove(other);
        demo::eng.remove(shared_from_this());
    }
}
