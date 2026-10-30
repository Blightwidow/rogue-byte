typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadStgSwitchFromBrx {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0xA8];
};                                                  /* size = 0xC0 */
void CSo_LoadFromBrx(s8 *, s32);
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
s32 PvAllocStackClearImpl__Fi(s32 *);
s32 PvAllocStackImpl__Fi(s32 *);
s32 PvAllocSwCopyImpl__FiPv(s32 *, s32);
void LoadStgSwitchFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s2;
    s8 *temp_s0;
    s8 *temp_s1;
    CStackFrame_Construct(sp);
    sp10 = 0x40;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x154) = PvAllocStackImpl__Fi(&sp10);
    sp10 = 0x200;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x164) = (s32) (PvAllocStackClearImpl__Fi(&sp10) + 0x10);
    CSo_LoadFromBrx(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x15C) = 0;
    sp10 = M2C_FIELD(arg0, s32 *, 0x150) * 8;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x160);
    M2C_FIELD(arg0, s32 *, 0x154) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0x154));
    if (temp_v1 != 0) {
        sp14 = 0x10;
        sp10 = (temp_v1 * 0x10) + 0x10;
        var_s0 = -1;
        M2C_FIELD(arg0, s32 *, 0x164) = (s32) (PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0x164) - 0x10) + 0x10);
        if (M2C_FIELD(arg0, s32 *, 0x160) > -1) {
loop_3:
            temp_s1 = (s8 *)(M2C_FIELD(arg0, s32 *, 0x164) + (var_s0 * 0x10));
            var_s2 = 0;
            sp14 = 0x10;
            sp10 = M2C_FIELD(temp_s1, s32 *, 8) * 8;
            M2C_FIELD(temp_s1, s32 *, 0xC) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(temp_s1, s32 *, 0xC));
            if (M2C_FIELD(temp_s1, s32 *, 8) > 0) {
                do {
                    temp_s0 = (s8 *)(M2C_FIELD(temp_s1, s32 *, 0xC) + (var_s2 * 8));
                    if (M2C_FIELD(temp_s0, s32 *, 0) == 0xC) {
                        sp10 = 8;
                        M2C_FIELD(&sp10, s32 *, 4) = 0x10;
                        M2C_FIELD(temp_s0, s32 *, 4) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(temp_s0, s32 *, 4));
                    }
                    var_s2 += 1;
                } while (var_s2 < M2C_FIELD(temp_s1, s32 *, 8));
            }
            var_s0 += 1;
            if (var_s0 < M2C_FIELD(arg0, s32 *, 0x160)) {
                goto loop_3;
            }
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x164) = 0;
    }
    CStackFrame_Destructor(sp, 2);
}
}
