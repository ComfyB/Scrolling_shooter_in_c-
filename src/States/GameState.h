//
// Created by Christoffer Lehre on 13/04/2022.
//

#ifndef CPP_EKSAMEN3_GAMESTATE_H
#define CPP_EKSAMEN3_GAMESTATE_H


#include <string>

class GameState {

public:
    virtual void update() = 0;
    virtual void render() = 0;
    virtual bool onEnter() = 0;
    virtual bool  onExit() = 0;
    [[nodiscard]] virtual std::string getStateID() const = 0;
    virtual ~GameState(){};

};


#endif //CPP_EKSAMEN3_GAMESTATE_H
