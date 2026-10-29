typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void RecalcSwOxfFilterForObject(void *, s8 *);
extern s32 B_003DD490;
void func_001F6918(s8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s64 *, 0x148) = (M2C_FIELD(arg0, s64 *, 0x148) & ~(1L << 26)) | ((s64)(arg1 & 1) << 26);
    RecalcSwOxfFilterForObject(&B_003DD490, arg0);
}
}
