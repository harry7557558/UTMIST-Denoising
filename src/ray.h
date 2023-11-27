#pragma once

#include "glm/glm/glm.hpp"

#include "spectrum.h"

struct Ray {
    glm::vec3 ro;
    glm::vec3 rd;
    float max_t;
    Spectrum colorContribution;
};
