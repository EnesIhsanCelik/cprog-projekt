#pragma once
#include "Sprite.h"
#include <string>

namespace demo {
    class MovableSprite : public Sprite {
    public:
        virtual ~MovableSprite();
        void draw() const override;
        void move(float dx, float dy) { rect.x += dx; rect.y += dy; }
        bool collidedWith(SpritePtr other) const;
        SDL_Texture* getTexture() const { return image; }

    protected:
        MovableSprite(const std::string& path, float x, float y);
        SDL_Texture* image;
    };
    
    typedef std::shared_ptr<MovableSprite> MovableSpritePtr;
}