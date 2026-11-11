#include "types.h"
extern "C" {
s32 func_00213928(s32, s32);
s32 func_00213B00(s32, s32);

void SwitchBlotLabel(s32 arg0, s32 arg1, s32 *arg2) {
    s32 temp_v0;

    temp_v0 = *arg2;
    if (arg1 != temp_v0) {
        if (temp_v0 != -1) {
            func_00213928(arg0, temp_v0);
        }
        *arg2 = arg1;
        if (arg1 != -1) {
            func_00213B00(arg0, arg1);
        }
    }
}

}
