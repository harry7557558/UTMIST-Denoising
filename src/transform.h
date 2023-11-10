#pragma once

#include "glm/glm/glm.hpp"

using glm::clamp; using glm::mix; using glm::sign;
using glm::vec2; using glm::vec3; using glm::vec4;
using glm::dot; using glm::cross; using glm::outerProduct;
using glm::mat2; using glm::mat3; using glm::mat4;
using glm::mat2x3; using glm::mat3x2; using glm::mat4x3;
using glm::inverse; using glm::transpose; using glm::determinant;
using glm::ivec2; using glm::ivec3; using glm::ivec4;

// camera
mat4 getTransform(
    vec3 position, vec3 lookat,
    float roll, float fov
);

// euler angle + translation
mat4 getTransform(
    float rx, float ry, float rz,
    vec3 translate = vec3(0.0)
);

// quaternion + translation
mat4 getTransform(
    glm::quat q,
    vec3 translate = vec3(0.0)
);

// apply transform to vector
vec3 applyTransform(mat4 m, vec3 r);

// apply inverse transform to vector
vec3 applyInterseTransform(mat4 m, vec3 r);

