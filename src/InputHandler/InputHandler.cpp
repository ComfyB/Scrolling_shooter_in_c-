//
// Created by 1024 on 05/04/2022.
//

#include "InputHandler.h"
#include "../Game/Game.h"

void InputHandler::init() {

}

InputHandler::keys InputHandler::update() {
    keyStates = SDL_GetKeyboardState(nullptr);

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            Game::instance().quit();
        else {
            if (keyStates[SDL_SCANCODE_W] || keyStates[SDL_SCANCODE_UP]) {
                return UP;
            }
            if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_LEFT]) {
                return LEFT;
            }
            if (keyStates[SDL_SCANCODE_S] || keyStates[SDL_SCANCODE_DOWN]) {
                return DOWN;
            }
            if (keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_RIGHT]) {
                return RIGHT;
            }
            if (keyStates[SDL_SCANCODE_RETURN]) {
                return ENTER;
            }
            if (keyStates[SDL_SCANCODE_SPACE]) {
                return SPACE;
            }
            if (keyStates[SDL_SCANCODE_ESCAPE] | keyStates[SDL_SCANCODE_Q]) {
                return QUIT;
            }
            if (keyStates[SDL_SCANCODE_T]) {
                return RANDOMENEMY;
            }
        }
    }
    return NOTHING;
}

void InputHandler::clean() {

}
