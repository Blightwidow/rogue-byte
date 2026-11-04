typedef signed char s8;
typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
float SMinCrv(s8 *);
float SMaxCrv(s8 *);
}
extern "C" void bevy_player_p14_19e110(s8 *arg0, float *arg1)
{
    s8 *obj = M2C_FIELD(arg0, s8 **, 0xC);
    if (M2C_FIELD(obj, s32 *, 0xE4) != 0) {
        arg1[0] = -3.402823466e+38f;
        arg1[1] = 3.402823466e+38f;
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x18) != 0) {
        arg1[0] = SMinCrv(obj) + 35.0f;
        arg1[1] = SMaxCrv(M2C_FIELD(arg0, s8 **, 0xC)) - 100.0f;
    } else {
        arg1[0] = SMinCrv(obj) + 100.0f;
        arg1[1] = SMaxCrv(M2C_FIELD(arg0, s8 **, 0xC)) - 35.0f;
    }
}
