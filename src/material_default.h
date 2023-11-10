#pragma once

#include "material_base.h"
#include "texture.h"

// Cook-Torrance like material

class MaterialDefault : MaterialBase {
public:

    // albedo color
    Texture<Spectrum> albedo;

    // diffuse component
    Texture<float>  diffuse;

    // GGX
    Texture<float> roughness;

    // linear interpolate between opaque and refractive
    float opacity;

    // ratio of object to environment index of refraction
    float ior;

    // isotropic emission
    Texture<Spectrum> emission;

    // evaluate the bsdf, assume n is in positive z direction
    void getBSDF(vec3 wi, vec3 wo, Spectrum &bsdf) const;

    // importance sampling
    void getSample(vec3 wi, vec3 &wo, Spectrum &weight) const;

};
