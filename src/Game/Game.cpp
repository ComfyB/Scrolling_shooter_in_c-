//
// Created by Christoffer Lehre on 05/04/2022.
//


#include <functional>
#include "Game.h"
#include "../SupportClasses/SoundLoader.h"

#define DELAY_TIME 16   //about 60fps

void Game::init() {
    TextureManager::Instance().init();
    TextureManager::Instance().load("../img/ship3.png", "ship");
    TextureManager::Instance().load("../img/UFO.png", "enemy");
    TextureManager::Instance().load("../img/bullet.png", "bullet");

    SoundLoader::instance().init();
    SoundLoader::instance().loadSound("../sound/shoot.wav", "shoot");


    m_player = std::shared_ptr<GameObject>(new Player({{10, 300}, {50, 64}, {1, 1}, "ship", 5, 4}, new HealthBar{80, {0, 0}, {80, 15}}));

    addGameObject(m_player);
    randomEnemy();
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

        SDL_RenderClear(TextureManager::Instance().getRenderer());
        InputHandler::Instance().update();
        std::for_each(m_gameObjects.begin(), m_gameObjects.end(), [](std::shared_ptr<GameObject> &ob) { ob->update(); });
        std::for_each(m_gameObjects.begin(), m_gameObjects.end(), [](std::shared_ptr<GameObject> &ob) { ob->draw(); });
        m_gameObjects.erase(std::remove_if(m_gameObjects.begin(), m_gameObjects.end(),
                                           [](auto const &ob) {
                           if(ob->isMIsDead() && ob != Game::Instance().m_player) return true ;else return false;}), m_gameObjects.end());
        m_frameTime = SDL_GetTicks() - m_frameStart;
        if (m_frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - m_frameTime));
        }
        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::Instance().getRenderer());

    }

}

void Game::quit() {
    m_isRunning = false;
    SDL_Quit();
}

std::shared_ptr<GameObject> Game::getPlayer() const {
    return m_player;
}

void Game::addGameObject(const std::shared_ptr<GameObject> &pGO) {
    m_gameObjects.emplace_back(pGO);
}

const std::vector<std::shared_ptr<GameObject>> &Game::getGameObjects() const {
    return m_gameObjects;
}

Uint32 Game::getFrameTime() const {
    return m_frameTime;
}

