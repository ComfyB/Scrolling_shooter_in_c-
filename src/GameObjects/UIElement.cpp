//
// Created by 1024 on 15/04/2022.
//

#include "UIElement.h"

void UIElement::draw() {
    GameObject::draw();
}

void UIElement::update() {
    GameObject::update();
}

void UIElement::clean() {
    GameObject::clean();
}


void UIElement::nextFrame() {
    GameObject::nextFrame();
}

bool UIElement::isMIsDead() const {
    return GameObject::isMIsDead();
}

void UIElement::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void UIElement::checkCollision() {
    GameObject::checkCollision();
}

void UIElement::checkOOB() {
    GameObject::checkOOB();
}

const Vector2D &UIElement::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D UIElement::getMSize() const {
    return GameObject::getMSize();
}

UIElement::UIElement(const ObjectParamLoader &pParams) : GameObject(pParams) {
    m_hasHitBox = false;
}

void UIElement::setMText(const char *mText) {
    GameObject::setMText(mText);
}

void UIElement::shoot(Vector2D velocity, Vector2D offset) {
    GameObject::shoot(velocity, offset);
}
