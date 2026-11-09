#include "types.h"
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void BuildAllDrawEnvGifs();
s32 FlushSaaUnpacks();
void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(s32, s32);
extern s32 g_2de594;
extern s32 g_2de598;

void RenderFrame__FP3FRMi(void *arg0, s32 arg1) {
    FlushSaaUnpacks();
    BuildAllDrawEnvGifs();
    SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de594, M2C_FIELD(arg0, s32 *, 0x24));
    if (arg1 != 0) {
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, M2C_FIELD(arg0, s32 *, 4));
    }
}

}
