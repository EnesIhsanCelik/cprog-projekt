#include <SDL3/SDL.h>

class Sprite
{
public:
    SDL_FRect rect;
    SDL_Texture* texture;   
    
    Sprite(SDL_Texture* texture, float x, float y, float w, float h);
    virtual ~Sprite();

    void draw(SDL_Renderer* renderer);
    virtual void update(float dt) = 0;
    
    void move(float dx, float dy) { rect.x += dx; rect.y += dy; }
    SDL_FPoint velocity {0.0f, 0.0f}; // Automatisk rörelse för bullets och fiender

    bool intersects(const Sprite& other) const;
    virtual void onCollision(Sprite* other) {};
    void destroy() { alive = false; }
    bool isAlive() const { return alive; }

    const SDL_FRect& getRect() const { return rect; }

private:
    bool alive = true;
};