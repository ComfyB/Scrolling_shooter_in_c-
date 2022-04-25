//
// Created by 1024 on 10/04/2022.
//

#ifndef CPP_EKSAMEN3_MENUSTATE_H
#define CPP_EKSAMEN3_MENUSTATE_H


#include <string>
#include <utility>
#include <memory>
#include "GameState.h"
#include "../GameObjects/GameObject.h"

class MenuState : public GameState {
public:
    explicit MenuState(std::string id) : m_menuID(std::move(id)) {
        currentSelection = NEWGAME;
    };

    ~MenuState() override = default;

    void update() override;

    bool onEnter() override;

    bool onExit() override;

    [[nodiscard]]  std::string getStateID() const override;

    void increaseScore() override {}

private:
    enum menuItem {
        NEWGAME = 1021, HIGHSCORE = 1022, ENDGAME = 1023
    };
    std::shared_ptr<GameObject> selector;
    menuItem currentSelection;
    const std::string m_menuID;
};


#endif //CPP_EKSAMEN3_MENUSTATE_H
