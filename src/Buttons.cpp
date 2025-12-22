#include "Button.h"
#include "GUIEngine.h"

namespace demo {
    ButtonPtr Button::make(float x,float y,float w,float h,std::string txt,Action doWhat){
        return ButtonPtr(new Button(x,y,w,h,txt,doWhat));
    }
    Button::Button(float x,float y,float w,float h,std::string txt,Action doWhat):Label(x,y,w,h,txt),doIt(doWhat){}
    
    void Button::draw() const{
        Label::draw();
    }    
    
        
    void Button::onKeyUp(const SDL_Event& event){
         
    }

    void Button::onKeyLeft(const SDL_Event& event){
        
    }

    void Button::onKeyRight(const SDL_Event& event){
        
    }
}