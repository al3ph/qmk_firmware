RGB_MATRIX_EFFECT(my_cool_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV my_cool_effect_math(HSV hsv, int16_t dx, int16_t dy, uint8_t time) {
    hsv.h = atan2_8(dy, dx) + time;
    return hsv;
}

bool my_cool_effect(effect_params_t* params) { return effect_runner_dx_dy(params, &my_cool_effect_math); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS