//
// Created by 1024 on 14/04/2022.
//

#include <sstream>
#include "HighScoreState.h"
#include "../SupportClasses/FileReader.h"
#include "../GameObjects/TextObject.h"
#include "MenuState.h"

void HighScoreState::update() {
    switch (InputHandler::Instance().update()) {
        case InputHandler::QUIT:
            Game::instance().getMGameStateMachine()->changeState(std::make_shared<MenuState>("Menu"));
            break;
        case InputHandler::UP:
        case InputHandler::DOWN:
        case InputHandler::SPACE:
        case InputHandler::ENTER:
        case InputHandler::LEFT:
        case InputHandler::RIGHT:
        case InputHandler::NEWGAME:
        case InputHandler::NOTHING:
        case InputHandler::RANDOMENEMY:
        case InputHandler::MUTED:
            break;
    }
}

void HighScoreState::render() {

}

bool HighScoreState::onEnter() {
    m_highscores = FileReader::readLines("../csv/hs.csv");
    int counter = 1;
    int yPos = 50;
    Game::instance().addGameObject(
            std::shared_ptr<GameObject>(
                    new TextObject({{45, 10}, {200, 40}, {0, 0}, "NULL", 1, 1}, "Highscores")));

    for (const auto &s: m_highscores) {
        std::string text;
        text = std::to_string(counter) + "\t\t:\t" + s;
        if (counter == 10) text = std::to_string(counter) + "\t:\t" + s;
        Game::instance().addGameObject(
                std::shared_ptr<GameObject>(
                        new TextObject(
                                {{60, yPos * counter+1}, {static_cast<int>(text.length() * 25), 40}, {0, 0}, "NULL", 1,
                                 1}, text)));
        if (++counter > 10) break;
    }
    return true;
}

bool HighScoreState::onExit() {
    Game::instance().cleanState();
    return true;
}

std::string HighScoreState::getStateID() const {
    return m_highscoreID;
}

void HighScoreState::increaseScore() {

}
