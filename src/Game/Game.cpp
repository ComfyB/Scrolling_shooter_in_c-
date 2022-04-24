//Game management class which holds instances of the helper classes and iterate methods for gameplay and rendering.
//this class holds the gameobjects where they are needed.
//


#include <functional>
#include <memory>
#include "Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "../States/MenuState.h"


#define UPDATE_TICK_TIME 16   //about 60tick - controls how often the gameobjects should be updated. uncaps framerate.

//init important classes and variables so that the t
void Game::init() {
    TextureManager::instance().init();
    SoundLoader::instance().init();

    m_gameStateMachine = std::make_shared<GameStateMachine>();
    m_gameStateMachine->pushState(std::make_shared<MenuState>("Menu"));
    m_timeFromLast = 16;
    m_isRunning = true;
    Game::loop();
}


void Game::randomEnemy() {
    addGameObject(std::make_shared<GameObject>(Enemy(
            {{Randomizer::generateRandomNumber(0, WINDOWWIDTH), Randomizer::generateRandomNumber(0, 50)}, {64, 64},
             {3, 1}, "enemy", 3, 4}, std::make_shared<HealthBar>(30, Vector2D{0, 0}, Vector2D{20, 300}))));
}


void Game::loop() {

    while (m_isRunning) {

        SDL_RenderClear(TextureManager::instance().getRenderer());
        m_gameStateMachine->getMGameState().back()->update();
        renderLoop();
        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::instance().getRenderer());
    }

}

void Game::renderLoop() {
    m_frameStart = SDL_GetTicks64();
    if (m_frameStart >= (m_timeFromLast + UPDATE_TICK_TIME)) {
        for (const auto &ob: m_gameObjects) {
            ob->update();
        }
        m_timeFromLast = m_frameStart;
    }
    for (const auto &ob: m_gameObjects) {
        ob->draw();
    }

    m_gameObjects.erase(std::remove_if(m_gameObjects.begin(), m_gameObjects.end(),
                                       [](auto &ob) {
                                           if (ob->isMIsDead() && ob != instance().m_player)
                                               return true;
                                           return false;
                                       }), m_gameObjects.end());
}

void Game::quit() {
    m_isRunning = false;
    TextureManager::instance().clean();
    SoundLoader::instance().clean();
    Mix_Quit();
    SDL_Quit();
}


void Game::addGameObject(const std::shared_ptr<GameObject> &pGO) {
    m_gameObjects.emplace_back(pGO);
}

const std::vector<std::shared_ptr<GameObject>> &Game::getGameObjects() const {
    return m_gameObjects;
}

std::shared_ptr<GameStateMachine> Game::getMGameStateMachine() const {
    return m_gameStateMachine;
}

void Game::cleanState() {
    TextureManager::instance().cleanTextures();
    for (const auto &obj: m_gameObjects) {
        obj->clean();
    }
    m_gameObjects.clear();
}

const std::unique_ptr<TextureManager> &Game::getMTextureManager() const {
    return m_textureManager;
}

