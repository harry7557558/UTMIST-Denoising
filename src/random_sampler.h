#pragma once

#include <stdint.h>

class RandomSampler {
public:
    uint64_t seed;
    void setSeed(uint64_t seed);

    // random float in [0, 1)
    float randf();
};
