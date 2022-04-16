//
// Created by Christoffer Lehre on 10/04/2022.
//

#include <iostream>
#include "MenuState.h"
#include "../Game/Game.h"
#include "../GameObjects/TextObject.h"
#include "../GameObjects/UI_Element.h"
#include "PlayingState.h"

void MenuState::update() {

    switch (InputHandler::Instance().update()) {

        case InputHandler::UP:
        case InputHandler::DOWN:
            
            if (currentSelection == NEWGAME) {
                currentSelection = HIGHSCORE;
                selector->setMPosition({10, 260});
            } else if(currentSelection == HIGHSCORE){
                selector->setMPosition({10, 180});
                currentSelection = NEWGAME;
            }
            break;
        case InputHandler::LEFT:
            break;
        case InputHandler::RIGHT:
            break;
        case InputHandler::NEWGAME:
            break;
        case InputHandler::QUIT:
            break;
        case InputHandler::SPACE:
            if (currentSelection == NEWGAME)
                Game::Instance().getMGameStateMachine()->changeState(new PlayingState("Playing"));
            break;
        case InputHandler::RANDOMENEMY:
            break;
        case InputHandler::NOTHING:
            break;
    }
}

void MenuState::render() {

}

bool MenuState::onEnter() {
    TextureManager::instance().load("../img/arrow_animated.png", "arrow_anim");
    Game::Instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 50}, {250, 100}, {0, 0}, "NULL", 1, 1}, "Menu")));
    Game::Instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 150}, {400, 100}, {0, 0}, "NULL", 1, 1}, "New Game")));
    Game::Instance().addGameObject(
            std::shared_ptr<GameObject>(new TextObject({{90, 250}, {450, 100}, {0, 0}, "NULL", 1, 1}, "Highscore")));
    selector = std::shared_ptr<GameObject>(new UI_Element({{10, 180}, {64, 64}, {0, 0}, "arrow_anim", 1, 4}));
    Game::Instance().addGameObject(selector);
    currentSelection = NEWGAME;
    
    std::cout << "enter MenuState" << std::endl;
    return true;
}


bool MenuState::onExit() {
    Game::Instance().cleanState();
    std::cout << "exit MenuState" << std::endl;
    return true;

}

std::string MenuState::getStateID() const {
    return m_menuID;
}
