#pragma once

#include <vector>

#include "object_base.h"
#include "light.h"
#include "camera.h"

class Scene {
public:
    std::vector<ObjectBase> objects;
    std::vector<Light> lights;
    Camera camera;
};

