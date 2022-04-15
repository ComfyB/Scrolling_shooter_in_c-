//
// Created by Christoffer Lehre on 05/04/2022.
//


#include <functional>
#include "Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "../States/PlayingState.h"


#define DELAY_TIME 16   //about 60fps

void Game::init() {
    TextureManager::Instance().init();


    SoundLoader::instance().init();

    m_gameStateMachine = new GameStateMachine();
    m_gameStateMachine->changeState(new PlayingState());

    m_isRunning = true;
    Game::loop();
}

void Game::randomEnemy() {
    addGameObject(std::shared_ptr<Renderable>(new Enemy(
            {{Randomizer::generateRandomNumber(0, WINDOWWIDTH), Randomizer::generateRandomNumber(0, 50)}, {64, 64},
             {3, 1}, "enemy", 3, 4})));
}


void Game::loop() {

    while (m_isRunning) {
        m_frameStart = SDL_GetTicks();

        SDL_RenderClear(TextureManager::Instance().getRenderer());
        m_gameStateMachine->getMGameState().back()->update();
        renderLoop();
        m_frameTime = SDL_GetTicks() - m_frameStart;
        if (m_frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - m_frameTime));
        }
        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::Instance().getRenderer());

    }

}

void Game::renderLoop() {
    std::for_each(m_renderableObjects.begin(), m_renderableObjects.end(), [](std::shared_ptr<Renderable> &ob) { ob->update(); });
    std::for_each(m_renderableObjects.begin(), m_renderableObjects.end(), [](std::shared_ptr<Renderable> &ob) { ob->draw(); });
    m_renderableObjects.erase(std::remove_if(m_renderableObjects.begin(), m_renderableObjects.end(),
                                             [](auto const &ob) {
                       if(ob->isMIsDead() && ob != Instance().m_player) return true ;else return false;}), m_renderableObjects.end());
}

void Game::quit() {
    m_isRunning = false;
    SDL_Quit();
}


void Game::addGameObject(const std::shared_ptr<Renderable> &pGO) {
    m_renderableObjects.emplace_back(pGO);
}

const std::vector<std::shared_ptr<Renderable>> &Game::getGameObjects() const {
    return m_renderableObjects;
}

Uint32 Game::getFrameTime() const {
    return m_frameTime;
}

GameStateMachine *Game::getMGameStateMachine() const {
    return m_gameStateMachine;
}

