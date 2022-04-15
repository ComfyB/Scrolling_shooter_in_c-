//
// Created by Christoffer Lehre on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_MENUOBJECT_H
#define CPP_EKSAMEN3_MENUOBJECT_H


#include "Renderable.h"
#include "../Game/States.h"
class MenuObject : public Renderable{

private:
    std::string text;
    States::gameState state;
};


#endif //CPP_EKSAMEN3_MENUOBJECT_H
