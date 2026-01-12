#pragma once
#include "GameObjects.h"
#include <string>
#include <memory>

namespace demo {
    class Label;
    typedef std::shared_ptr<Label> LabelPtr;

    class Label : public Sprite {
    public:
        static LabelPtr make(float x, float y, float w, float h, std::string txt);
        ~Label() {}
        
        void draw() const;
        void tick() {}
        void setText(std::string newText);
        std::string getText() const { return text; }
        void onResize(int newWidth, int newHeight) override;

    protected:
        Label(float x, float y, float w, float h, std::string txt);

    private:
        std::string text;
        SDL_Texture* texture; 
    };
}