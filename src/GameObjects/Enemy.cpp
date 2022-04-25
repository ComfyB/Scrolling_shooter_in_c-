//
// Created by 1024 on 05/04/2022.
//

#include "Enemy.h"
#include "../Game/Game.h"

void Enemy::draw() {
    m_healthBar->draw();
    GameObject::draw();
}

void Enemy::update() {
    m_healthBar->setCurrent(m_lives * 26);
    m_healthBar->updatePos(m_position + Vector2D{-5, 0});
    if(SDL_GetTicks64()%80 == 0){
        shoot({0,0},{0,0});
    }
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

Vector2D Enemy::normalize(int velocityFactor,Vector2D v)
{
    //normalizing a line makes the x, y, (z)
    //components < 1 making their magnitude (a^2 + b^2 = c^2)
    //equal 1
    double x,y;
    double length = sqrt(v.getX()*v.getX()+v.getY()*v.getY());
    x = (v.getX()/length);
    y = (v.getY()/length);
    x*=velocityFactor;
    y*=velocityFactor;
    return {(int)x,(int)y};
}

void Enemy::shoot(Vector2D velocity, Vector2D offset) {
    Vector2D playerPos = Game::instance().getMPlayer()->getMPosition();

    Vector2D velocityTowardsPlayer = {playerPos-m_position};

    GameObject::shoot(normalize(4,velocityTowardsPlayer),  {20,100});
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