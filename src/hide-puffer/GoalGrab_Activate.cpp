typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
void ClearGuardPathMode(s8 *);
void GoalAnimLeap_SetState(s8 *, M2C_UNK);
void func_00154038(s32, s32, M2C_UNK);
void func_00174950();
void func_001EEFC0(s8 *);
void func_0020AB68(s8 *, M2C_UNK, M2C_UNK, s128);
extern s128 g_2a2dd0;

void GoalGrab_Activate(s8 *arg0) {
    func_00174950();
    func_0020AB68(M2C_FIELD(arg0, s8 **, 0x10), 0, 0, g_2a2dd0);
    ClearGuardPathMode(M2C_FIELD(arg0, s8 **, 0x10));
    GoalAnimLeap_SetState(arg0, 0);
    func_001EEFC0(arg0);
    func_00154038(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x10), s32 *, 0xF64), M2C_FIELD(arg0, s32 *, 0x5C), 2);
}

}
