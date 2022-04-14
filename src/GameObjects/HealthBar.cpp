//
// Created by Christoffer Lehre on 09/04/2022.
//

#include "HealthBar.h"
#include "../SupportClasses/TextureManager.h"

void HealthBar::draw() {
    TextureManager::Instance().drawBar(m_pos,m_size);
}
