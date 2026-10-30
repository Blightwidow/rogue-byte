typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00165280 {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s8 *sp14;                          /* inferred */
    /* 0x18 */ s32 sp18;                            /* inferred */
    /* 0x1C */ s32 sp1C;                            /* inferred */
    /* 0x20 */ s8 *sp20;                          /* inferred */
    /* 0x24 */ s8 *sp24;                          /* inferred */
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ s32 sp2C;                            /* inferred */
    /* 0x30 */ s8 *sp30;                          /* inferred */
    /* 0x34 */ s32 sp34;                            /* inferred */
    /* 0x38 */ char pad38[8];                       /* maybe part of sp34[3]? */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ s32 sp44;                            /* inferred */
    /* 0x48 */ char pad48[0x58];
};                                                  /* size = 0xA0 */
M2C_UNK ApplyTaskState(s8 *, M2C_UNK);            /* extern */
M2C_UNK CRef_Destruct(s8 **);                     /* extern */
M2C_UNK CStackFrame_Construct(s8 *);              /* extern */
M2C_UNK CStackFrame_Destructor(s8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK OrderTasks(s32 *, s32 *);                   /* extern */
s8 *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK RestoreTaskStateFromSave(s8 *);           /* extern */
M2C_UNK SetTaskState(s8 *, M2C_UNK);              /* extern */
M2C_UNK func_001D8B20(s8 **, s8 **, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A5238;
void func_00165280(s8 *arg0) {
    s8 sp[0xA0] __attribute__((aligned(16)));
    s8 *sp10;
    s8 *sp14;
    s32 sp18;
    s32 sp1C;
    s8 *sp20;
    s8 *sp24;
    s32 sp28;
    s32 sp2C;
    s8 *sp30;
    s32 sp34;
    s32 sp40;
    s32 sp44;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s8 *temp_a0;
    s8 *temp_a0_2;
    s8 *temp_v0;
    if (M2C_FIELD(&B_003DD490, s32 *, 0x3BF4) & 8) {
        var_s0 = 0;
        CStackFrame_Construct(sp);
        OrderTasks(&sp40, &sp44);
        if (sp40 > 0) {
            do {
                temp_a0 = (s8 *)(*(s32 *)((var_s0 * 4) + sp44));
                sp10 = NULL;
                sp14 = temp_a0;
                if (temp_a0 != NULL) {
                    sp18 = M2C_FIELD(temp_a0, s32 *, 0xF4);
                    M2C_FIELD(temp_a0, s32 *, 0xF4) = 3;
                    sp1C = M2C_FIELD(sp14, s32 *, 0xF8);
                    M2C_FIELD(sp14, s32 *, 0xF8) = 0;
                }
                RestoreTaskStateFromSave(temp_a0);
                if (sp10 != NULL) {
                    M2C_FIELD(sp10, s32 *, 0xF0) = sp18;
                    M2C_FIELD(sp10, s32 *, 0xF4) = sp1C;
                }
                if (sp14 != NULL) {
                    M2C_FIELD(sp14, s32 *, 0xF4) = sp18;
                    M2C_FIELD(sp14, s32 *, 0xF8) = sp1C;
                }
                var_s0 += 1;
            } while (var_s0 < sp40);
        }
        temp_v0 = PloFindSwObject_thunk(&B_003DD490, 0x105, M2C_FIELD(arg0, s32 *, 0x18), 0);
        M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(temp_v0, s8 **, 0x7C), s32 *, 0x18);
        sp10 = NULL;
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(temp_v0, s32 *, 0x18);
        sp14 = temp_v0;
        if (temp_v0 != NULL) {
            sp18 = M2C_FIELD(temp_v0, s32 *, 0xF4);
            M2C_FIELD(temp_v0, s32 *, 0xF4) = 3;
            sp1C = M2C_FIELD(sp14, s32 *, 0xF8);
            M2C_FIELD(sp14, s32 *, 0xF8) = 0;
        }
        SetTaskState(temp_v0, 1);
        temp_v1 = M2C_FIELD(temp_v0, s32 *, 0xC0);
        if (temp_v1 != -1) {
            sp30 = (s8 *)0x15;
            sp34 = temp_v1;
            func_001D8B20(&sp20, &sp30, &RO_002A5238, 0);
            CRef_Destruct(&sp20);
            CRef_Destruct(&sp30);
        }
        var_s0_2 = 0;
        if (sp40 > 0) {
            do {
                temp_a0_2 = (s8 *)(*(s32 *)((var_s0_2 * 4) + sp44));
                sp20 = NULL;
                sp24 = temp_a0_2;
                if (temp_a0_2 != NULL) {
                    sp28 = M2C_FIELD(temp_a0_2, s32 *, 0xF4);
                    M2C_FIELD(temp_a0_2, s32 *, 0xF4) = 3;
                    sp2C = M2C_FIELD(sp24, s32 *, 0xF8);
                    M2C_FIELD(sp24, s32 *, 0xF8) = 0;
                }
                ApplyTaskState(temp_a0_2, -1);
                if (sp20 != NULL) {
                    M2C_FIELD(sp20, s32 *, 0xF0) = sp28;
                    M2C_FIELD(sp20, s32 *, 0xF4) = sp2C;
                }
                if (sp24 != NULL) {
                    M2C_FIELD(sp24, s32 *, 0xF4) = sp28;
                    M2C_FIELD(sp24, s32 *, 0xF8) = sp2C;
                }
                var_s0_2 += 1;
            } while (var_s0_2 < sp40);
        }
        M2C_FIELD(&B_003DD490, s32 *, 0x3C38) = (s32) M2C_FIELD(temp_v0, s32 *, 0xB8);
        M2C_FIELD(&B_003DD490, s32 *, 0x3BF4) = (s32) ((M2C_FIELD(&B_003DD490, s32 *, 0x3BF4) & ~8) | 4);
        M2C_FIELD(&B_003DD490, s32 *, 0x3C3C) = -1;
        if (sp10 != NULL) {
            M2C_FIELD(sp10, s32 *, 0xF0) = sp18;
            M2C_FIELD(sp10, s32 *, 0xF4) = sp1C;
        }
        if (sp14 != NULL) {
            M2C_FIELD(sp14, s32 *, 0xF4) = sp18;
            M2C_FIELD(sp14, s32 *, 0xF8) = sp1C;
        }
        CStackFrame_Destructor(sp, 2, -1);
    }
}
}
