RGB_MATRIX_EFFECT(my_cool_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
// we know the i values for each key so build a lookup to set values..
// define the colours for each colour way..

HSV w(255,255,255);

static HSV my_cool_effect_math(HSV hsv, uint8_t i, uint8_t time) {
    return w;
}

bool my_cool_effect(effect_params_t* params) { return effect_runner_i(params, &my_cool_effect_math); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
