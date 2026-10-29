typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern "C" {
void AddPrimList__4GIFSiUl(s8 *arg0, s32 arg1, u64 arg2) {
    s8 *temp_v1;
    s8 *temp_v1_2;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x18);
    M2C_FIELD(temp_v1, void (**)(s8 *, s32), 0xC)(arg0 + M2C_FIELD(temp_v1, s16 *, 8), 0);
    temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
    M2C_FIELD(arg0, s8 **, 0xC) = (s8 *) (temp_v1_2 + 0x10);
    M2C_FIELD(temp_v1_2, u64 *, 8) = arg2;
    M2C_FIELD(temp_v1_2, u64 *, 0) = ((u64)arg1 << 0x3C) | ((u64)0x8000 << 0x2B);
    M2C_FIELD(arg0, s32 *, 0x20) = arg1;
    M2C_FIELD(arg0, s8 **, 0x1C) = temp_v1_2;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
}
}
