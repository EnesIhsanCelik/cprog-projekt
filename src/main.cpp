#include "Engine.h"
#include "Sprite.h"
#include "Rocketship.h"
#include "FallingEnemy.h"
#include "Label.h"
#include "CountHits.h"
#include "Bullet.h"
#include "Background.h"



using namespace demo;

void setupGame()
{
    // Skapa och lägg till bakgrunden
    auto bg1 = std::make_shared<demo::Background>(0);
    auto bg2 = std::make_shared<demo::Background>(-constants::gScreenHeight);
    demo::eng.add(bg1);
    demo::eng.add(bg2);

    // Skapa och lägg till spelaren
    auto player = std::make_shared<Rocketship>();
    demo::eng.add(player);

    // Skapa och lägg till fiender
    auto e1 = std::make_shared<FallingEnemy>(constants::alien_str, 100, -40, 2.0f);
    auto e2 = std::make_shared<FallingEnemy>(constants::alien2_str, 300, -200, 1.5f);

    // Lägg till fienderna i spelet
    demo::eng.add(e1);
    demo::eng.add(e2);

    // Skapa och lägg till poängetiketten
    auto scoreLabel = demo::Label::make(500, 20, 120, 30, "Score: 0");
    demo::eng.add(scoreLabel);
    
    // Skapa och lägg till CountHits för att hålla koll på poäng
    game::CountHits::setLabel(scoreLabel);
}

int main(int argc, char* argv[]) {
    setupGame();
    demo::eng.run();

    return 0;
}