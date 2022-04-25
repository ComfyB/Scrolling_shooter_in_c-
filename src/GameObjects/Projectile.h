//
// Created by 1024 on 09/04/2022.
//

#ifndef _PROJECTILE_H
#define _PROJECTILE_H


#include "GameObject.h"

class Projectile : public GameObject {
public:
    explicit Projectile(const ObjectParamLoader &pParams) : GameObject(pParams) {
        m_identifier = "projectile";
    }

    void draw() override;

    void update() override;

    void clean() override;

    void nextFrame() override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;

    [[nodiscard]] bool isMIsDead() const override;


};


#endif //_PROJECTILE_H
