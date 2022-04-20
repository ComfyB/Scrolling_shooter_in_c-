//
// Created by Christoffer Lehre on 10/04/2022.
//

#ifndef CPP_EKSAMEN3_PLAYINGSTATE_H
#define CPP_EKSAMEN3_PLAYINGSTATE_H


#include <memory>
#include "GameState.h"
#include "../GameObjects/GameObject.h"

class PlayingState : public GameState {
public:
    explicit PlayingState(std::string id): m_menuID(std::move(id)) {  };
    ~PlayingState() override= default;
    void update() override;
    void render() override;
    bool onEnter() override;
    bool onExit() override;
    [[nodiscard]] std::string getStateID() const override;
    [[nodiscard]] std::shared_ptr<GameObject> getPlayer() const;

private:
    int m_score = 0;
    const std::string m_menuID;
    std::string m_scoreText_string;
    std::shared_ptr<GameObject> m_player;
    std::shared_ptr<GameObject> m_scoreText;

    void keyInputs();

    void updateScore();
};

#endif //CPP_EKSAMEN3_PLAYINGSTATE_H
