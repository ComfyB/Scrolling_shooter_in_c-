//
// Created by 1024 on 09/04/2022.
//

#include <iostream>
#include "SoundLoader.h"

void SoundLoader::init() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    std::cout << "sound init" << std::endl;
}

void SoundLoader::loadSound(const char *path, const char *id) {
    m_soundMap[id] = std::shared_ptr<Mix_Music>(Mix_LoadMUS(path), Mix_FreeMusic);
}

void SoundLoader::playSound(const char *id, int repeat) {
    Mix_PlayMusic(m_soundMap.at(id).get(), repeat);
}

void SoundLoader::clean() {
    m_soundMap.clear();
}

[[maybe_unused]] void SoundLoader::mute() {
    Mix_VolumeMusic(0);
    SDL_Delay(10);
}

