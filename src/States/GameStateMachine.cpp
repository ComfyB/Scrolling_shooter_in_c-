//
// Created by Christoffer Lehre on 14/04/2022.
//

#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState *pState) {
    m_gameState.push_back(pState);
    m_gameState.back()->onEnter();
}

void GameStateMachine::changeState(GameState *pState) {
    if (!m_gameState.empty()) {
        if (m_gameState.back()->getStateID() == pState->getStateID()) {
            return;
        }
        if (m_gameState.back()->onExit()) {
            delete m_gameState.back();
            m_gameState.pop_back();
        }
    }
    m_gameState.push_back(pState);
    m_gameState.back()->onEnter();
}


void GameStateMachine::popState(GameState *pState) {
    if (!m_gameState.empty()) {
        if (m_gameState.back()->onExit()) {
            delete m_gameState.back();
            m_gameState.pop_back();
        }
    }
}

const std::vector<GameState *> &GameStateMachine::getMGameState() const {
    return m_gameState;
}
