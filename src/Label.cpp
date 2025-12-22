#pragma once
#include "Label.h"
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Engine.h"
#include "Sprite.h"

namespace demo {
    LabelPtr Label::make(float x, float y, float w, float h, std::string txt) {
        return LabelPtr(new Label(x, y, w, h, txt));
    }
    
    Label::Label(float x, float y, float w, float h, std::string txt): GameObjects(x, y, w, h), text(txt) {
        texture = nullptr;
        setText(text);
    }
    
    void Label::draw() const {
        SDL_RenderTexture(eng.getRen(), texture, NULL, &getRect());
    }
    
    void Label::setText(std::string newText) {
        text = newText;
        SDL_DestroyTexture(texture);
        SDL_Surface* surf = TTF_RenderText_Solid(eng.getFont(), text.c_str(), 0, {0, 0, 0});
        texture = SDL_CreateTextureFromSurface(eng.getRen(), surf);
        SDL_DestroySurface(surf);
    }
    
    Label::~Label(){
        SDL_DestroyTexture(texture);
    }
}
