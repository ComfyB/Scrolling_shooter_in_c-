//
// Created by 1024 on 10/04/2022.
//

#include <charconv>
#include <memory>
#include "PlayingState.h"
#include "../Game/Game.h"
#include "../SupportClasses/SoundLoader.h"
#include "MenuState.h"
#include "../GameObjects/TextObject.h"
#include "../SupportClasses/FileReader.h"
#include "../GameObjects/BG.h"

void PlayingState::update() {
    updateScore();
    keyInputs();
    if (m_player->isMIsDead()) {
        FileReader::addHighscore(m_score);
        Game::instance().getMGameStateMachine()->changeState(std::shared_ptr<GameState>(new MenuState("Menu")));
    }

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
            m_player->setMVelocity({-5, 0});
            break;
        case InputHandler::RIGHT:
            m_player->setMVelocity({5, 0});
            break;
        case InputHandler::MUTED:
            SoundLoader::instance().mute();
            break;
        case InputHandler::QUIT:
            m_player->setMIsDead(true); //bugs if you don't let the gameLoop() do the normal cleanups.
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

bool PlayingState::onEnter() {
    //load textures

    TextureManager::instance().load("../img/BG_1.png", "bg");
    TextureManager::instance().load("../img/level1.png", "bg1");
    TextureManager::instance().load("../img/ship3.png", "ship");
    TextureManager::instance().load("../img/UFO.png", "enemy");
    TextureManager::instance().load("../img/bullet.png", "bullet");
    //load shooting sound
    SoundLoader::instance().loadSound("../sound/shoot.wav", "shoot");

    //update saved pointers to new objects
    m_bg = std::shared_ptr<GameObject>(new BG({{0, -2400}, {800, 3000}, {0, 2}, "bg", 1, 1}));
    m_bg_level = std::shared_ptr<GameObject>(new BG({{0, 0}, {800, 600}, {0, 0}, "bg1", 1, 1}));
    m_scoreText = std::shared_ptr<GameObject>(new TextObject({{600, 30}, {120, 30}, {0, 0}, "NULL", 1, 1}, "1"));
    m_player = std::shared_ptr<GameObject>(new Player({{10, 300}, {50, 64}, {1, 1}, "ship", 5, 4},
                                                      std::make_shared<HealthBar>(Vector2D{0, 0}, Vector2D{250, 15})));
    Game::instance().addGameObject(m_bg);
    Game::instance().addGameObject(m_bg_level);
    Game::instance().addGameObject(m_scoreText);


    Game::instance().addGameObject(std::shared_ptr<GameObject>(new TextObject({{80,30},{80,15},{0,0},"NULL",1,1},"m to mute")));
// add the two items that should render up top. unfortunatly as we dont have an index, when you push the objects into the array matters.
    Game::instance().addGameObject(m_player);
    Game::instance().setMPlayer(m_player);
    Game::instance().randomEnemy(0);
    m_score = 0;
    return true;
}

bool PlayingState::onExit() {
    FileReader::addHighscore(m_score);
    SoundLoader::instance().clean();
    Game::instance().cleanState();
    return true;
}

std::string PlayingState::getStateID() const {
    return m_menuID;
}

void PlayingState::updateScore() {
    m_scoreText_string = "score:\t" + std::to_string(m_score);
    m_scoreText->setMText(m_scoreText_string.c_str());

    //change BGcolor and difficulty if the score is corresponding to next level.

    if(m_score == 3 && m_currentLevel != 2){
        TextureManager::instance().cleanAt("bg1");
        TextureManager::instance().load("../img/level2.png", "bg1");
        Game::instance().setMDifficulty(2);
        m_currentLevel = 2;
    }    if(m_score == 6 && m_currentLevel != 3){
        TextureManager::instance().cleanAt("bg1");
        TextureManager::instance().load("../img/level3.png", "bg1");
        Game::instance().setMDifficulty(3);
        m_currentLevel = 3;
    }   if(m_score == 9 && m_currentLevel != 4){
        TextureManager::instance().cleanAt("bg1");
        TextureManager::instance().load("../img/level3.png", "bg1");
        Game::instance().setMDifficulty(4);
        m_currentLevel = 4;
    }

}


void PlayingState::increaseScore() {
    m_score++;
}
