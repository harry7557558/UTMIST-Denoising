#pragma once

#include "bvh.h"
#include "scene.h"

class Intersector {
    std::vector<Bvh*> bvhs;
public:

    Intersector(Scene scene);
    ~Intersector();

    Intersection getIntersection(Ray) const;
};
