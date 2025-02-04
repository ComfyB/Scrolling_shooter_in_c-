//
// Created by 1024 on 25/04/2022.
//

#ifndef CPP_EKSAMEN3_BG_H
#define CPP_EKSAMEN3_BG_H


#include "GameObject.h"

class BG : public GameObject {
public:
    explicit BG(const ObjectParamLoader &pParams);

    void draw() override;

    void update() override;

    void clean() override;

    void nextFrame() override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    [[nodiscard]] bool isMIsDead() const override;

    [[nodiscard]] Vector2D getMSize() const override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    void setMText(const char *mText) override;

    void shoot(Vector2D velocity, Vector2D offset) override;
};


#endif //CPP_EKSAMEN3_BG_H
