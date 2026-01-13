#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "MovableSprite.h"
#include "Constants.h"

namespace demo {
    class Background : public MovableSprite {
        public:
            Background(float y);
            void tick() override;
            void onResize(int newW, int newH) override;
    };
}

#endif