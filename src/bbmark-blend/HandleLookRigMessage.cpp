typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
extern "C" {
void func_00131B10(s32, void *, s32);

void HandleLookRigMessage(void *arg0, s32 arg1, void *arg2) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_a1;

    if ((arg1 == 9) && (temp_a0 = M2C_FIELD(arg2, s32 *, 0), (temp_a0 == M2C_FIELD(arg0, s32 *, 0xE0)))) {
        temp_a2 = M2C_FIELD(arg2, s32 *, 8);
        switch (temp_a2) {                          /* irregular */
        case 0x16E:
            temp_a1 = M2C_FIELD(arg0, void **, 0);
            func_00131B10(temp_a0, temp_a1, M2C_FIELD(temp_a1, s32 *, 0x10B8));
            M2C_FIELD(arg0, s32 *, 0x10) = 1;
            return;
        case 0x242:
            M2C_FIELD(arg0, s32 *, 0xC) = 1;
            break;
        }
    }
}

}
