RGB_MATRIX_EFFECT(my_cool_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// red
#define VILE_COUNT 4
HSV VILE[VILE_COUNT] = {
	{20,120,255},
	{250,125,255}, 
	{239,112,255},
	{143,255,255},
};

static HSV my_cool_effect_math(HSV hsv, uint8_t i, uint8_t time) {
    HSV  tmp = VILE[i%VILE_COUNT];
    hsv.v  = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    hsv.h = tmp.h;
    hsv.s = tmp.s;
    return hsv;
}

bool my_cool_effect(effect_params_t* params) { return effect_runner_i(params, &my_cool_effect_math); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS