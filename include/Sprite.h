#pragma once
#include <memory>
#include <string>
#include <SDL3/SDL.h>

namespace demo {
    class Sprite;
    typedef std::shared_ptr<Sprite> SpritePtr;

    // Inheriting from enable_shared_from_this allows shared_from_this()
    class Sprite : public std::enable_shared_from_this<Sprite> {
    public:
        virtual ~Sprite();
        void draw() const; 
        const SDL_FRect& getRect() const { return rect; }
        
        virtual void onMouseDown(const SDL_Event& event) {}
        virtual void tick() = 0; 
        void move(float dx, float dy) { rect.x += dx; rect.y += dy; }
        bool collidedWith(SpritePtr other) const;
        virtual void onCollisionWith(SpritePtr other) {}

        Sprite(const Sprite& other) = delete;
        const Sprite& operator=(const Sprite& other) = delete;

    protected:
        Sprite() = default; 
        Sprite(std::string name, float x, float y);

    private:
        SDL_FRect rect;
        SDL_Texture* image; 
    };
}