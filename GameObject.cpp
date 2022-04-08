//
// Created by Christoffer Lehre on 05/04/2022.
//

#include <memory>
#include "GameObject.h"
#include "Bullet.h"
#include "Game.h"

void GameObject::draw() {
    TextureManager::Instance().drawFrame(m_textureID, m_position, m_size, m_currentFrame, m_currentRow,
                                         TextureManager::Instance().getRenderer(), SDL_FLIP_NONE, 0);
}

void GameObject::shoot(){
    auto bullet = new Bullet({m_position+Vector2D{20,-25},{5,15},{0,-10},"bullet",100,1});
    Game::Instance().addGameObject(bullet);
  //  Game::Instance().addGameObject(new Bullet({m_position+Vector2D{49,-25},{5,15},{0,-10},"bullet",100,1}));
    SDL_Delay(5);
}

void GameObject::update() {
    nextFrame();
    //make sure the object can´t leave screen
    m_position = m_position + m_velocity;
    if (m_position.getX() <= 0)
        m_position.setX(1);
    if (m_position.getX() >= WINDOWWIDTH - m_size.getX())
        m_position.setX(WINDOWWIDTH - m_size.getX());
    if (m_position.getY() <= 0)
        m_position.setY(1);
    if (m_position.getY() >= WINDOWHEIGHT - m_size.getY())
        m_position.setY(WINDOWHEIGHT - m_size.getY());

}

void GameObject::clean() {

}

bool GameObject::deleteOneLife(){
    m_lives--;
    if(m_lives <= 0){
        m_isDead = true;
        return true;
    }
    return false;
}

void GameObject::nextFrame() {

    m_currentFrame = int(SDL_GetTicks() / 100) % m_numFrames;

}

void GameObject::setMVelocity(const Vector2D &mVelocity) {
    m_velocity = mVelocity;
}

const Vector2D &GameObject::getMPosition() const {
    return m_position;
}

const Vector2D &GameObject::getMSize() const {
    return m_size;
}

bool GameObject::isMIsDead() const {
    return m_isDead;
}
