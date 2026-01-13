#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

namespace demo {
    class Sprite;
    typedef std::shared_ptr<Sprite> SpritePtr;

    class Sprite : public std::enable_shared_from_this<Sprite> {
    public:
        virtual ~Sprite();
        virtual void draw() const = 0; 
        const SDL_FRect& getRect() const { return rect; }
        
        virtual void onMouseDown(const SDL_Event& event) {}
        virtual void onKeyDown(const SDL_Event& event) {}
        virtual void tick() = 0; 
        virtual void onCollisionWith(SpritePtr other) {}
        virtual void onResize(int newW, int newH) {}
        
        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;

    protected:
        Sprite(float x, float y, float w, float h);
        SDL_FRect rect;
    };
}