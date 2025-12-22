#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Engine.h"

namespace game {
    class CountHits : public Label, public Sprite {
        
        public:
        void funk(LaberPtr label, SpritePtr e);

        private:
        LaberPtr label;
        
    };

}