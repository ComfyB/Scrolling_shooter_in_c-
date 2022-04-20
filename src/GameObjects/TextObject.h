//
// Created by Christoffer Lehre on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_TEXTOBJECT_H
#define CPP_EKSAMEN3_TEXTOBJECT_H


#include <utility>

#include "GameObject.h"
class TextObject : public GameObject{
public:
    TextObject(const ObjectParamLoader& params, const char * text) : GameObject(params), m_text(text){}

    void draw() override;

    void update() override;

    void clean() override;

    void shoot() override;

    void nextFrame() override;

    bool isMIsDead() const override;

    void setMVelocity(Vector2D velocity) override;

    void checkCollision() override;

    void checkOOB() override;

    const Vector2D &getMPosition() const override;

    Vector2D getMSize() const override;

    void setMText(const char *mText) override;

private:

    const char *m_text;
};


#endif //CPP_EKSAMEN3_TEXTOBJECT_H
