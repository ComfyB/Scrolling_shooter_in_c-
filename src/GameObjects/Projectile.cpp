//
// Created by Christoffer Lehre on 09/04/2022.
//

#include "Projectile.h"

void Projectile::draw() {
    GameObject::draw();

}

void Projectile::update() {
    GameObject::update();
}

void Projectile::clean() {
    GameObject::clean();
}

void Projectile::nextFrame() {
    GameObject::nextFrame();
}

bool Projectile::isMIsDead() const {
    return GameObject::isMIsDead();
}

void Projectile::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void Projectile::checkCollision() {
    GameObject::checkCollision();
}

void Projectile::checkOOB() {
    if(m_position.getY()<5)
        m_isDead= true;
    GameObject::checkOOB();
}

const Vector2D &Projectile::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D Projectile::getMSize() const {
    return GameObject::getMSize();
}
