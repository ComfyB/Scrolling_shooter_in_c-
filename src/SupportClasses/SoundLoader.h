//
// Created by 1024 on 09/04/2022.
//

#ifndef CPP_EKSAMEN3_SOUNDLOADER_H
#define CPP_EKSAMEN3_SOUNDLOADER_H

#include <string>
#include <map>
#include <memory>
#include "SDL_mixer.h"

class SoundLoader {
private:
    SoundLoader() = default;

    std::map<std::string, std::shared_ptr<Mix_Music>> m_soundMap;

public:

    SoundLoader(const SoundLoader &) = delete;

    SoundLoader &operator=(const SoundLoader &) = delete;

    SoundLoader(SoundLoader &&) = delete;

    SoundLoader &operator=(SoundLoader &&) = delete;

    static auto &instance() {
        static SoundLoader SoundLoader;
        return SoundLoader;
    }

    void init();

    void loadSound(const char *path, const char *id);

    void playSound(const char *id, int repeat);

    void clean();
};


#endif //CPP_EKSAMEN3_SOUNDLOADER_H
