//
// Created by Christoffer Lehre on 05/04/2022.
//

#include "Player.h"

void Player::draw() {
    m_healthBar->draw();
    GameObject::draw();
}

void Player::update() {
    m_healthBar->setCurrent(14*m_lives);
    m_healthBar->updatePos(m_position + Vector2D{-10,-30});
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

void Player::shoot() {


    GameObject::shoot();
}


