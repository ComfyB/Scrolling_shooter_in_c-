//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_OBJECTPARAMLOADER_H
#define CPP_EKSAMEN3_OBJECTPARAMLOADER_H


#include <string>
#include "Vector2D.h"

class ObjectParamLoader {
public:
    ObjectParamLoader(Vector2D pos, Vector2D size, Vector2D velocity, std::string textureID, int num_lives,
                      int num_frames) : m_position(pos), m_size(size), m_textureId(std::move(textureID)),
                                        m_velocity(velocity), m_lives(num_lives), m_numFrames(num_frames) {};

    [[nodiscard]] const Vector2D &getMPosition() const {
        return m_position;
    }

    [[nodiscard]] const std::string &getMTextureId() const {
        return m_textureId;
    }

    [[nodiscard]] const Vector2D &getMVelocity() const {
        return m_velocity;
    }

    [[nodiscard]] const Vector2D &getMSize() const {
        return m_size;
    }

    [[nodiscard]] int getMLives() const {
        return m_lives;
    }

    [[nodiscard]] int getMNumFrames() const {
        return m_numFrames;
    }

private:
    Vector2D m_position;
    Vector2D m_size;
    Vector2D m_velocity;
    std::string m_textureId;
    int m_lives;
    int m_numFrames;


};


#endif //CPP_EKSAMEN3_OBJECTPARAMLOADER_H
