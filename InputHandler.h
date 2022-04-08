//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_INPUTHANDLER_H
#define CPP_EKSAMEN3_INPUTHANDLER_H

#include "SDL.h"

class InputHandler {
private:
    InputHandler(){};

    ~InputHandler(){};


    const Uint8 *keystates;



public:
    InputHandler(const InputHandler&) = delete;
    InputHandler & operator = (const InputHandler&) = delete;
    InputHandler(InputHandler&&) = delete;
    InputHandler & operator = (InputHandler &&) = delete;

    static auto& Instance(){
        static InputHandler inputHandler;
        return inputHandler;
    }
    void init();

    void update();

    void clean();




};


#endif //CPP_EKSAMEN3_INPUTHANDLER_H
