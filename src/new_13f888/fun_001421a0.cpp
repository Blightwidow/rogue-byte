#include "types.h"

extern "C" {
void Carry_Attach(s32, s32);
void Carry_Detach(s32);
void SetJtAttach5(s32, s32);

void func_001421A0(s32 arg0, s32 arg1) {
    SetJtAttach5(arg0, 0);
    if (arg1 != 0) {
        Carry_Attach(arg0 + 0x900, arg1);
        return;
    }
    Carry_Detach(arg0 + 0x900);
}

}
