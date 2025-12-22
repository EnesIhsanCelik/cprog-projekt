#include "Rocketship.h"
#include "Constants.h"

Rocketship::Rocketship() : Sprite(constants::rocketship_str, 0, 0) {
    rect.w = 64.f;
    rect.h = 64.f;

    rect.x = (constants::gScreenWidth / 2.0f) - (rect.w / 2.0f);
    rect.y = constants::gScreenHeight - rect.h - 20.0f;

}

void Rocketship::tick() {
    const bool* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_LEFT] && getRect().x > 0) move(-4, 0);
    if (keys[SDL_SCANCODE_RIGHT] && getRect().x < (constants::gScreenWidth - getRect().w)) move(4, 0);
}

void Rocketship::onKeyDown(const SDL_Event& event) {
    if (event.key.scancode == SDL_SCANCODE_UP) {
        shoot();
    }
}

void Rocketship::shoot() {
    // Shooting logic here
}