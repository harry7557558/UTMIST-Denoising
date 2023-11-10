#pragma once

#include <vector>
#include <string>

#include "object_base.h"

class ObjectMesh : ObjectBase {
public:
    std::vector<vec3> vertices;
    std::vector<ivec3> triangles;
    std::vector<vec2> texcoords;  // same size as vertices

    // set all vectors to empty
    ObjectMesh();

    // should support OBJ, PLY, and STL, preferably without dependency
    // file formats can be found on Google
    // duplicate vertices in STL should be merged
    // example model writer (not reader): https://github.com/harry7557558/Graphics/blob/master/modeling/img23d/write_model.h
    // set texcoords to empty if not defined
    ObjectMesh(std::string filename);

    // apply transform to each vertex
    void applyTransform();

    // should not be called, assert failure
    void getIntersection(Ray) const;
};
