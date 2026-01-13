#include "MovableSprite.h"
#include "Engine.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

namespace demo
{
    MovableSprite::MovableSprite(const std::string &path, float x, float y)
        : Sprite(x, y, 0, 0), image(nullptr)
    {
        if (!path.empty())
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
    }

    MovableSprite::~MovableSprite()
    {
        if (image)
        {
            SDL_DestroyTexture(image);
        }
    }

    bool MovableSprite::collidedWith(SpritePtr other) const
    {
        return SDL_HasRectIntersectionFloat(&rect, &other->getRect());
    }

    void MovableSprite::draw() const
    {
        SDL_RenderTexture(eng.getRen(), image, NULL, &rect);
    }
}