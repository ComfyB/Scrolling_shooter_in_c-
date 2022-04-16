//
// Created by Christoffer Lehre on 05/04/2022.
//

#include <memory>
#include "GameObject.h"
#include "Projectile.h"
#include "../Game/Game.h"
#include "../SupportClasses/SoundLoader.h"


void GameObject::draw() {
    TextureManager::instance().drawFrame(m_textureID, m_position, m_size, m_currentFrame, m_currentRow,
                                         TextureManager::instance().getRenderer(), SDL_FLIP_NONE, 0);
}


void GameObject::shoot() {
    currentTime = SDL_GetTicks64();
    if (currentTime > lastTime + 100) {
        Game::Instance().addGameObject(std::shared_ptr<GameObject>(

                new Projectile({m_position + Vector2D{20, -60}, {5, 20}, {0, -5}, "bullet", 1,
                                1})));
        // SoundLoader::instance().playSound("shoot",1);

        lastTime = currentTime;
    }
}

void GameObject::update() {

    nextFrame();
    //make sure the object can´t leave screen
    checkOOB();
    if (m_hasHitBox)
        checkCollision();
    m_position = m_position + m_velocity;


}


void GameObject::checkOOB() {
    if (m_position.getX() <= 0) {
        m_position.setX(1);
        m_velocity.setX(-m_velocity.getX());
    }
    if (m_position.getX() >= WINDOWWIDTH - m_size.getX()) {
        m_velocity.setX(-m_velocity.getX());
        m_position.setX(WINDOWWIDTH - m_size.getX());
    }
    if (m_position.getY() <= 0) {
        m_position.setY(1);
        m_velocity.setY(-m_velocity.getY());

    }

    if (m_position.getY() >= WINDOWHEIGHT - m_size.getY()) {
        m_position.setY(WINDOWHEIGHT - m_size.getY());
        m_velocity.setY(-m_velocity.getY());
    }

}

void GameObject::clean() {
}

void GameObject::nextFrame() {
    m_currentFrame = int(SDL_GetTicks() / 100) % m_frames;

}


bool GameObject::isMIsDead() const {
    return m_isDead;
}


void GameObject::checkCollision() {
    for (const auto &two: Game::Instance().getGameObjects()) {
        if (m_hasHitBox && two->m_hasHitBox) {
            // collision x-axis?
            bool collisionX = m_position.getX() + m_size.getX() >= two->getMPosition().getX() &&
                              two->getMPosition().getX() + two->getMSize().getX() >= m_position.getX();
            // collision y-axis?
            bool collisionY = m_position.getY() + m_size.getY() >= two->getMPosition().getY() &&
                              two->getMPosition().getY() + two->getMSize().getY() >= m_position.getY();
            // collision only if on both axes
            if (collisionX && collisionY && (this != two.get())) {
                m_lives--;
                m_velocity = m_velocity - m_velocity * 2;
            }

        }


        if (m_lives == 0) {
            m_isDead = true;
        }
    }
}

void GameObject::setMVelocity(Vector2D velocity) {
    m_velocity = velocity;
}

const Vector2D &GameObject::getMPosition() const {
    return m_position;
}

Vector2D GameObject::getMSize() const {
    return m_size;
}

void GameObject::setMHasHitBox(bool mHasHitBox) {
    m_hasHitBox = mHasHitBox;
}

void GameObject::setMIsDead(bool mIsDead) {
    m_isDead = mIsDead;
}

void GameObject::setMText(const char *mText) {
}

void GameObject::setMPosition(const Vector2D &mPosition) {
    m_position = mPosition;
}
