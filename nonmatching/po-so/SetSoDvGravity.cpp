typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetSoDvGravity {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK SetXfKind(s8 *, M2C_UNK);                 /* extern */
M2C_UNK func_001F5078(s8 *);                      /* extern */
void SetSoDvGravity(s8 *arg0, s32 arg1) {
    s128 temp_s1;
    s8 *temp_a1;
    s128 vu_1;
    asm volatile("por %0, %1, %2" : "=r"(vu_1) : "r"(0), "r"(arg1));
    temp_s1 = vu_1;
    if (M2C_FIELD(arg0, s8 **, 0xE8) != NULL) {
        temp_a1 = M2C_FIELD(arg0, s8 **, 0x58);
        if ((M2C_FIELD(temp_a1, s32 *, 0x90) == 0) && (M2C_FIELD(temp_a1, s16 *, 0x98) != 2)) {
            SetXfKind(temp_a1, 1);
        }
        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), s128 *, 0x80) = temp_s1;
        func_001F5078(arg0);
    }
}
}
