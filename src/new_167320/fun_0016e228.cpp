#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
extern char D_00003AB0[];
M2C_UNK AddDmaCnt__4DMAS();
M2C_UNK AddVifFlusha__4VIFS(s32);
M2C_UNK AddVifMscal__4VIFSPv(s32, void *);
M2C_UNK EndDmaCnt__4DMAS(s32);
M2C_UNK UnpackHelper__4VIFS3UPKiiPiPPUi(s32, s32, s32, s32, s32, void *);
M2C_UNK memset(void *, s32, s32);
void func_0016E228(s32 arg0) {
    void *buffer;
    AddDmaCnt__4DMAS();
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 0xD, 0xB, 0xA, 0, &buffer);
    memset(buffer, 0, 0x58);
    AddVifMscal__4VIFSPv(arg0, D_00003AB0);
    AddVifFlusha__4VIFS(arg0);
    EndDmaCnt__4DMAS(arg0);
}
}
