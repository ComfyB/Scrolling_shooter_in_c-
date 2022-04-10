//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include <memory>
#include "../SupportClasses/Randomizer.h"
#include "../GameObjects/Projectile.h"
#include "../InputHandler/InputHandler.h"
#include "TextureManager.h"
#include "../SupportClasses/ObjectParamLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"

class Game {
private:
    Game(){};

    bool m_isRunning;
    Uint32 m_frameStart;
    Uint32 m_frameTime;

    std::vector<std::shared_ptr<GameObject>> m_gameObjects;
    std::shared_ptr<GameObject> m_player;
public:
    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    Game(Game &&) = delete;

    Game &operator=(Game &&) = delete;

    static auto &Instance() {
        static Game game;
        return game;
    }

    void init();

    void loop();

    void quit();

    [[nodiscard]] std::shared_ptr<GameObject> getPlayer() const;

    void addGameObject(const std::shared_ptr<GameObject> &newGO);

  //  static bool checkCollision(const std::shared_ptr<GameObject> &one, const std::shared_ptr<GameObject> &two);

    [[nodiscard]] const std::vector<std::shared_ptr<GameObject>> &getGameObjects() const;

    void randomEnemy();

  //  void shoot() const;
  Uint32 getFrameTime() const;
};


#endif //_GAME_H
