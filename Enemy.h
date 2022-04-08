//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_ENEMY_H
#define CPP_EKSAMEN3_ENEMY_H


#include "GameObject.h"

class Enemy : public GameObject {
public:
    explicit Enemy(const ObjectParamLoader &pParams) : GameObject(pParams) {}

    void draw() override;

    void update() override;

    void clean() override;

    void shoot() override;

};


#endif //CPP_EKSAMEN3_ENEMY_H
