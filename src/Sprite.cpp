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

    Sprite::Sprite(std::string path, float x, float y) {
        image = IMG_LoadTexture(eng.getRen(), path.c_str());
        
        if (!image) {
            std::cerr << "Failed to load texture at: " << path << std::endl;
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