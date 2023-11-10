#pragma once

#include "scene.h"
#include "intersector.h"
#include "texture.h"

struct IntegratorConfig {
    int lightPathDepth = 12;
    bool useIS = true;
    bool useDLS = true;
    int minSample = 0;
    int maxSample = 4096;
    float noiseThreshold = -1.0;
};

class Integrator {
    Texture<Spectrum> accumulationBuffer;
    Texture<Spectrum> accumulationBufferVariance;  // or moment
public:
    IntegratorConfig config;
    Scene *scene;
    Intersector *intersector;

    // set buffers to zero
    Integrator(IntegratorConfig config, Scene *scene = nullptr);

    // assume scene is modified, update intersector
    void updateIntersector();

    // set buffers to zero
    void clearBuffer();

    // render the image once, add to buffers
    void render(int spp);

    // get image texture
    Texture<Spectrum> getImage() const;
};
