#pragma once
#include "Sprite.h"
#include <string>
#include <memory>

namespace demo {
    class Label;
    using LabelPtr = std::shared_ptr<Label>;

    class Label : public Sprite {
    public:
        static LabelPtr make(float x, float y, float w, float h, std::string txt);
        ~Label();
        
        void draw() const override;
        void tick() override {}
        void setText(std::string newText);
        std::string getText() const { return text; }
        void onResize(int newW, int newH) override;

    protected:
        Label(float x, float y, float w, float h, std::string txt);

    private:
        std::string text;
        SDL_Texture* texture; 
    };
}