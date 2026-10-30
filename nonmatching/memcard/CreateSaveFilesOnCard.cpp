typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_CreateSaveFilesOnCard {
    /* 0x00 */ char pad0[0x50];
    /* 0x50 */ s32 sp50;                            /* inferred */
    /* 0x54 */ char pad54[0x5C];
};                                                  /* size = 0xB0 */
M2C_UNK BuildSlotFilePath(s8 *, s8 *, M2C_UNK *); /* extern */
s32 CreateSaveDirectory(s8 *, s32);               /* extern */
M2C_UNK DeleteMemcardFile(s8 *, M2C_UNK *);       /* extern */
s32 FUN_0018c1e8(M2C_UNK *);                        /* extern */
s32 InitAndWriteSaveSlot(s8 *, s8 *);           /* extern */
s32 McSync(s32, s32, M2C_UNK, s32 *);               /* extern */
M2C_UNK func_001ACC38(M2C_UNK *, M2C_UNK);          /* extern */
s32 sceMcGetEntSpace(s32, s32, M2C_UNK *);          /* extern */
extern M2C_UNK B_002E6550;
extern M2C_UNK RO_002A38E8;
extern M2C_UNK RO_002A6BB0;
extern M2C_UNK RO_002A6BC8;
s32 CreateSaveFilesOnCard(s8 *arg0) {
    s8 sp[0x40] __attribute__((aligned(16)));
    s32 sp50;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_v0;
    s8 *temp_a1_2;
    s8 *var_s0;
    var_s3 = McSync((int)(arg0 + 0xFD5C), sceMcGetEntSpace(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), (M2C_UNK *)("/")), 0x12, &sp50);
    if (var_s3 == 0) {
        temp_v0 = FUN_0018c1e8(&RO_002A38E8);
        temp_a1 = temp_v0 + 0x3FF;
        var_s3 = 1;
        if (M2C_FIELD(arg0, s32 *, 0x1C) >= (((sp50 == 0) ? 2 : 1) + 5 + ((s32) ((temp_a1 > -1) ? temp_a1 : (temp_v0 + 0x7FE)) >> 0xA) + 0x42)) {
            var_s3 = CreateSaveDirectory(arg0, temp_a1);
            var_s0 = arg0 + 0x24;
            if (var_s3 == 0) {
                var_s2 = 0;
loop_4:
                var_s3 = InitAndWriteSaveSlot(arg0, var_s0);
                var_s2 += 1;
                if (var_s3 == 0) {
                    var_s0 += 0x5464;
                    if (var_s2 >= 3) {
                        if (M2C_FIELD(arg0, s32 *, 0xC) < 5) {
                            M2C_FIELD(arg0, s32 *, 0xC) = 5;
                        }
                        goto block_14;
                    }
                    goto loop_4;
                }
                var_s0 = arg0 + 0x24;
                goto block_9;
            }
block_9:
            var_s2_2 = 2;
            do {
                temp_a1_2 = var_s0;
                var_s0 += 0x5464;
                BuildSlotFilePath(arg0, temp_a1_2, (M2C_UNK *)(sp));
                var_s2_2 -= 1;
                DeleteMemcardFile(arg0, (M2C_UNK *)(sp));
            } while (var_s2_2 >= 0);
            DeleteMemcardFile(arg0, (M2C_UNK *)("/BASCUS-97316YAOTWTD!/icon.sys"));
            DeleteMemcardFile(arg0, (M2C_UNK *)("/BASCUS-97316YAOTWTD!/memcard_icon.ico"));
            DeleteMemcardFile(arg0, &RO_002A6BC8);
            DeleteMemcardFile(arg0, &RO_002A6BB0);
            goto block_12;
        }
block_12:
        var_v0 = var_s3;
        if (var_s3 != 0) {
            goto block_13;
        }
    } else {
block_13:
        func_001ACC38(&B_002E6550, 3);
block_14:
        var_v0 = var_s3;
    }
    return var_v0;
}
}
