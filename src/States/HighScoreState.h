//
// Created by 1024 on 14/04/2022.
//

#ifndef CPP_EKSAMEN3_HIGHSCORESTATE_H
#define CPP_EKSAMEN3_HIGHSCORESTATE_H


#include "../Game/Game.h"

class HighScoreState : public GameState {
public:
    explicit HighScoreState(std::string id) : m_highscoreID(std::move(id)) {};

    void update() override;

    void render() override;

    bool onEnter() override;

    bool onExit() override;

    [[nodiscard]] std::string getStateID() const override;

    void increaseScore() override;

private:
    std::vector<std::string> m_highscores;
    const std::string m_highscoreID;

};


#endif //CPP_EKSAMEN3_HIGHSCORESTATE_H
