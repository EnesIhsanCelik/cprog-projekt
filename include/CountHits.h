//#include <SDL3/SDL.h>
//#include <SDL3_ttf/SDL_ttf.h>
#include "Engine.h"
#include "Sprite.h"
#include "Label.h"

using namespace demo;
namespace game {
    class CountHits {
        
        public:
        static void setLabel(demo::LabelPtr label) { scoreLabel = label; }
        static void funk();
        static void reset();

        private:
        static int score;
        static demo::LabelPtr scoreLabel;
    }; 
}