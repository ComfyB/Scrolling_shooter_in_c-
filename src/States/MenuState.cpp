//
// Created by Christoffer Lehre on 10/04/2022.
//

#include <iostream>
#include "MenuState.h"
#include "../Game/Game.h"
#include "../GameObjects/TextObject.h"
#include "../GameObjects/UI_Element.h"

void MenuState::update() {

}

void MenuState::render() {

}

bool MenuState::onEnter() {
    TextureManager::instance().load("../img/arrow_animated.png","arrow_anim");
    Game::Instance().addGameObject(std::shared_ptr<GameObject>(new TextObject({{90, 50}, {250, 100}, {0, 0}, "NULL", 1, 1}, "Menu")));
    Game::Instance().addGameObject(std::shared_ptr<GameObject>(new TextObject({{90, 150}, {400, 100}, {0, 0}, "NULL", 1, 1}, "New Game")));
    Game::Instance().addGameObject(std::shared_ptr<GameObject>(new TextObject({{90, 250}, {450, 100}, {0, 0}, "NULL", 1, 1}, "Highscore")));
    Game::Instance().addGameObject(std::shared_ptr<GameObject>(new UI_Element({{90,350},{64,64},{0,0},"arrow_anim",1,4})));
    std::cout << "enter MenuState" << std::endl;
    return true;
}



bool MenuState::onExit() {
    std::cout << "exit MenuState" << std::endl;
    return true;

}

std::string MenuState::getStateID() const {
    return m_menuID;
}
