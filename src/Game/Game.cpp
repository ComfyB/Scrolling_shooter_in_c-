//
// Created by Christoffer Lehre on 05/04/2022.
//


#include <functional>
#include <memory>
#include "Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "../States/MenuState.h"


#define DELAY_TIME 60   //about 60fps

void Game::init() {
    TextureManager::instance().init();

    SoundLoader::instance().init();

    m_gameStateMachine = std::make_shared<GameStateMachine>();
    m_gameStateMachine->pushState(std::shared_ptr<GameState>(std::make_shared<MenuState>("Menu")));

    m_isRunning = true;
    Game::loop();
}

void Game::randomEnemy() {
    addGameObject(std::shared_ptr<GameObject>(new Enemy(
            {{Randomizer::generateRandomNumber(0, WINDOWWIDTH), Randomizer::generateRandomNumber(0, 50)}, {64, 64},
             {3, 1}, "enemy", 3, 4})));
}


void Game::loop() {

    while (m_isRunning) {
        m_frameStart = SDL_GetTicks();

        SDL_RenderClear(TextureManager::instance().getRenderer());
        m_gameStateMachine->getMGameState().back()->update();
        renderLoop();

        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::instance().getRenderer());

        m_frameTime = SDL_GetTicks() - m_frameStart;
        if (m_frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - m_frameTime));
        }

    }

}

void Game::renderLoop() {
    std::for_each(m_gameObjects.begin(), m_gameObjects.end(), [](std::shared_ptr <GameObject> &ob) { ob->update(); });
    std::for_each(m_gameObjects.begin(), m_gameObjects.end(), [](std::shared_ptr <GameObject> &ob) { ob->draw(); });
    m_gameObjects.erase(std::remove_if(m_gameObjects.begin(), m_gameObjects.end(),
                                       [](auto const &ob) {
                                           if (ob->isMIsDead() && ob != Instance().m_player)
                                               return true;
                                       }), m_gameObjects.end());
}

void Game::quit() {
    m_isRunning = false;
    SoundLoader::instance().clean();
    Mix_Quit();
    SDL_Quit();
}


void Game::addGameObject(const std::shared_ptr <GameObject> &pGO) {
    m_gameObjects.emplace_back(pGO);
}

const std::vector <std::shared_ptr<GameObject>> &Game::getGameObjects() const {
    return m_gameObjects;
}

std::shared_ptr <GameStateMachine> Game::getMGameStateMachine() const {
    return m_gameStateMachine;
}

void Game::cleanState() {
    TextureManager::instance().cleanTextures();
    for (const auto &obj: m_gameObjects) {
        obj->clean();
    }
    m_gameObjects.clear();
}

