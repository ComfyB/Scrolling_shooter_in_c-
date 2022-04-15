//
// Created by Christoffer Lehre on 05/04/2022.
//

#include "Player.h"

void Player::draw() {
    m_healthBar->draw();
    Renderable::draw();
}

void Player::update() {
    m_healthBar->setCurrent(14*m_lives);
    m_healthBar->updatePos(m_position + Vector2D{-10,-30});
    Renderable::update();
}

void Player::clean() {
    Renderable::clean();
}


void Player::nextFrame() {
    Renderable::nextFrame();
}

bool Player::isMIsDead() const {
    return Renderable::isMIsDead();
}

void Player::setMVelocity(Vector2D velocity) {
    Renderable::setMVelocity(velocity);
}

void Player::checkCollision() {
    Renderable::checkCollision();
}

void Player::checkOOB() {
    Renderable::checkOOB();
}

const Vector2D &Player::getMPosition() const {
    return Renderable::getMPosition();
}

Vector2D Player::getMSize() const {
    return Renderable::getMSize();
}

void Player::shoot() {


    Renderable::shoot();
}


