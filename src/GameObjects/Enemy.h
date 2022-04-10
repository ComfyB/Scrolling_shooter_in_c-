//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _H_ENEMY_H
#define _H_ENEMY_H


#include "GameObject.h"
#include "HealthBar.h"

class Enemy : public GameObject {
private:
    HealthBar *m_healthBar;
public:
    explicit Enemy(const ObjectParamLoader &pParams) : GameObject(pParams)     ,    m_healthBar (new HealthBar(m_lives*20 ,m_position, {50,5}))
    {
    }

    void draw() override;

    void update() override;

    void clean() override;


    void nextFrame() override;

    bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    const Vector2D &getMPosition() const override;

    Vector2D getMSize() const override;

};


#endif //_H_ENEMY_H
