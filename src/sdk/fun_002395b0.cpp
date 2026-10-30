typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
extern "C" {
void RFU116_SetSyscall(s32, s32);
s32 func_00239598(s32, s32, void *);
extern u32 D_002C4AA0;
extern s32 D_002C4AA8[];
extern char func_00239558[];
extern char func_00239518[];
void func_002395B0(void) {
    s32 var_s2;
    s32 var_s3;
    u32 var_s0;
    u32 var_s1;
    RFU116_SetSyscall(D_002C4AA8[0], D_002C4AA8[1]);
    RFU116_SetSyscall(D_002C4AA8[2], D_002C4AA8[3]);
    var_s3 = func_00239598(0x80000000, 0x80080000, func_00239558);
    var_s1 = var_s3 - 0x20C;
    var_s2 = func_00239598(0x80000000, 0x80080000, (func_00239518 + 8));
    var_s0 = var_s2 - 0x168;
    while (var_s1 != var_s0) {
        if (var_s1 < var_s0) {
            var_s3 = func_00239598(var_s3 + 4, 0x80080000, func_00239558);
            var_s1 = var_s3 - 0x20C;
        } else {
            var_s2 = func_00239598(var_s2 + 4, 0x80080000, (func_00239518 + 8));
            var_s0 = var_s2 - 0x168;
        }
    }
    D_002C4AA0 = var_s1;
}
}
