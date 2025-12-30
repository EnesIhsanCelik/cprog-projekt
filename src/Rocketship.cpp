#include "Rocketship.h"
#include "Constants.h"
#include "Bullet.h"
#include "Engine.h"

Rocketship::Rocketship() : Sprite(constants::rocketship_str, 0, 0)
{
    rect.w = 64.f;
    rect.h = 64.f;

    rect.x = (constants::gScreenWidth / 2.0f) - (rect.w / 2.0f);
    rect.y = constants::gScreenHeight - rect.h - 20.0f;

    if (!SDL_LoadWAV(constants::shoot_sound_str.c_str(), &shotSpec, &shotBuf, &shotLen))
    {
        SDL_Log("Failed to load shoot sound: %s", SDL_GetError());
    }

    shotStream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &shotSpec, nullptr, nullptr);

    if (shotStream)
    {
        SDL_ResumeAudioStreamDevice(shotStream);
    }
}

Rocketship::~Rocketship()
{
    if (shotStream)
        SDL_DestroyAudioStream(shotStream);
    if (shotBuf)
        SDL_free(shotBuf);
}

void Rocketship::tick()
{
    const bool *keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_LEFT] && getRect().x > 0)
        move(-4, 0);
    if (keys[SDL_SCANCODE_RIGHT] && getRect().x < (constants::gScreenWidth - getRect().w))
        move(4, 0);
}

void Rocketship::onKeyDown(const SDL_Event &event)
{
    if (event.key.scancode == SDL_SCANCODE_UP)
    {
        shoot();
    }
}

void Rocketship::shoot() 
{
    if (shotStream && shotBuf)
    {
        SDL_ClearAudioStream(shotStream);
        SDL_PutAudioStreamData(shotStream, shotBuf, shotLen);
    }
    float bulletX = rect.x + (rect.w / 2); 
    float bulletY = rect.y;

    auto bullet = std::make_shared<Bullet>(bulletX, bulletY, 10.0f);
    demo::eng.add(bullet);
}