typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefGetSaveValue {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x48];
};                                                  /* size = 0x60 */
#define sp14 (*(s32 *)(sp + 0x14))
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK CRef_SetBool(...);        /* extern */
M2C_UNK CRef_SetClqPtr(s8 *, s8 *);             /* extern */
M2C_UNK CRef_SetF32(s8 *, s8 *, f32);           /* extern */
M2C_UNK CRef_SetLmPtr(s8 *, s8 *);              /* extern */
M2C_UNK CRef_SetS32(s8 *, s32);                   /* extern */
M2C_UNK CRef_SetSmpPtr(s8 *, s8 *);             /* extern */
M2C_UNK CRef_SetVectorPtr(s8 *, s8 *);          /* extern */
s32 FFindSaveVar(s32, s32, s8 **, s32);           /* extern */
s32 RefGetSaveValue(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *sp10;
    s32 *temp_t0;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_v0;
    s8 temp_a0;
    if (FFindSaveVar(arg1, arg2, &sp10, -1) != 0) {
        temp_a0 = M2C_FIELD(sp10, s8 *, 2);
        if (temp_a0 != -1) {
            temp_t0 = (s32 *)(arg3 + M2C_FIELD(sp10, u16 *, 4));
            switch (temp_a0) {
            case 0:
            case 1:
            case 2:
            case 10:
                CRef_SetS32(sp, *((sp14 * 4) + temp_t0));
                break;
            case 3:
                CRef_SetF32(sp, sp10, *((sp14 * 4) + temp_t0));
                break;
            case 4:
                if (M2C_FIELD(sp10, u8 *, 3) != 0) {
                    temp_v0 = (s32) ((sp14 > -1) ? sp14 : (sp14 + 7)) >> 3;
                    temp_a2 = sp14 - (temp_v0 * 8);
                    temp_a3 = (1 << temp_a2) & 0xFF;
                    CRef_SetBool(arg0, arg1, sp, (*(temp_t0 + temp_v0) & temp_a3) != 0, temp_a2, temp_a3);
                } else {
                    CRef_SetBool(arg0, arg1, sp, *temp_t0, sp14);
                }
                break;
            case 5:
                CRef_SetVectorPtr(sp, (s8 *)(temp_t0 + (sp14 * 0x10)));
                break;
            case 6:
                CRef_SetClqPtr(sp, (s8 *)(temp_t0 + (sp14 * 0x10)));
                break;
            case 7:
                CRef_SetLmPtr(sp, (s8 *)(temp_t0 + (sp14 * 8)));
                break;
            case 8:
                CRef_SetSmpPtr(sp, (s8 *)((sp14 * 0xC) + temp_t0));
                break;
            case 9:
                CRef_SetS32(sp, *((sp14 * 4) + temp_t0));
                break;
            }
            CRef_CopyConstruct(arg0, sp);
            CRef_Destruct(sp);
        } else {
            goto block_4;
        }
    } else {
block_4:
        CRef_CopyConstruct(arg0, sp);
        CRef_Destruct(sp);
    }
    return arg0;
}
}
