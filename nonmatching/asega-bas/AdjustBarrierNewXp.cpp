typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_AdjustBarrierNewXp {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 PrefFindBinding__6CFrameUii(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, s32 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F4FB0();                            /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A4797;
void AdjustBarrierNewXp(s32 *arg0) {
    s32 temp_a0;
    func_001F4FB0();
    temp_a0 = *arg0;
    if ((temp_a0 != 0) && (PrefFindBinding__6CFrameUii(temp_a0, 5, 1) != 0)) {
        s32 vu_1;
        asm volatile("ldl %0, %%lo(RO_002A4797)(%1)" : "=r"(vu_1) : "r"(&RO_002A4797));
        s32 vu_2;
        asm volatile("ldr %0, %%lo(RO_002A4790)(%1)" : "=r"(vu_2) : "r"(&RO_002A4797), "0"(vu_1));
        QueueSwCallbackOnce(&B_003DD490, arg0, vu_2, 0);
    }
}
}
