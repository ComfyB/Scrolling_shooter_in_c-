//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _H_ENEMY_H
#define _H_ENEMY_H


#include "GameObject.h"
#include "HealthBar.h"
#include <memory>

class Enemy : public GameObject {
private:
    std::shared_ptr<HealthBar> m_healthBar;
public:
    explicit Enemy(const ObjectParamLoader &pParams) : GameObject(pParams), m_healthBar (std::shared_ptr<HealthBar>(new HealthBar(m_lives, m_position, {50, 5}))){
    }

    void draw() override;

    void update() override;

    void clean() override;


    void nextFrame() override;

    [[nodiscard]] bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;

};


#endif //_H_ENEMY_H
