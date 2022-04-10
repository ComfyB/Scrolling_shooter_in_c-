//
// Created by Christoffer Lehre on 08/04/2022.
//

#include "Randomizer.h"

int Randomizer::generateRandomNumber(int min, int max) {
    uint32_t seed = SDL_GetTicks();
    std::mt19937 rng(seed*rand());
    std::uniform_int_distribution<int> int_dist(min, max);
    return int_dist(rng);
}
