//
// Created by Christoffer Lehre on 05/04/2022.
//

#include "Enemy.h"

void Enemy::draw() {
    m_healthBar->draw();
    Renderable::draw();
}

void Enemy::update() {
    m_healthBar->setCurrent(m_lives*20);
    m_healthBar->updatePos(m_position + Vector2D{0,-30});
    Renderable::update();
}

void Enemy::clean() {
    Renderable::clean();
}


void Enemy::nextFrame() {
    Renderable::nextFrame();
}

bool Enemy::isMIsDead() const {
    return Renderable::isMIsDead();
}

void Enemy::setMVelocity(Vector2D velocity) {
    Renderable::setMVelocity(velocity);
}

void Enemy::checkCollision() {
    Renderable::checkCollision();
}

void Enemy::checkOOB() {
    Renderable::checkOOB();
}

const Vector2D &Enemy::getMPosition() const {
    return Renderable::getMPosition();
}

Vector2D Enemy::getMSize() const {
    return Renderable::getMSize();
}
