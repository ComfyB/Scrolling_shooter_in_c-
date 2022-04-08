//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_BULLET_H
#define CPP_EKSAMEN3_BULLET_H


#include "GameObject.h"

class Bullet : public GameObject{
public:
    explicit Bullet(const ObjectParamLoader &paramLoader): GameObject(paramLoader){
    };
    void draw() override;
    void update() override;
    void clean() override;

};


#endif //CPP_EKSAMEN3_BULLET_H
