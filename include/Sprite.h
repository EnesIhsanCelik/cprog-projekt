#pragma once
#include <SDL3/SDL.h>
#include <memory>

class Sprite
{
public:
    using Ptr = std::shared_ptr<Sprite>;  
    
    Sprite(SDL_Texture* texture, float x, float y, float w, float h);
    virtual ~Sprite();

    void draw(SDL_Renderer* renderer) const;
    virtual void update(float dt) = 0;
    
    void move(float dx, float dy) { rect.x += dx; rect.y += dy; }

    bool intersects(const Sprite& other) const;
    virtual void onCollision(Sprite* other) {};
    
    void destroy() { alive = false; }
    bool isAlive() const { return alive; }

    const SDL_FRect& getRect() const { return rect; }

protected:
    SDL_FRect rect;
    SDL_Texture* texture; 
    bool alive = true;
};