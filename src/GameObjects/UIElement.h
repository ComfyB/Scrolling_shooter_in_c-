//
// Created by 1024 on 15/04/2022.
//

#ifndef CPP_EKSAMEN3_UIELEMENT_H
#define CPP_EKSAMEN3_UIELEMENT_H


#include "GameObject.h"

class UIElement : public GameObject {
public:
    explicit UIElement(const ObjectParamLoader &pParams);

    void draw() override;

    void update() override;

    void clean() override;

    void shoot(Vector2D velocity, Vector2D offset) override;

    void nextFrame() override;

    [[nodiscard]] bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    void setMText(const char *mText) override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;
};


#endif //CPP_EKSAMEN3_UIELEMENT_H
