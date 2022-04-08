//
// Created by Christoffer Lehre on 05/04/2022.
//

#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "ObjectParamLoader.h"
#include "InputHandler.h"
#include "Enemy.h"

#define DELAY_TIME 16   //about 60fps

void Game::init() {
    TextureManager::Instance().init();
    TextureManager::Instance().load("../img/ship3.png", "ship");
    TextureManager::Instance().load("../img/UFO.png", "enemy");
    TextureManager::Instance().load("../img/bullet.png", "bullet");

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music *explosionSound = Mix_LoadMUS("../sound/explosion.wav");
    Mix_Music *shootingSound = Mix_LoadMUS("../sound/shoot.wav");
    player = new Player({{10, 300}, {50, 64}, {1, 1}, "ship", 3, 4});
    addGameObject(player);
    addGameObject(new Enemy({{10, 10}, {64, 64}, {0, 1}, "enemy", 3, 4}));
    addGameObject(new Enemy({{100, 10}, {64, 64}, {0, 1}, "enemy", 3, 4}));
    addGameObject(new Enemy({{220, 10}, {64, 64}, {0, 1}, "enemy", 3, 4}));

    m_isRunning = true;
    Game::loop();
}

//this crashes the game//
//this crashes the game//
void Game::loop() {
    while (m_isRunning) {
        SDL_RenderClear(TextureManager::Instance().getRenderer());
        frameStart = SDL_GetTicks();
        InputHandler::Instance().update();

        auto it = gameObjects.begin();
        while (it != gameObjects.end()) {
            (*it)->update();
            (*it)->draw();

            for (auto GO: gameObjects) {
                if ((*it) != GO) {
                    if (checkCollision(*(it), GO)) {
                        std::cout << (*it) << " & "<< GO <<std::endl;
                        GO->deleteOneLife();
                    }
                }
            }
            if ((*it)->isMIsDead()) {
                it = gameObjects.erase(it);
            } else {
                ++it;
            }
        }

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
        SDL_PumpEvents();
        SDL_RenderPresent(TextureManager::Instance().getRenderer());

    }

}

void Game::quit() {
    m_isRunning = false;
    SDL_Quit();
}

Player *Game::getPlayer() const {
    return player;
}
bool Game::checkCollision(GameObject *one, GameObject *two) // AABB - AABB collision
{
    // collision x-axis?
    bool collisionX = one->getMPosition().getX() + one->getMSize().getX() >= two->getMPosition().getX() &&
                      two->getMPosition().getX() + two->getMSize().getX() >= one->getMPosition().getX();
    // collision y-axis?
    bool collisionY = one->getMPosition().getY() + one->getMSize(). getY() >= two->getMPosition().getY() &&
                      two->getMPosition().getY() + two->getMSize().getY() >= one->getMPosition().getY();
    // collision only if on both axes
    return collisionX && collisionY;
}
/*
bool Game::checkCollision(GameObject *o1, GameObject *o2) {
     if (o1->getMPosition().getX() < o2->getMPosition().getX() + o2->getMSize().getX() &&
         o1->getMPosition().getX() + o1->getMSize().getX() > o2->getMPosition().getX() &&
         o1->getMPosition().getY() < o2->getMPosition().getY() + o1->getMSize().getY() &&
         o1->getMPosition().getY() + o1->getMSize().getY() > o2->getMPosition().getY()
             ) {
         std::cout << "collision!!";
         return true;
     }
    return false;
}*/

void Game::addGameObject(GameObject *pGO) {
    gameObjects.emplace_back(pGO);
}

