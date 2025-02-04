//
// Created by 1024 on 05/04/2022.
//

#include "Player.h"

void Player::draw() {
    m_healthBar->draw();
    GameObject::draw();
}

void Player::update() {
    m_healthBar->updatePos(m_position + Vector2D{-28,-30});
    m_healthBar->setCurrent(m_lives*22);
    GameObject::update();
}

void Player::clean() {
    GameObject::clean();
}


void Player::nextFrame() {
    GameObject::nextFrame();
}

bool Player::isMIsDead() const {
    return GameObject::isMIsDead();
}

void Player::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void Player::checkCollision() {
    GameObject::checkCollision();
}

void Player::checkOOB() {
    GameObject::checkOOB();
}

const Vector2D &Player::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D Player::getMSize() const {
    return GameObject::getMSize();
}

void Player::setMText(const char *mText) {
    GameObject::setMText(mText);
}

void Player::shoot(Vector2D velocity, Vector2D offset) {
    GameObject::shoot(velocity, offset);
}


