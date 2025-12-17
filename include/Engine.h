#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include "Constants.h"

namespace cnts = constants;

class Engine
{
public:
    Engine();
    ~Engine();

    SDL_Renderer* getRen() const { return renderer; }
    SDL_Window* getWin() const { return window; }

    void addSprite(SpritePtr sprite);
    void removeSprite(SpritePtr sprite);
    void gameLoop();

private:
    SDL_Window* win;
    SDL_Renderer* ren;
    std::vector<std::shared_ptr<class Sprite>> sprites;

}