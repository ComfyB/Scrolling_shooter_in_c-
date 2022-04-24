//
// Created by 1024 on 15/04/2022.
//

#include "UI_Element.h"

void UI_Element::draw() {
    GameObject::draw();
}

void UI_Element::update() {
    GameObject::update();
}

void UI_Element::clean() {
    GameObject::clean();
}


void UI_Element::nextFrame() {
    GameObject::nextFrame();
}

bool UI_Element::isMIsDead() const {
    return GameObject::isMIsDead();
}

void UI_Element::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void UI_Element::checkCollision() {
    GameObject::checkCollision();
}

void UI_Element::checkOOB() {
    GameObject::checkOOB();
}

const Vector2D &UI_Element::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D UI_Element::getMSize() const {
    return GameObject::getMSize();
}

UI_Element::UI_Element(const ObjectParamLoader &pParams) : GameObject(pParams) {
    m_hasHitBox = false;
}

void UI_Element::setMText(const char *mText) {
    GameObject::setMText(mText);
}

void UI_Element::shoot(Vector2D velocity, Vector2D offset) {
    GameObject::shoot(velocity, offset);
}
