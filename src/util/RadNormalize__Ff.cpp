#include "types.h"
extern "C" {
f32 GModPositive__Fff(f32, f32);

f32 RadNormalize__Ff(f32 angle) {
    if ((angle < -3.1415927f) || (angle > 3.1415927f)) {
        angle = GModPositive__Fff(angle + 3.1415927f, 6.2831855f) - 3.1415927f;
    }
    return angle;
}

}
