//
// Created by Christoffer Lehre on 09/04/2022.
//

#include <iostream>
#include "SoundLoader.h"

void SoundLoader::init() {
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    std::cout << "sound init" << std::endl;
}

void SoundLoader::loadSound(const char *path, const char *id) {
    soundMap[id] = Mix_LoadMUS(path);
}

void SoundLoader::playSound(const char *id, int repeat) {
    Mix_PlayMusic(soundMap[id], repeat);
}

void SoundLoader::clean(){
    for (const auto& so: soundMap){
        Mix_FreeMusic(so.second);
    }
    soundMap.clear();

}

