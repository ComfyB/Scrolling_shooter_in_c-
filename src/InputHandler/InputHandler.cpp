//
// Created by Christoffer Lehre on 05/04/2022.
//

#include "InputHandler.h"
#include "../Game/Game.h"

void InputHandler::init() {

}

void InputHandler::update() {
    keystates = SDL_GetKeyboardState(nullptr);

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            Game::Instance().quit();
        else {
            if (keystates[SDL_SCANCODE_W] | keystates[SDL_SCANCODE_UP]) {
                Game::Instance().getPlayer()->setMVelocity({0, -2});
            }
            if (keystates[SDL_SCANCODE_A] | keystates[SDL_SCANCODE_LEFT]) {
                Game::Instance().getPlayer()->setMVelocity({-2, 0});

            }
            if (keystates[SDL_SCANCODE_S] | keystates[SDL_SCANCODE_DOWN]) {
                Game::Instance().getPlayer()->setMVelocity({0, 2});

            }
            if (keystates[SDL_SCANCODE_D] | keystates[SDL_SCANCODE_RIGHT]) {
                Game::Instance().getPlayer()->setMVelocity({2, 0});

            }
            if (keystates[SDL_SCANCODE_SPACE]) {
             //   Game::Instance().getPlayer()->shoot(Game::Instance().getPlayer()->getMPosition()+Vector2D{32,-90});

                Game::Instance().getPlayer()->shoot();

            }
            if (keystates[SDL_SCANCODE_ESCAPE] | keystates[SDL_SCANCODE_Q]) {
                Game::Instance().quit();
            }
            if (keystates[SDL_SCANCODE_T]) {
                Game::Instance().randomEnemy();
            }

        }
    }
}

void InputHandler::clean() {

}
