//
// Created by Christoffer Lehre on 14/04/2022.
//

#include "TextObject.h"
#include "../SupportClasses/TextureManager.h"

void TextObject::draw() {
    TextureManager::instance().renderText(m_text,m_position,m_size);
}


void TextObject::update() {
}

void TextObject::clean() {
    GameObject::clean();
}


void TextObject::nextFrame() {
    GameObject::nextFrame();
}

bool TextObject::isMIsDead() const {
    return GameObject::isMIsDead();
}

void TextObject::setMVelocity(Vector2D velocity) {
    GameObject::setMVelocity(velocity);
}

void TextObject::checkCollision() {
    GameObject::checkCollision();
}

void TextObject::checkOOB() {
    GameObject::checkOOB();
}

const Vector2D &TextObject::getMPosition() const {
    return GameObject::getMPosition();
}

Vector2D TextObject::getMSize() const {
    return GameObject::getMSize();
}

void TextObject::setMText(const char *mText) {
    m_text = mText;
}

void TextObject::shoot(Vector2D velocity, Vector2D offset) {
    GameObject::shoot(velocity, offset);
}
