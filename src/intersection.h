#pragma once

#include "spectrum.h"
#include "object_base.h"

class Intersection {
public:
    ObjectBase *object;
    float t;  // distance
    vec3 p;  // location
    vec2 uv;  // texcoord
    vec3 n;  // unit normal

    // evaluate the bsdf
    void getBSDF(vec3 wi, vec3 wo, Spectrum &bsdf) const;

    // importance sampling
    void getSample(vec3 wi, vec3 &wo, Spectrum &weight) const;
};

