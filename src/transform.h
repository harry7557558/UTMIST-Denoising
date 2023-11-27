#pragma once

#include "glm/glm/geometric.hpp"
#include "glm/glm/glm.hpp"

using glm::clamp; using glm::mix; using glm::sign;
using glm::vec2; using glm::vec3; using glm::vec4;
using glm::dot; using glm::cross; using glm::outerProduct;
using glm::mat2; using glm::mat3; using glm::mat4;
using glm::mat2x3; using glm::mat3x2; using glm::mat4x3;
using glm::inverse; using glm::transpose; using glm::determinant; using glm::normalize;
using glm::ivec2; using glm::ivec3; using glm::ivec4;
using glm::radians;

// camera
mat4 getTransform(
    vec3 position, vec3 lookat,
    float roll_degrees, float fov,
    float far = 1.0, float near = 0.01
) {
    float roll = radians(roll_degrees);
    float scale = 1.0 / tan(fov / 2.0);
    vec3 forward = normalize(lookat - position);
    vec3 original_up(0.0, 0.0, 1.0);
    vec3 right = normalize(cross(original_up, forward));
    vec3 up = -normalize(cross(forward, right));
    mat4 rotation(
        vec4(right, 0.0),
        vec4(up, 0.0),
        vec4(-forward, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );
    mat4 translation(
        vec4(1.0, 0.0, 0.0, 0.0),
        vec4(0.0, 1.0, 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(-position, 1.0)
    );
    mat4 rollMatrix(
        vec4(cos(roll), -sin(roll), 0.0, 0.0),
        vec4(sin(roll), cos(roll), 0.0, 0.0),
        vec4(0.0, 0.0, 1.0, 0.0),
        vec4(0.0, 0.0, 0.0, 1.0)
    );
    mat4 perspective(
        vec4(scale, 0.0, 0.0, 0.0),
        vec4(0.0, scale, 0.0, 0.0),
        vec4(0.0, 0.0, -(far + near) / (far - near), -1.0),
        vec4(0.0, 0.0, -2 * far * near / (far - near), 0.0)
    );
    return perspective * rotation * rollMatrix * translation;
}

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
vec3 applyTransform(mat4 m, vec3 r) {
    vec4 r4(r, 1.0);
    vec4 unscaled = m * r4;
    vec3 scaled = vec3(unscaled) / unscaled.w;
    return scaled;
}

// apply inverse transform to vector
vec3 applyInverseTransform(mat4 m, vec3 r) {
    return applyTransform(inverse(m), r);
}
