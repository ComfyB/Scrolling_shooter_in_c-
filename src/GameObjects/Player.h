//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>
#include <utility>
#include "GameObject.h"
#include "HealthBar.h"

class Player : public GameObject {
private:
    std::shared_ptr<HealthBar> m_healthBar;
public:
    explicit Player(const ObjectParamLoader &pParams, std::shared_ptr<HealthBar>  healthBar) : GameObject(pParams), m_healthBar(std::move(healthBar)){
    }


    void draw() override ;

    void update() override ;

    void clean() override ;

    void shoot() override;

    void nextFrame() override;

    bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;


};


#endif //_PLAYER_H
