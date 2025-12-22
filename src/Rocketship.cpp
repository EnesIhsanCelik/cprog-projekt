#include "Rocketship.h"
#include "Constants.h"

Rocketship::Rocketship() : Sprite(constants::rocketship_str, 
                                  (constants::gScreenWidth/2) - 25, 
                                  constants::gScreenHeight - 100) {}

void Rocketship::tick() {
    const bool* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_LEFT] && getRect().x > 0) move(-5, 0);
    if (keys[SDL_SCANCODE_RIGHT] && getRect().x < (constants::gScreenWidth - getRect().w)) move(5, 0);
}

void Rocketship::onKeyDown(const SDL_Event& event) {
    if (event.key.scancode == SDL_SCANCODE_UP) {
        shoot();
    }
}

void Rocketship::shoot() {
    // Shooting logic here
}