typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
s32 GoalFollowCrv_FAtEnd(s8 *);
}
extern "C" {
void OnPoActive();
void RetractAsegaHandle(s8 *);

void JT_OnPoActive(s8 *arg0, s32 arg1) {
    s8 *temp_v0;

    OnPoActive();
    temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
    ((void (*)(s8 *))M2C_FIELD(temp_v0, void **, 0x34C))(arg0 + M2C_FIELD(temp_v0, s16 *, 0x348));
    if (arg1 == 0) {
        RetractAsegaHandle(arg0 + 0x1310);
        M2C_FIELD(arg0, s32 *, 0x1314) = -1;
    }
}

}
