#include "Sprite.h"
#include "Engine.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

namespace demo
{
    Sprite::~Sprite()
    {
        if (image)
        {
            SDL_DestroyTexture(image);
        }
    }

    Sprite::Sprite(std::string path, float x, float y)
        : GameObjects(x, y, 0, 0)
    {
        if (path.empty())
        {
            image = nullptr;
        }

        else
        {
            image = IMG_LoadTexture(eng.getRen(), path.c_str());
            if (!image)
            {
                std::cerr << "Failed to load texture at: " << path << std::endl;
                exit(EXIT_FAILURE);
            }

            rect.w = static_cast<float>(image->w);
            rect.h = static_cast<float>(image->h);
        }

        rect.x = x;
        rect.y = y;
    }

    bool Sprite::collidedWith(SpritePtr other) const
    {
        return SDL_HasRectIntersectionFloat(&rect, &other->rect);
    }

    void Sprite::draw() const
    {
        SDL_RenderTexture(eng.getRen(), image, NULL, &rect);
    }
}