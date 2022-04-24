//
// Created by 1024 on 14/04/2022.
//

#include "HighScoreState.h"

void HighScoreState::update() {

}

void HighScoreState::render() {

}

bool HighScoreState::onEnter() {
    // Game::instance().quit();
    return false;
}

bool HighScoreState::onExit() {
    return false;
}

std::string HighScoreState::getStateID() const {
    return m_highscoreID;
}
