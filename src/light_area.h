#pragma once

#include "light.h"

class LightArea : Light {
public:
    enum Shape { CIRCLE, SQUARE };

    Shape shape;
    vec3 position;
    mat3 orientation;
    float size;
    bool twoSided;
    Spectrum intensity;

    LightArea();

    void applyTransform();

    void getRadiance(Ray ray, Spectrum &radiance) const;
    void getDLS(vec3 ro, Spectrum &weight) const;
};
