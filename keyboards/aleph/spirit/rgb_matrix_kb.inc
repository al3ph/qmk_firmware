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
    	case 18:
    	case 19:
    	case 20:
    	case 21:
    	case 22:
    	case 23:
    	case 24:
    	case 25:
    	case 46:
    	case 47:
    	case 48:
    	case 49:
    	case 50:
    	case 74:
    	case 75:
    	case 76:
    	case 77:
    		tmp = VILE[0];
    		break; 
    	case 17:
    	case 26:
    	case 27:
    	case 44:
    	case 45:
    	case 51:
    	case 52:
    	case 72:
    	case 73:
    	case 78:
    		tmp = VILE[1];
    		break;
    	case 16:
    	case 28:
    	case 43:
    	case 53:
    	case 71:
    		tmp = VILE[2];
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