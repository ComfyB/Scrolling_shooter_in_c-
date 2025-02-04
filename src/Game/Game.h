//
// Created by 1024 on 05/04/2022.
//

#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include <memory>
#include "../SupportClasses/Randomizer.h"
#include "../GameObjects/Projectile.h"
#include "../InputHandler/InputHandler.h"
#include "../SupportClasses/TextureManager.h"
#include "../SupportClasses/ObjectParamLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../States/GameStateMachine.h"

class Game {
private:
    Game() = default;;

    bool m_isRunning{};
    Uint32 m_frameStart{};
    Uint32 m_timeFromLast{};
public:
    void setMDifficulty(int mDifficulty);

private:
    int m_difficulty = 0;

    std::vector<std::shared_ptr<GameObject>> m_gameObjects;
    std::shared_ptr<GameObject> m_player;
    std::shared_ptr<GameStateMachine> m_gameStateMachine;


public:
    Game(const Game &) = delete;

    Game &operator=(const Game &) = delete;

    Game(Game &&) = delete;

    Game &operator=(Game &&) = delete;

    static auto &instance() {
        static Game game;
        return game;
    }


    void init();

    void loop();

    void quit();

    void renderLoop();

    void updateLoop();

    void removeDeadObjectsFromGameObjects();

    void cleanState();

    void addGameObject(const std::shared_ptr<GameObject> &newGO);

    [[nodiscard]] const std::shared_ptr<GameObject> &getMPlayer() const;

    [[nodiscard]] const std::vector<std::shared_ptr<GameObject>> &getGameObjects() const;

    [[nodiscard]] std::shared_ptr<GameStateMachine> getMGameStateMachine() const;

    void setMPlayer(const std::shared_ptr<GameObject> &mPlayer);

    void randomEnemy(int difficulty);


    void checkIfEnemyIsKilled();
};


#endif //_GAME_H
