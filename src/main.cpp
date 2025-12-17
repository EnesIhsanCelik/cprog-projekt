#include "Engine.h"
#include "Sprite.h"

class Background : public demo::Sprite {
public:
    Background() : Sprite("background-alternativ-2.png", 0, 0) {}
    void tick() override {} 
};

int main(int argc, char* argv[]) {
    demo::SpritePtr bg = std::make_shared<Background>();
    demo::eng.add(bg);
    demo::eng.run();
    
    return 0;
}