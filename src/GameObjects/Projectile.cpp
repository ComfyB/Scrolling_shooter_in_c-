//
// Created by Christoffer Lehre on 09/04/2022.
//

#include "Projectile.h"

void Projectile::draw() {
    Renderable::draw();

}

void Projectile::update() {
    Renderable::update();
}

void Projectile::clean() {
    Renderable::clean();
}

void Projectile::nextFrame() {
    Renderable::nextFrame();
}

bool Projectile::isMIsDead() const {
    return Renderable::isMIsDead();
}

void Projectile::setMVelocity(Vector2D velocity) {
    Renderable::setMVelocity(velocity);
}

void Projectile::checkCollision() {
    Renderable::checkCollision();
}

void Projectile::checkOOB() {
    if(m_position.getY()<5)
        m_isDead= true;
    Renderable::checkOOB();
}

const Vector2D &Projectile::getMPosition() const {
    return Renderable::getMPosition();
}

Vector2D Projectile::getMSize() const {
    return Renderable::getMSize();
}
