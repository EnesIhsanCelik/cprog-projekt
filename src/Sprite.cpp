#include <SDL3/SDL.h>
#include "Sprite.h"
#include "Engine.h"

Sprite::Sprite(SDL_Texture* texture, float x, float y, float w, float h)
    : texture(texture)
{
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

/*Sprite::Sprite(std::string name, float x, float y)
{
    -----När vi har en Engine-instans som heter t.ex. engine----
    
     image = IMG_LoadTexture(engine.getRen(), 
         (cnts::gResPath + "/images/" + name).c_str());
    
     if (!image) {
         std::cerr << "Could not load image: " << name << std::endl;
         exit(EXIT_FAILURE);
     }
    
    rect = { x, y, (float)image->w, (float)image->h };
}*/


Sprite::~Sprite()
{
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::draw(SDL_Renderer* renderer) const
{
    if(!alive) return;
    SDL_RenderTexture(renderer, texture, NULL, &rect);
}


bool Sprite::intersects(const SpritePtr other) const
{
    return !(rect.x + rect.w < other->rect.x ||
             rect.x > other->rect.x + other->rect.w ||
             rect.y + rect.h < other->rect.y ||
             rect.y > other->rect.y + other->rect.h);
}

