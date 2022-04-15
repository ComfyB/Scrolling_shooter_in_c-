//
// Created by Christoffer Lehre on 05/04/2022.
//

#include <memory>
#include "Renderable.h"
#include "Projectile.h"
#include "../Game/Game.h"
#include "../SupportClasses/SoundLoader.h"


void Renderable::draw() {
    TextureManager::Instance().drawFrame(m_textureID, m_position, m_size, m_currentFrame, m_currentRow,
                                         TextureManager::Instance().getRenderer(), SDL_FLIP_NONE, 0);
}


void Renderable::shoot() {
    currentTime = SDL_GetTicks64();
    if(currentTime>lastTime+100) {
        Game::Instance().addGameObject(std::shared_ptr<Renderable>(

                new Projectile({m_position + Vector2D{20, -60}, {5, 20}, {0, -5}, "bullet", 1,
                                1})));
       // SoundLoader::instance().playSound("shoot",1);

        lastTime = currentTime;
    }
}

void Renderable::update() {

     nextFrame();
    //make sure the object can´t leave screen
    checkOOB();
    if(m_hasHitBox)
        checkCollision();
    m_position = m_position + m_velocity;


}


void Renderable::checkOOB() {
    if (m_position.getX() <= 0){
        m_position.setX(1);
        m_velocity.setX(-m_velocity.getX()) ;
    }
    if (m_position.getX() >= WINDOWWIDTH - m_size.getX()){
        m_velocity.setX(-m_velocity.getX()) ;
        m_position.setX(WINDOWWIDTH - m_size.getX());
    }
    if (m_position.getY() <= 0){
        m_position.setY(1);
        m_velocity.setY(-m_velocity.getY()) ;

    }

    if (m_position.getY() >= WINDOWHEIGHT - m_size.getY()){
        m_position.setY(WINDOWHEIGHT - m_size.getY());
        m_velocity.setY(-m_velocity.getY()) ;
    }

}

void Renderable::clean() {
}

void Renderable::nextFrame() {
    m_currentFrame = int(SDL_GetTicks() / 100) % m_frames;

}


bool Renderable::isMIsDead() const {
    return m_isDead;
}


void Renderable::checkCollision() {
    for (const auto &two: Game::Instance().getGameObjects()) {
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


    if (m_lives == 0) {
        m_isDead = true;
    }
}}

void Renderable::setMVelocity(Vector2D velocity) {
    m_velocity = velocity;
}

const Vector2D &Renderable::getMPosition() const {
    return m_position;
}

Vector2D Renderable::getMSize() const {
    return m_size;
}

void Renderable::setMHasHitBox(bool mHasHitBox) {
    m_hasHitBox = mHasHitBox;
}
