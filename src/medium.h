#pragma once

#include "spectrum.h"

class Medium {
public:
    Spectrum absorption;
    float scatterDensity;
    float scatterAnisotropy;
    Spectrum emission;

    // evaluate the phase function
    void getPhaseFunction(vec3 wi, vec3 wo, Spectrum &phase) const;

    // importance sampling
    void getSample(vec3 wi, vec3 &wo, Spectrum &weight) const;
};
