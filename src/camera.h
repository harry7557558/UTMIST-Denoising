#pragma once

#include "transform.h"
#include "ray.h"

class Camera {
public:
    // tentative parameters
    // let us know if you find better parameters
    vec3 position;
    mat3 orientation;
    int imageWidth;
    int imageHeight;
    float fov;
    float imageDist;
    float exposure;

    // depth of field
    float focalLength;
    float apertureSize;

    // motion blur
    vec3 velocity;
    float exposureTime;

    // To-do
    Camera();

    // pixel should be integer
    Ray getRandomRay(vec2 pixel) const;

};
