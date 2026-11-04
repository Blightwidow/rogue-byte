typedef signed char s8;
typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" void LoadXfmFromBrx(s8 *);
extern "C" void func_002035A8(s8 *arg0)
{
    M2C_FIELD(arg0, s32 *, 0xE4) = 0;
    M2C_FIELD(arg0, float *, 0xE0) = 75.0f;
    M2C_FIELD(arg0, float *, 0xE8) = 0.25f;
    M2C_FIELD(arg0, float *, 0x104) = 5000.0f;
    LoadXfmFromBrx(arg0);
    if (M2C_FIELD(arg0, float *, 0xE4) == 0.0f) {
        M2C_FIELD(arg0, float *, 0xE4) = M2C_FIELD(arg0, float *, 0xE0);
    }
    if (M2C_FIELD(arg0, s32 *, 0xF8) == -2) {
        M2C_FIELD(arg0, s32 *, 0xF8) = M2C_FIELD(arg0, s32 *, 0xF4);
    }
}
