#include "m2c_macros.h"

void AddVifStrow__4VIFSP2QW(void *arg0, void *arg1) {
    s32 *temp_a2;
    s32 *temp_a2_2;
    s32 *temp_a3;
    s32 *temp_a3_2;
    s32 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_v1 + 4);
    *temp_v1 = 0x30000000;
    temp_a2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a2 + 4);
    *temp_a2 = M2C_FIELD(arg1, s32 *, 0);
    temp_a3 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a3 + 4);
    *temp_a3 = M2C_FIELD(arg1, s32 *, 4);
    temp_a2_2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a2_2 + 4);
    *temp_a2_2 = M2C_FIELD(arg1, s32 *, 8);
    temp_a3_2 = M2C_FIELD(arg0, s32 **, 0xC);
    M2C_FIELD(arg0, s32 **, 0xC) = (s32 *) (temp_a3_2 + 4);
    *temp_a3_2 = M2C_FIELD(arg1, s32 *, 0xC);
}
