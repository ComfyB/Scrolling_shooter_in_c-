//
// Created by 1024 on 09/04/2022.
//

#include "HealthBar.h"
#include "../SupportClasses/TextureManager.h"

void HealthBar::draw() {
    TextureManager::instance().drawBar(m_pos, m_size);
}
