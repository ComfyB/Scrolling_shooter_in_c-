//
// Created by 1024 on 14/04/2022.
// GamestateMachine Manages and holds states- making sure that the states are handled.

#include "GameStateMachine.h"

void GameStateMachine::pushState(const std::shared_ptr<GameState> &pState) {
    m_gameState.push_back(pState);
    m_gameState.back()->onEnter();
}

void GameStateMachine::changeState(const std::shared_ptr<GameState> &pState) {
    if (!m_gameState.empty()) {
        if (m_gameState.back()->getStateID() == pState->getStateID()) {
            return;
        }
        if (m_gameState.back()->onExit()) {
            m_gameState.pop_back();
        }
    }
    m_gameState.push_back(pState);
    m_gameState.back()->onEnter();
}


void GameStateMachine::popState(const std::shared_ptr<GameState> &pState) {
    if (!m_gameState.empty()) {
        if (m_gameState.back()->onExit()) {
            m_gameState.pop_back();
        }
    }
}

const std::vector<std::shared_ptr<GameState>> &GameStateMachine::getMGameState() const {
    return m_gameState;
}
