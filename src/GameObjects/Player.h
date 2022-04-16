//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameObject.h"
#include "HealthBar.h"

class Player : public GameObject {
private:
    HealthBar* m_healthBar;
public:
    explicit Player(const ObjectParamLoader &pParams, HealthBar *healthBar) : GameObject(pParams), m_healthBar(healthBar) {}

    void draw() override ;

    void update() override ;

    void clean() override ;

    void shoot() override;

    void nextFrame() override;

    bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    const Vector2D &getMPosition() const override;

    Vector2D getMSize() const override;


};


#endif //_PLAYER_H
