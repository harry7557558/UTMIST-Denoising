#pragma once

#include "light.h"

class LightSky : Light {
    // research sky model representation
public:
    LightSky();

    void getRadiance(Ray ray, Spectrum &radiance) const;
    void getDLS(vec3 ro, Spectrum &weight) const;
};
