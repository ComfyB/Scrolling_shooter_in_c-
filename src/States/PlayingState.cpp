//
// Created by 1024 on 10/04/2022.
//

#include <charconv>
#include "PlayingState.h"
#include "../Game/Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "MenuState.h"
#include "../GameObjects/TextObject.h"

void PlayingState::update() {
    updateScore();
    keyInputs();
}

void PlayingState::keyInputs() {
    switch (InputHandler::Instance().update()) {
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
        case InputHandler::QUIT:
            Game::instance().getMGameStateMachine()->changeState(std::shared_ptr<GameState>(new MenuState("Menu")));
            break;
        case InputHandler::SPACE:
            m_player->shoot({0, -8}, {30, -40});
            break;
        case InputHandler::RANDOMENEMY:
        case InputHandler::NEWGAME:
        case InputHandler::NOTHING:
        case InputHandler::ENTER:
            break;
    }
}

void PlayingState::render() {

}

bool PlayingState::onEnter() {
    TextureManager::instance().load("../img/ship3.png", "ship");
    TextureManager::instance().load("../img/UFO.png", "enemy");
    TextureManager::instance().load("../img/bullet.png", "bullet");
    SoundLoader::instance().loadSound("../sound/shoot.wav", "shoot");
    m_scoreText = std::shared_ptr<GameObject>(new TextObject({{600, 30}, {120, 30}, {0, 0}, "NULL", 1, 1}, "1"));
    m_scoreText->setMHasHitBox(false);
    m_player = std::make_shared<GameObject>(Player({{10, 300}, {50, 64}, {1, 1}, "ship", 5, 4},
                                                   std::make_shared<HealthBar>(HealthBar{80, {50, 50}, {80, 15}})));
    Game::instance().addGameObject(m_scoreText);
    Game::instance().addGameObject(m_player);
    Game::instance().randomEnemy();
    return true;
}

bool PlayingState::onExit() {
    Game::instance().cleanState();
    SoundLoader::instance().clean();
    return true;
}

std::string PlayingState::getStateID() const {
    return m_menuID;
}

std::shared_ptr<GameObject> PlayingState::getPlayer() const {
    return m_player;
}

void PlayingState::updateScore() {
    m_scoreText_string = "score" + std::to_string(m_score);
    m_scoreText->setMText(m_scoreText_string.c_str());

}
