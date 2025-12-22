#pragma once
#include <memory>
#include <SDL3/SDL.h>

namespace demo {
    class GameObjects{
        
        public:
        virtual ~GameObjects(){}
        virtual void draw() const{} = 0;
        const SDL_FRect& getRect() const { return rect; }
        virtual void onKeyUp(const SDL_Event& event){}
        //virtual void onKeyDown(const SDL_Event& event){}
        virtual void onKeyLeft(const SDL_Event& event){}
        virtual void onKeyRight(const SDL_Event& event){}
        
        GameObjects(const GameObjects& other) = delete;
        const GameObjects& operator=(const GameObjects& other) = delete;
        
        protected:
        GameObjects(float x,float y,float w,float h);
        
        private:
        SDL_FRect rect;
    };
    typedef std::shared_ptr<GameObjects> GamePtr;
}

