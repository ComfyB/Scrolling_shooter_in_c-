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


void Game::randomEnemy(int difficulty) {
    addGameObject(std::shared_ptr<GameObject>(new Enemy(
            {{Randomizer::generateRandomNumber(0, WINDOWWIDTH-64), Randomizer::generateRandomNumber(0, 30)}, {64, 64},
             {difficulty+3, Randomizer::generateRandomNumber(0, difficulty*2)}, "enemy", 3, 4},
            std::make_shared<HealthBar>(Vector2D{-30, 80}, Vector2D{20, 10}))));
}


void Game::loop() {

    while (m_isRunning) {
        SDL_RenderClear(TextureManager::instance().getRenderer());
        m_gameStateMachine->getMGameState().back()->update();
        checkLivesLoop();
        updateLoop();
        renderLoop();
        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::instance().getRenderer());
    }

}

void Game::renderLoop() {
    for (const auto &ob: m_gameObjects) {
        ob->draw();
    }
}

void Game::checkLivesLoop() {
    m_gameObjects.erase(std::remove_if(m_gameObjects.begin(), m_gameObjects.end(),
                                       [](auto &ob) {
                                           if (ob->isMIsDead() && ob != instance().m_player)
                                               return true;
                                           return false;
                                       }), m_gameObjects.end());
}

void Game::updateLoop() {
    m_frameStart = SDL_GetTicks64();
    if (m_frameStart >= (m_timeFromLast + UPDATE_TICK_TIME)) {
        for (const auto &GO: m_gameObjects) {
            if(GO == nullptr) break;
            GO->update();
            if (std::dynamic_pointer_cast<Enemy>(GO) != nullptr) {
                if (GO->isMIsDead()) {
                    m_gameStateMachine->getMGameState().back()->increaseScore();
                    randomEnemy(m_difficulty);
                }

            }
        }
        m_timeFromLast = m_frameStart;
    }
}

void Game::quit() {
    m_isRunning = false;
    TextureManager::instance().clean();
    SoundLoader::instance().clean();
    Mix_Quit();
    SDL_VideoQuit();
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

const std::shared_ptr<GameObject> &Game::getMPlayer() const {
    return m_player;
}

void Game::setMPlayer(const std::shared_ptr<GameObject> &mPlayer) {
    m_player = mPlayer;
}

void Game::setMDifficulty(int mDifficulty) {
    m_difficulty = mDifficulty;
}



