//
// Created by 1024 on 10/04/2022.
//

#include <iostream>
#include "MenuState.h"
#include "../Game/Game.h"
#include "../GameObjects/TextObject.h"
#include "../GameObjects/UI_Element.h"
#include "PlayingState.h"
#include "HighScoreState.h"

void MenuState::update() {

    switch (InputHandler::Instance().update()) {

        case InputHandler::UP:

            if (currentSelection == NEWGAME) {
                selector->setMPosition({10, 360});
                currentSelection = ENDGAME;
            } else if (currentSelection == ENDGAME) {
                selector->setMPosition({10, 260});
                currentSelection = HIGHSCORE;
            } else if (currentSelection == HIGHSCORE) {
                selector->setMPosition({10, 180});
                currentSelection = NEWGAME;
            }
            break;
        case InputHandler::DOWN:
            if (currentSelection == HIGHSCORE) {
                selector->setMPosition({10, 360});
                currentSelection = ENDGAME;
            } else if (currentSelection == NEWGAME) {
                selector->setMPosition({10, 260});
                currentSelection = HIGHSCORE;
            } else if (currentSelection == ENDGAME) {
                selector->setMPosition({10, 180});
                currentSelection = NEWGAME;
            }
            break;
        case InputHandler::SPACE:
        case InputHandler::ENTER:

            if (currentSelection == NEWGAME) {
                Game::instance().getMGameStateMachine()->changeState(
                        std::shared_ptr<GameState>(new PlayingState("Playing")));
            } else if (currentSelection == ENDGAME) {
                Game::instance().quit();
            } else if (currentSelection == HIGHSCORE) {
                Game::instance().getMGameStateMachine()->changeState(
                        std::shared_ptr<GameState>(new HighScoreState("HIGHSCORE")));
            }
            break;
        case InputHandler::LEFT:
        case InputHandler::QUIT:
        case InputHandler::RIGHT:
        case InputHandler::NEWGAME:
        case InputHandler::NOTHING:
        case InputHandler::RANDOMENEMY:
            break;
    }
}

void MenuState::render() {

}

bool MenuState::onEnter() {

    TextureManager::instance().load("../img/arrow_animated.png", "arrow_anim");
    Game::instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 50}, {250, 100}, {0, 0}, "NULL", 1, 1}, "Menu")));
    Game::instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 150}, {400, 100}, {0, 0}, "NULL", 1, 1}, "New Game")));
    Game::instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 250}, {450, 100}, {0, 0}, "NULL", 1, 1}, "Highscore")));
    Game::instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 350}, {200, 100}, {0, 0}, "NULL", 1, 1}, "Exit")));
    selector = std::shared_ptr<GameObject>(new UI_Element({{10, 180}, {64, 64}, {0, 0}, "arrow_anim", 1, 4}));
    Game::instance().addGameObject(selector);
    currentSelection = NEWGAME;
    std::cout << "enter MenuState" << std::endl;
    return true;
}


bool MenuState::onExit() {
    Game::instance().cleanState();
    std::cout << "exit MenuState" << std::endl;
    return true;

}

std::string MenuState::getStateID() const {
    return m_menuID;
}


