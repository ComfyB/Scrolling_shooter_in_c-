//
// Created by Christoffer Lehre on 10/04/2022.
//

#ifndef CPP_EKSAMEN3_MENUSTATE_H
#define CPP_EKSAMEN3_MENUSTATE_H


#include <string>
#include "GameState.h"

class MenuState : public GameState{
public:

    MenuState() {}
    ~MenuState() {}
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    virtual std::string getStateID() const {return m_menuID;}

private:
    static const std::string m_menuID;
};


#endif //CPP_EKSAMEN3_MENUSTATE_H
