//
// Created by 1024 on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_GAMESTATEMACHINE_H
#define CPP_EKSAMEN3_GAMESTATEMACHINE_H


#include <vector>
#include <memory>
#include "GameState.h"

class GameStateMachine {

public:
    void changeState(const std::shared_ptr<GameState> &pState);

    void pushState(const std::shared_ptr<GameState> &pState);

    void popState(const std::shared_ptr<GameState> &pState);

    [[nodiscard]] const std::vector<std::shared_ptr<GameState>> &getMGameState() const;


private:
    std::vector<std::shared_ptr<GameState>> m_gameState;
};


#endif //CPP_EKSAMEN3_GAMESTATEMACHINE_H
