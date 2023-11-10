#pragma once

#include "ray.h"
#include "object_mesh.h"
#include "intersection.h"

class Bvh {
public:
    // to-do

    Bvh(ObjectMesh mesh);
    ~Bvh();

    Intersection getIntersection(Ray) const;
};
