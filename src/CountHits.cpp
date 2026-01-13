#include <string>
#include "CountHits.h"
using namespace std;

namespace game {

    int CountHits::score = 0;
    demo::LabelPtr CountHits::scoreLabel = nullptr;

    void CountHits::funk() {
        score++;
        if (scoreLabel) {
            scoreLabel->setText("Score: " + to_string(score));
        }
    }

    void CountHits::reset() {
        score = 0;
        if (scoreLabel) {
            scoreLabel->setText("Score: 0");
        }
    }   
}