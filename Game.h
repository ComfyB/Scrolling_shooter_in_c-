//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_GAME_H
#define CPP_EKSAMEN3_GAME_H


#include <vector>
#include "GameObject.h"
#include "Player.h"

class Game {

private:
    Game() = default;

    std::vector<GameObject *> gameObjects;
    bool m_isRunning;
    Uint32 frameStart;
    Uint32 frameTime;
    Player *player;
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

    [[nodiscard]] Player *getPlayer() const;

    void addGameObject(GameObject *newGO);

   static bool checkCollision(GameObject *one, GameObject *two);

};


#endif //CPP_EKSAMEN3_GAME_H
