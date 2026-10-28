#include "m2c_macros.h"

f32 atan2f(f32, f32);                               /* extern */

void GetJtHangHeading__FP2JTPf(void *arg0, f32 *arg1) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_2;

    temp_a1 = M2C_FIELD(arg0, void **, 0x18C4);
    temp_v1 = M2C_FIELD(temp_a1, void **, 0xC);
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x18C4);
    temp_s1 = M2C_FIELD(temp_v1, void *(**)(void *, void *), 0xFC)(temp_a1 + M2C_FIELD(temp_v1, s16 *, 0xF8), temp_a1);
    temp_v1_2 = M2C_FIELD(temp_a1_2, void **, 0xC);
    *arg1 = atan2f(M2C_FIELD(temp_s1, f32 *, 4), *M2C_FIELD(temp_v1_2, f32 *(**)(void *, void *), 0xFC)(temp_a1_2 + M2C_FIELD(temp_v1_2, s16 *, 0xF8), temp_a1_2));
}
