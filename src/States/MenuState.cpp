//
// Created by Christoffer Lehre on 10/04/2022.
//

#include <iostream>
#include "MenuState.h"

void MenuState::update() {

}

void MenuState::render() {

}

bool MenuState::onEnter() {
    std::cout << "enter MenuState" << std::endl;
    return true;
}



bool MenuState::onExit() {
    std::cout << "exit MenuState" << std::endl;
    return true;

}
