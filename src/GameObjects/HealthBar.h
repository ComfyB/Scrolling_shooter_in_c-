//
// Created by 1024 on 09/04/2022.
//

#ifndef CPP_EKSAMEN3_HEALTHBAR_H
#define CPP_EKSAMEN3_HEALTHBAR_H


#include "../SupportClasses/Vector2D.h"

class HealthBar {
    int m_current_width;

    Vector2D m_pos;
    Vector2D m_size;

public:
    HealthBar(int current, Vector2D pos, Vector2D size) : m_current_width(current), m_pos(pos), m_size(size) {
    }

    void draw();

    void setCurrent(int current) { m_size.setX(current); }

    void updatePos(Vector2D pos) {
        m_pos = pos;
    }

};


#endif //CPP_EKSAMEN3_HEALTHBAR_H
