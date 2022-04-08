//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_PLAYER_H
#define CPP_EKSAMEN3_PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
public:
    explicit Player(const ObjectParamLoader &pParams) : GameObject(pParams) {}

    void draw() override ;

    void update() override ;

    void clean() override ;

    void shoot() override;
};


#endif //CPP_EKSAMEN3_PLAYER_H
