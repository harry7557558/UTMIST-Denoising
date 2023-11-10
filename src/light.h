#pragma once

#include "object_base.h"

class Light : ObjectBase {
public:
    virtual void getRadiance(Ray ray, Spectrum &radiance) const = 0;
    virtual void getDLS(vec3 ro, Spectrum &weight) const = 0;

    // set material and medium to nullptr
    Light();
};
