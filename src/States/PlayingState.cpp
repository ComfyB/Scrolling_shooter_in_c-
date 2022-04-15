//
// Created by Christoffer Lehre on 10/04/2022.
//

#include "PlayingState.h"
#include "../Game/Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "MenuState.h"

void PlayingState::update() {
    keyInputs();
}

void PlayingState::keyInputs() {
    switch (InputHandler::Instance().update()){
        case InputHandler::UP:
            m_player->setMVelocity({0, -2});
            break;
        case InputHandler::DOWN:
            m_player->setMVelocity({0, 2});
            break;
        case InputHandler::LEFT:
            m_player->setMVelocity({-2, 0});
            break;
        case InputHandler::RIGHT:
            m_player->setMVelocity({2, 0});
            break;
        case InputHandler::NEWGAME:
            break;
        case InputHandler::QUIT:
            Game::Instance().getMGameStateMachine()->pushState(new MenuState);

            break;
        case InputHandler::SPACE:
            m_player->shoot();
            break;
        case InputHandler::RANDOMENEMY:
            break;
    };
}

void PlayingState::render() {

}

bool PlayingState::onEnter() {

    TextureManager::Instance().load("../img/ship3.png", "ship");
    TextureManager::Instance().load("../img/UFO.png", "enemy");
    TextureManager::Instance().load("../img/bullet.png", "bullet");
    SoundLoader::instance().loadSound("../sound/shoot.wav", "shoot");
    m_player = std::shared_ptr<Renderable>(new Player({{10, 300}, {50, 64}, {1, 1}, "ship", 5, 4}, new HealthBar{80, {0, 0}, {80, 15}}));
    Game::Instance().addGameObject(m_player);
    Game::Instance().randomEnemy();
    return true;
}

bool PlayingState::onExit() {
    return false;
}

std::string PlayingState::getStateID() const {
    return m_menuID;
}
std::shared_ptr<Renderable> PlayingState::getPlayer() const {
    return m_player;
}
