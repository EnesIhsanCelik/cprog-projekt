#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include "Constants.h"

namespace cnts = constants;
typedef std::shared_ptr<Sprite> SpritePtr;

class Engine
{
public:
    Engine();
    ~Engine();

    SDL_Renderer* getRen() const { return ren; }
    SDL_Window* getWin() const { return win; }

    void addSprite(SpritePtr sprite);
    void removeSprite(SpritePtr sprite);
    void gameLoop();

private:
    SDL_Window* win;
    SDL_Renderer* ren;
    std::vector<std::shared_ptr<class Sprite>> sprites, added, removed;

}

Engine eng;