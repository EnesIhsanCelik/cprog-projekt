#include "Engine.h"
#include "Sprite.h"
#include <FallingEnemy.h>

class Background : public demo::Sprite {
public:
    Background() : Sprite(constants::background_str, 0, 0) {}
    void tick() override {} 
};

int main(int argc, char* argv[]) {
    demo::SpritePtr bg = std::make_shared<Background>();
    demo::eng.add(bg);
    
    demo::SpritePtr e1 = std::make_shared<FallingEnemy>(constants::alien_str, 100, -40, 2.0f);
    demo::SpritePtr e2 = std::make_shared<FallingEnemy>(constants::alien2_str, 300, -200, 1.5f);

    demo::eng.add(e1);
    demo::eng.add(e2);
    demo::eng.run();

    return 0;
}