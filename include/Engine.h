#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "Constants.h"
#include <SDL3_ttf/SDL_ttf.h>

namespace demo {
    class Sprite;
    typedef std::shared_ptr<Sprite> SpritePtr;

    class Engine {
    public:
        Engine();
        ~Engine();

        SDL_Renderer* getRen() const { return ren; }
        SDL_Window* getWin() const { return win; }
        TTF_Font* getFont() const { return font; }

        void add(SpritePtr spr);
        void remove(SpritePtr spr);
        void run();

    private:
        SDL_Window* win;
        SDL_Renderer* ren;
        TTF_Font* font;
        // Pointers to track sprites throughout their lifecycle
        std::vector<SpritePtr> sprites, added, removed;
    };

    // Tells other files that 'eng' exists in Engine.cpp
    extern Engine eng;
}