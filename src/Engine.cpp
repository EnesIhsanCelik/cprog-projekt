#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include "Engine.h"
#include "Sprite.h"


Engine::Engine()
{
    SDL_Init(SDL_INIT_VIDEO);
    win = SDL_CreateWindow("Our Game", cnts::gScreenWidth, cnts::gScreenHeight, 0);
    ren = SDL_CreateRenderer(win, NULL);
    srand(time(NULL));
}

Engine::~Engine()
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}

void Engine::addSprite(SpritePtr sprite)
{
    added.push_back(sprite);
}

void Engine::removeSprite(SpritePtr sprite)
{
    removed.push_back(sprite);
}

void Engine::gameLoop()
{
    const int FPS = 60;
    const int TICKINTERVAL = 1000 / FPS;
    Uint64 nextTick = SDL_GetTicks() + TICKINTERVAL;
    bool running = true;

    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            switch (e.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            /*case SDL_EVENT_MOUSE_BUTTON_DOWN:
                for (SpritePtr spr : sprites)
                    spr->onMouseDown(e);*/
                break;
                // Handle other events as needed
            }

            for (SpritePtr spr : sprites)
                spr->tick();

            for (SpritePtr spr : added)
                sprites.push_back(spr);
            added.clear();

            for (SpritePtr spr : removed)
            {
                for (int pos = 0; pos < sprites.size(); pos++)
                {
                    auto iter = sprites.begin() + pos;
                    if (spr == *iter)
                    {
                        sprites.erase(iter);
                        break;
                    }
                }
            }
            removed.clear();

            for (SpritePtr sp1 : sprites)
                for (SpritePtr sp2 : sprites)
                    if (sp1 != sp2 && sp1->intersects(sp2))
                    {
                        sp1->onCollision(sp2);
                        sp2->onCollision(sp1);
                    }

            SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
            SDL_RenderClear(ren);
            for (SpritePtr spr : sprites)
                spr->draw(ren);
            SDL_RenderPresent(ren);

            Sint64 delay = nextTick - SDL_GetTicks();
            if (delay > 0)
                SDL_Delay(delay);
        }
    }
}

Engine eng;
