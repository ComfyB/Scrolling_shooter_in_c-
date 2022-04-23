//
// Created by Christoffer Lehre on 03/04/2022.
//

#ifndef CPP_EKSAMEN2_TEXTUREMANAGER_H
#define CPP_EKSAMEN2_TEXTUREMANAGER_H


#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"


#include "Vector2D.h"

#define WINDOWHEIGHT 600
#define WINDOWWIDTH 800

class TextureManager {
private:
    TextureManager() = default;

    std::map<std::string, std::shared_ptr<SDL_Texture >> m_textureMap;
    std::shared_ptr<SDL_Window> m_window;
    std::shared_ptr<SDL_Renderer> m_renderer;
    /*
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>m_window{nullptr,SDL_DestroyWindow};
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer{nullptr, SDL_DestroyRenderer};
*/
    std::shared_ptr<TTF_Font> m_ttfFont;


public:

    TextureManager(const TextureManager &) = delete;

    TextureManager &operator=(const TextureManager &) = delete;

    TextureManager(TextureManager &&) = delete;

    TextureManager &operator=(TextureManager &&) = delete;

    static auto &instance() {
        static TextureManager textureManager;
        return textureManager;
    }

    bool init();

    bool load(const std::string &path, const std::string &id);

    void drawFrame(const std::string &id, Vector2D pos, Vector2D size, int currentFrame, int currentRow,
                   SDL_Renderer *pRenderer,
                   SDL_RendererFlip sdlFlip, double angle);

    void draw(const std::string &id, Vector2D pos, Vector2D size, SDL_Renderer *pRenderer, SDL_RendererFlip sdlFlip,
              double angle);


    void clean();

    SDL_Renderer *getRenderer() {
        return m_renderer.get();
    }

    SDL_Window *getWindow() {
        return m_window.get();
    }

    void renderText(const char *text,Vector2D pos, Vector2D size);

    void drawBar(Vector2D pos, Vector2D size);

    void cleanTextures();

    void cleanAt(const std::string& key);
};


#endif //CPP_EKSAMEN2_TEXTUREMANAGER_H
