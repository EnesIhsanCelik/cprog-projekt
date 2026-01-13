#include "Label.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Engine.h"

namespace demo {
    LabelPtr Label::make(float x, float y, float w, float h, std::string txt) 
    {
        return LabelPtr(new Label(x, y, w, h, txt));
    }
    
    Label::Label(float x, float y, float w, float h, std::string txt): 
        Sprite(x, y, w, h), text(txt), texture(nullptr)
    {
        rect.w = w;
        rect.h = h;
        setText(text);
    }
    
    void Label::draw() const {
        SDL_RenderTexture(eng.getRen(), texture, NULL, &rect);
    }
    
    void Label::setText(std::string newText) {
        text = newText;
        if (texture) {
            SDL_DestroyTexture(texture);
        }
        SDL_Surface* surf = TTF_RenderText_Solid(eng.getFont(), text.c_str(), 0, {255, 0, 0});
        texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
        SDL_DestroySurface(surf);
    }
    
    Label::~Label(){
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }

    void Label::onResize(int newW, int newH)
    {
        rect.x = newW - rect.w - 20.0f;
        rect.y = 20.0f;
    }
}