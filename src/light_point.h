#pragma once

#include "light.h"

class LightPoint : Light {
public:
    vec3 position;
    float radius;
    Spectrum intensity;

    LightPoint();
    LightPoint(vec3 position, float radius);

    void applyTransform();

    void getRadiance(Ray ray, Spectrum &radiance) const;
    void getDLS(vec3 ro, Spectrum &weight) const;
};
