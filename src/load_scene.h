#pragma once

#include <string>

#include "scene.h"
#include "integrator.h"

typedef struct {
    Scene scene;
    IntegratorConfig integratorConfig;
} SceneFile;

SceneFile loadScene(std::string filename);

