#pragma once

#include "spectrum.h"

class MaterialBase {
public:

    // evaluate the BSDF
    virtual void getBSDF(vec3 wi, vec3 wo, Spectrum &bsdf) const = 0;

    // importance sampling
    virtual void getSample(vec3 wi, vec3 &wo, Spectrum &weight) const = 0;

};
