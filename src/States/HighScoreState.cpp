//
// Created by Christoffer Lehre on 14/04/2022.
//

#include "HighScoreState.h"

void HighScoreState::update() {

}

void HighScoreState::render() {

}

bool HighScoreState::onEnter() {
   // Game::Instance().quit();
    return false;
}

bool HighScoreState::onExit() {
    return false;
}

std::string HighScoreState::getStateID() const {
    return m_highscoreID;
}
