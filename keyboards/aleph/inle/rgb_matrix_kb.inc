RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// red
#define VILE_COUNT 4
HSV VILE[VILE_COUNT] = {
	{20,120,255},
	{250,105,255}, 
	{229,152,255},
	{160,255,230},
};


static HSV my_cool_effect_math(HSV hsv, uint8_t i, uint8_t time) {
    HSV tmp;

    switch(i) {
    	case 7:
    	case 10:
    	case 13:
    	case 15:
    		tmp = VILE[2];
    		break; 
    	case 11:
    	case 14:
    	case 16:
    	case 17:
    	case 19:
    		tmp = VILE[1];
    		break;
    	case 18:
    	case 20:
    		tmp = VILE[0];
    		break;

    	default:
    		tmp = VILE[3];
    		break;
    }

    hsv.v  = scale8(abs8(sin8(time) - 128) * 2, hsv.v);
    hsv.h = tmp.h;
    hsv.s = tmp.s;
    return hsv;
}

static HSV my_cool_effect_math2(HSV hsv, uint8_t i, uint8_t time) {
    return my_cool_effect_math(hsv, i, 180);
}

bool my_cool_effect(effect_params_t* params) { return effect_runner_i(params, &my_cool_effect_math); }
bool my_cool_effect2(effect_params_t* params) { return effect_runner_i(params, &my_cool_effect_math2); }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS