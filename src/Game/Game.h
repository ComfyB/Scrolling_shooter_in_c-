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
#include "../SupportClasses/TextureManager.h"
#include "../SupportClasses/ObjectParamLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Enemy.h"
#include "../States/GameStateMachine.h"

class Game {
private:
    Game() = default;;

    bool m_isRunning;
    Uint32 m_frameStart;
    Uint32 m_timeFromLast;

    std::vector<std::shared_ptr<GameObject>> m_gameObjects;
    std::shared_ptr<GameObject> m_player;
    std::unique_ptr<TextureManager> m_textureManager;
    std::shared_ptr<GameStateMachine> m_gameStateMachine;

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

    void randomEnemy();

    void renderLoop();

    void cleanState();

    void addGameObject(const std::shared_ptr<GameObject> &newGO);

    [[nodiscard]] const std::vector<std::shared_ptr<GameObject>> &getGameObjects() const;

    [[nodiscard]] std::shared_ptr<GameStateMachine> getMGameStateMachine() const;

    const std::unique_ptr<TextureManager> &getMTextureManager() const;

};


#endif //_GAME_H
