#include "Engine.h"
#include "Sprite.h"
#include "FallingEnemy.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <iostream>
#include <cstdlib> // Added for std::rand()

namespace demo
{
    Engine::Engine()
    {
        if (!TTF_Init())
        {
            std::cerr << "TTF_Init failed: " << SDL_GetError() << std::endl;
        }
        win = SDL_CreateWindow("Our Game", constants::gScreenWidth, constants::gScreenHeight, 0);
        ren = SDL_CreateRenderer(win, NULL);

        std::string fontPath = constants::gResPath + "fonts/arial.ttf";
        font = TTF_OpenFont(fontPath.c_str(), 24);
    }

    Engine::~Engine()
    {
        if (font) TTF_CloseFont(font);
        TTF_Quit();
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
    }

    void Engine::add(SpritePtr spr)
    {
        added.push_back(spr);
    }

    void Engine::remove(SpritePtr spr)
    {
        removed.push_back(spr);
    }

    TTF_Font *Engine::getFont() const
    {
        return font;
    }

    void Engine::run()
    {
        Uint64 lastSpawnTime = SDL_GetTicks();
        Uint64 spawnInterval = 2000;
        const int FPS = 60;
        const int TICKINTERVAL = 1000 / FPS;
        bool running = true;

        while (running)
        {
            Uint64 nextTick = SDL_GetTicks() + TICKINTERVAL;
            SDL_Event event;

            while (SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                    for (SpritePtr spr : sprites)
                        spr->onMouseDown(event);
                    break;
                case SDL_EVENT_KEY_DOWN:
                    for (SpritePtr spr : sprites)
                        spr->onKeyDown(event);
                    break;
                }
            }

            // NEW SPAWNING LOGIC START FOR ENEMIES
            Uint64 currentTime = SDL_GetTicks();
            if (currentTime > lastSpawnTime + spawnInterval)
            {
                float randomX = static_cast<float>(std::rand() % (constants::gScreenWidth - 100));
                
                auto newEnemy = std::make_shared<::FallingEnemy>(
                    constants::alien_str, 
                    randomX, 
                    -100.0f,
                    2.0f + (std::rand() % 4)
                );
                
                this->add(newEnemy);
                lastSpawnTime = currentTime;
            }
            // SPAWNING LOGIC END

            for (SpritePtr spr : sprites)
                spr->tick();

            for (SpritePtr spr : added)
                sprites.push_back(spr);
            added.clear();

            for (SpritePtr spr : removed)
            {
                for (size_t pos = 0; pos < sprites.size(); pos++)
                {
                    if (spr == sprites[pos])
                    {
                        sprites.erase(sprites.begin() + pos);
                        break;
                    }
                }
            }
            removed.clear();

            // 3. Handle COLLISIONS
            for (SpritePtr sp1 : sprites)
            {
                for (SpritePtr sp2 : sprites)
                {
                    if (sp1 != sp2 && sp1->collidedWith(sp2))
                    {
                        sp1->onCollisionWith(sp2);
                        sp2->onCollisionWith(sp1);
                    }
                }
            }

            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); 
            SDL_RenderClear(ren);
            for (SpritePtr spr : sprites)
                spr->draw(); 
            SDL_RenderPresent(ren);

            Sint64 delay = nextTick - SDL_GetTicks();
            if (delay > 0)
                SDL_Delay(delay);
        }
    }
    Engine eng;
}