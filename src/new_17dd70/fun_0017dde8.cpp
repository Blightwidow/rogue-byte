typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void Goal_Deactivate();
void RemoveGuardSgs(void *, M2C_UNK);
s32 ResetSensorStates(s32);
void func_0017E278(void *, M2C_UNK);
void func_00208540(void *, M2C_UNK);

void func_0017DDE8(void *arg0) {
    Goal_Deactivate();
    func_0017E278(arg0, -1);
    ResetSensorStates(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF64));
    func_00208540(M2C_FIELD(arg0, void **, 0x10), 0);
    RemoveGuardSgs(M2C_FIELD(arg0, void **, 0x10), 0x2B);
}

}
