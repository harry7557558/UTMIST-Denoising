#pragma once

#include "material_base.h"
#include "texture.h"

class MaterialMix : MaterialBase {
public:

    MaterialBase *mat1;
    MaterialBase *mat2;
    Texture<float> t;  // linear interpolation parameter

    // evaluate the BSDF
    void getBSDF(vec3 wi, vec3 wo, Spectrum &bsdf) const;

    // importance sampling
    void getSample(vec3 wi, vec3 &wo, Spectrum &weight) const;

};
