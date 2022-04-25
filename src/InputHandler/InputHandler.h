//
// Created by 1024 on 05/04/2022.
//

#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

#include "SDL.h"

class InputHandler {
private:
    InputHandler() = default;

    const Uint8 *keyStates;
    SDL_Event event;


public:
    enum keys {
        UP = 10200,
        DOWN = 10201,
        LEFT = 10203,
        RIGHT = 10204,
        NEWGAME = 10205,
        QUIT = 10206,
        SPACE = 10207,
        RANDOMENEMY = 10208,
        ENTER = 10210,
        MUTED = 10211,
        NOTHING = 10209//ID's/ numbers to make the enum work
    };

    InputHandler(const InputHandler &) = delete;

    InputHandler &operator=(const InputHandler &) = delete;

    InputHandler(InputHandler &&) = delete;

    InputHandler &operator=(InputHandler &&) = delete;

    static auto &Instance() {
        static InputHandler inputHandler;
        return inputHandler;
    }

    void init();

    keys update();

    void clean();


};


#endif //_INPUTHANDLER_H
