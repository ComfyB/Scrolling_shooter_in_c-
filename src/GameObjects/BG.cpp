//
// Created by 1024 on 25/04/2022.
//

#include "BG.h"

void BG::draw() {
    GameObject::draw();
}

void BG::update() {
    GameObject::update();
}

void BG::clean() {
    GameObject::clean();
}

void BG::nextFrame() {
    GameObject::nextFrame();
}

bool BG::isMIsDead() const {
    return GameObject::isMIsDead();
}

void BG::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void BG::checkCollision() {
    GameObject::checkCollision();
}

void BG::checkOOB() {
    if(m_position.getY() <= -(m_size.getY()-600)){
        m_position= {0,0};
    }
}

const Vector2D &BG::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D BG::getMSize() const {
    return GameObject::getMSize();
}

void BG::setMText(const char *mText) {
    GameObject::setMText(mText);
}

void BG::shoot(Vector2D velocity, Vector2D offset) {
    GameObject::shoot(velocity, offset);
}

BG::BG(const ObjectParamLoader &pParams) : GameObject(pParams) {
    m_hasHitBox = false;
}
