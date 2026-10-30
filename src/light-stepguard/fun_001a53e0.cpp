extern "C" {
#include "m2c_macros.h"
extern char B_003DD4BC;
s32 FFindDlEntry(void *, s32);
void RemoveDlEntry(void *, s32);
void RemoveSwRoot(void *, s32);
void FreeSlotheapPv(void *, s32);

void func_001A53E0(void *arg0) {
    char *base = &B_003DD4BC;
    if (FFindDlEntry(base, M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
        RemoveDlEntry(base, M2C_FIELD(arg0, s32 *, 0x14));
    }
    RemoveSwRoot(base - 0x2C, M2C_FIELD(arg0, s32 *, 0x14));
    FreeSlotheapPv(base + 0x3960, M2C_FIELD(arg0, s32 *, 0x14));
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}

}
