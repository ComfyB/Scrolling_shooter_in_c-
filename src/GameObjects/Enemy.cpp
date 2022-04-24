//
// Created by 1024 on 05/04/2022.
//

#include "Enemy.h"

void Enemy::draw() {
    m_healthBar->draw();
    GameObject::draw();
}

void Enemy::update() {
    m_healthBar->setCurrent(m_lives * 26);
    m_healthBar->updatePos(m_position + Vector2D{-10, -50});
    GameObject::update();
}

void Enemy::clean() {
    GameObject::clean();
}


void Enemy::nextFrame() {
    GameObject::nextFrame();
}

bool Enemy::isMIsDead() const {
    return GameObject::isMIsDead();
}


void Enemy::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

const Vector2D &Enemy::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D Enemy::getMSize() const {
    return GameObject::getMSize();
}

void Enemy::checkCollision() {
    GameObject::checkCollision();
}

void Enemy::checkOOB() {
    GameObject::checkOOB();
}