//
// Created by Christoffer Lehre on 03/04/2022.
//

#ifndef CPP_EKSAMEN2_TEXTUREMANAGER_H
#define CPP_EKSAMEN2_TEXTUREMANAGER_H


#include <iostream>
#include <string>
#include <map>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"


#include "Vector2D.h"

#define WINDOWHEIGHT 600
#define WINDOWWIDTH 800

class TextureManager {
private:
    TextureManager()=default;
    std::map<std::string, SDL_Texture *> m_textureMap;
    SDL_Window *m_window{};
    SDL_Renderer *m_renderer{};
    TTF_Font *m_ttfFont = nullptr;
    SDL_Color m_yellow = {241, 250, 140};

public:

    TextureManager(const TextureManager&) = delete;
    TextureManager & operator = (const TextureManager&) = delete;
    TextureManager(TextureManager&&) = delete;
    TextureManager & operator = (TextureManager &&) = delete;

    static auto& Instance(){
        static TextureManager textureManager;
        return textureManager;
    }

    bool init();

    bool load(const char *path, const char *id);

    void drawFrame(const std::string &id, Vector2D pos, Vector2D size, int currentFrame, int currentRow,
                   SDL_Renderer *pRenderer,
                   SDL_RendererFlip sdlFlip, double angle);

    void draw(const std::string &id, Vector2D pos, Vector2D size, SDL_Renderer *pRenderer, SDL_RendererFlip sdlFlip,
              double angle);


    void clean();

    SDL_Renderer* getRenderer(){
        return m_renderer;
    }


    void renderText(const char *text,  Vector2D pos, Vector2D size);

    void drawBar(Vector2D pos, Vector2D size);
};


#endif //CPP_EKSAMEN2_TEXTUREMANAGER_H
