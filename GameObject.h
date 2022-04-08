//
// Created by Christoffer Lehre on 05/04/2022.
//

#ifndef CPP_EKSAMEN3_GAMEOBJECT_H
#define CPP_EKSAMEN3_GAMEOBJECT_H


#include <string>
#include "Vector2D.h"
#include "ObjectParamLoader.h"
#include "TextureManager.h"

class GameObject{
private:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_size;

    std::string m_textureID;
    int m_lives;
    int m_currentRow;
    //int m_numRow;
    int m_numFrames;
    int m_currentFrame;

    bool m_isDead;
public:
    explicit GameObject(const ObjectParamLoader &pParams) : m_position(pParams.getMPosition()),
                                                            m_velocity(pParams.getMVelocity()),
                                                            m_size(pParams.getMSize()),
                                                            m_textureID(pParams.getMTextureId()),
                                                            m_numFrames(pParams.getMNumFrames()),
                                                            m_lives(pParams.getMLives()) {
        m_isDead = false;
        m_currentRow = 0;
        m_currentFrame = 0;
    }

    virtual void draw();

    virtual void update();

    virtual void clean();

    virtual void shoot();

    [[nodiscard]] const Vector2D &getMPosition() const;

    [[nodiscard]] const Vector2D &getMSize() const;

    void nextFrame();

    void setMVelocity(const Vector2D &mVelocity);

    [[nodiscard]] bool isMIsDead() const ;

    bool deleteOneLife();
};


#endif //CPP_EKSAMEN3_GAMEOBJECT_H
