#pragma once

#include "transform.h"
#include "ray.h"
#include "material_base.h"
#include "medium.h"

class ObjectBase {
public:
    MaterialBase *material;
    Medium *medium;
    mat4 transform;

    // apply transform to object and set transform matrix to identity
    // do nothing in base class
    virtual void applyTransform();

    virtual void getIntersection(Ray ray) const;

    // set material and medium to nullptr
    // set transform to identity
    ObjectBase();
};
