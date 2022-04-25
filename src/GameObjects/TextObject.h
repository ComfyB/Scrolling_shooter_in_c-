//
// Created by 1024 on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_TEXTOBJECT_H
#define CPP_EKSAMEN3_TEXTOBJECT_H


#include <utility>

#include "GameObject.h"

class TextObject : public GameObject {
public:
    TextObject(const ObjectParamLoader &params, std::string text) : GameObject(params), m_text(std::move(text)) {m_hasHitBox=false;}

    void nextFrame() override;

    void update() override;

    void clean() override;

    void draw() override;

    void shoot(Vector2D velocity, Vector2D offset) override;

    void setMText(const char *mText) override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    [[nodiscard]] const Vector2D &getMPosition() const override;

    [[nodiscard]] Vector2D getMSize() const override;

    [[nodiscard]] bool isMIsDead() const override;


private:

   std::string m_text;
};


#endif //CPP_EKSAMEN3_TEXTOBJECT_H
