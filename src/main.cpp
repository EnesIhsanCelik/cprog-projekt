#include "Engine.h"
#include "Sprite.h"
#include "Rocketship.h"
#include "Background.h"
#include "FallingEnemy.h"
#include "Bullet.h"
#include "Label.h"
#include "CountHits.h"

using namespace std;
using namespace demo;

void setupGame()
{
    // Create and add scrolling backgrounds
    auto bg1 = std::make_shared<demo::Background>(0);
    auto bg2 = std::make_shared<demo::Background>(-constants::gScreenHeight);
    demo::eng.add(bg1);
    demo::eng.add(bg2);

    // Create and add player
    auto player = std::make_shared<Rocketship>();
    demo::eng.add(player);

    // Create and add initial enemies
    auto e1 = std::make_shared<FallingEnemy>(constants::alien_str, 100, -40, 2.0f);
    auto e2 = std::make_shared<FallingEnemy>(constants::alien2_str, 300, -200, 1.5f);
    demo::eng.add(e1);
    demo::eng.add(e2);

    // Create and add score label

    auto scoreLabel = demo::Label::make(500, 20, 120, 30, "Score: 0");
    demo::eng.add(scoreLabel);

    game::CountHits::setLabel(scoreLabel);
}

int main(int argc, char *argv[])
{
    setupGame();
    demo::eng.run();

    return 0;
}