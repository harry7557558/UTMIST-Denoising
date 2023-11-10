#pragma once

#include "light.h"

class LightSpot : Light {
public:

    vec3 position;
    vec3 direction;  // unit vector
    float angle;
    Spectrum intensity;

    LightSpot();

    void applyTransform();

    void getRadiance(Ray ray, Spectrum &radiance) const;
    void getDLS(vec3 ro, Spectrum &weight) const;
};
