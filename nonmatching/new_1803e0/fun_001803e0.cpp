typedef signed char s8;
typedef int s32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s32 FIsBasicDerivedFrom(s32, s32);
void func_0017F1A0(s8 *, s32, s32);
void func_0017F5B0(s8 *, s32);
}
extern "C" void func_001803E0(s8 *arg0, s8 *arg1, s32 arg2)
{
    func_0017F1A0(arg0, (s32)arg1, arg2);
    s32 temp = M2C_FIELD((s8 *)arg1 + ((1 - arg2) << 6), s32 *, 0xC);
    if (FIsBasicDerivedFrom(temp, 0x47) == 0 && M2C_FIELD(arg0, s32 *, 0x1CC) != 0) {
        goto setOne;
    }
    func_0017F5B0(arg0, temp);
    if (M2C_FIELD(arg0, s32 *, 0x1CC) == 0) {
        return;
    }
setOne:
    M2C_FIELD(arg1, float *, 0x98) = 1.0f;
}
