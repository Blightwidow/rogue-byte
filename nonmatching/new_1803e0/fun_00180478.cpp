typedef signed char s8;
typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void RecalcSwOxfFilterForObject(char *, s8 *);
extern char B_003DD490[];
extern float g_2a5654;
extern float g_2dded0;
}
extern "C" void func_00180478(s8 *arg0, s32 arg1)
{
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x1C8)) {
        M2C_FIELD(arg0, s32 *, 0x1C8) = arg1;
        s8 *owner = M2C_FIELD(arg0, s8 **, 0xEC);
        if (M2C_FIELD(owner, s8 **, 0x60) == arg0) {
            RecalcSwOxfFilterForObject(B_003DD490, arg0);
        }
    }
    float frac = M2C_FIELD(arg0, float *, 0x1C4);
    float result;
    if (frac != 0.0f) {
        result = g_2dded0 + frac;
    } else {
        result = g_2a5654;
    }
    M2C_FIELD(arg0, float *, 0x1C0) = result;
}
