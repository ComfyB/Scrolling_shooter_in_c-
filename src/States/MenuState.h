//
// Created by Christoffer Lehre on 10/04/2022.
//

#ifndef CPP_EKSAMEN3_MENUSTATE_H
#define CPP_EKSAMEN3_MENUSTATE_H


#include <string>
#include <utility>
#include "GameState.h"

class MenuState : public GameState{
public:
    explicit MenuState(std::string id): m_menuID(std::move(id)) {  };
    ~MenuState() override = default;
    void update() override;
    void render() override;
    bool onEnter() override;
    bool onExit() override;
    [[nodiscard]]  std::string getStateID() const override;

private:
    const std::string m_menuID;
};


#endif //CPP_EKSAMEN3_MENUSTATE_H
