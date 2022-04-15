//
// Created by Christoffer Lehre on 10/04/2022.
//

#ifndef CPP_EKSAMEN3_PLAYINGSTATE_H
#define CPP_EKSAMEN3_PLAYINGSTATE_H


#include <memory>
#include "GameState.h"
#include "../GameObjects/Renderable.h"

class PlayingState : public GameState {
public:
    PlayingState() = default;
    ~PlayingState() override= default;
    void update() override;
    void render() override;
    bool onEnter() override;
    bool onExit() override;
    std::string getStateID() const override;
private:
    const std::string m_menuID;
    std::shared_ptr<Renderable> m_player;


    std::shared_ptr<Renderable> getPlayer() const;
};

#endif //CPP_EKSAMEN3_PLAYINGSTATE_H
