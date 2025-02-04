//
// Created by 1024 on 05/04/2022.
//

#ifndef _H_ENEMY_H
#define _H_ENEMY_H


#include "GameObject.h"
#include "HealthBar.h"
#include <memory>
#include <utility>

class Enemy : public GameObject {
private:
    std::shared_ptr<HealthBar> m_healthBar;

public:
    explicit Enemy(const ObjectParamLoader &pParams, std::shared_ptr<HealthBar> healthBar)  : GameObject(pParams),
                                                                                             m_healthBar(std::move(
                                                                                                     healthBar)) {
        m_identifier = "enemy";
    }

    void draw() override;

    void update() override;

    void clean() override;
    
    void nextFrame() override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    void shoot(Vector2D velocity, Vector2D offset) override;

    static Vector2D normalize(int velocityFactor, Vector2D v);

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;

    [[nodiscard]] bool isMIsDead() const override;

};


#endif //_H_ENEMY_H
