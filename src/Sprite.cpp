#include "Sprite.h"
#include "Engine.h"
#include <SDL3_image/SDL_image.h>
#include <iostream>

namespace demo
{
    Sprite::~Sprite() {
        if (image) {
            SDL_DestroyTexture(image);
        }
    }

    Sprite::Sprite(std::string name, float x, float y)
    {
        // Build the path: ./resources/ + images/ + background.png
        std::string fullPath = constants::gResPath + "images/" + name;
        image = IMG_LoadTexture(eng.getRen(), fullPath.c_str());

        if (!image)
        {
            std::cerr << "Failed to load texture: " << SDL_GetError() << std::endl;
            exit(EXIT_FAILURE);
        }

        rect.x = x;
        rect.y = y;
        rect.w = static_cast<float>(image->w);
        rect.h = static_cast<float>(image->h);
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