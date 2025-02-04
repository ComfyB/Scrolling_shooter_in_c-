//
// Created by 1024 on 05/04/2022.
//

#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <string>
#include "../SupportClasses/Vector2D.h"
#include "../SupportClasses/ObjectParamLoader.h"
#include "SDL.h"

class GameObject {
protected:
    Vector2D m_velocity;
    Vector2D m_size;
    Vector2D m_position;


    Uint32 currentTime = 0;
    Uint32 lastTime = 0;

    std::string m_identifier;

    std::string m_textureID;
    int m_lives;
    int m_currentRow;
    int m_frames;
    int m_currentFrame;

    bool m_isDead;
    bool m_hasHitBox;


    explicit GameObject(const ObjectParamLoader &pParams) : m_position(pParams.getMPosition()),
                                                            m_velocity(pParams.getMVelocity()),
                                                            m_size(pParams.getMSize()),
                                                            m_textureID(pParams.getMTextureId()),
                                                            m_frames(pParams.getMNumFrames()),
                                                            m_lives(pParams.getMLives()) {
        m_isDead = false;
        m_currentRow = 0;
        m_currentFrame = 0;
        m_hasHitBox = true;
        m_identifier = "";
    }

public:

    virtual void draw();

    virtual void update();

    virtual void clean();

    virtual void nextFrame();



    virtual void setMVelocity(Vector2D velocity);

    virtual void checkCollision();

    virtual void checkOOB();

    virtual void setMText(const char *mText);

    void setMIsDead(bool mIsDead);

    void setMPosition(const Vector2D &mPosition);

    virtual void shoot(Vector2D velocity, Vector2D offset);

    [[nodiscard]] virtual const Vector2D &getMPosition() const;

    [[nodiscard]] virtual Vector2D getMSize() const;

    [[nodiscard]] virtual bool isMIsDead() const;


};


#endif //_GAMEOBJECT_H
