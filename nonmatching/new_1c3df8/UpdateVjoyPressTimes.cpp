typedef signed char s8;
typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
extern float g_2dded0;
}
extern "C" void UpdateVjoyPressTimes(s8 *arg0)
{
    s32 grfbtnOld = M2C_FIELD(arg0, s32 *, 0x78);
    s32 grfbtnNew = M2C_FIELD(arg0, s32 *, 0x30);
    float timeNow = g_2dded0;
    s32 grfbtnPressed = grfbtnNew & ~grfbtnOld;
    M2C_FIELD(arg0, s32 *, 0x78) = grfbtnNew;
    if (grfbtnPressed != 0) {
        float *pTimes = (float *)(arg0 + 0x88);
        do {
            if (grfbtnPressed & 1) {
                *pTimes = timeNow;
            }
            grfbtnPressed >>= 1;
            pTimes++;
        } while (grfbtnPressed != 0);
    }
    float stickFloat0 = M2C_FIELD(arg0, float *, 0x1C);
    s32 indexLeft = 0;
    if (0.0f < stickFloat0) {
        indexLeft = 4;
    }
    s8 *pLeftSlot = arg0 + 0xC8;
    *(float *)(pLeftSlot + indexLeft) = timeNow;
    float stickFloat1 = M2C_FIELD(arg0, float *, 0x2C);
    s32 indexRight = 0;
    if (0.0f < stickFloat1) {
        indexRight = 4;
    }
    s8 *pRightSlot = arg0 + 0xD0;
    *(float *)(pRightSlot + indexRight) = timeNow;
}
