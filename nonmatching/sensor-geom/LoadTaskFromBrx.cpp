typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_LoadTaskFromBrx {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x7C];
};                                                  /* size = 0x90 */
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void LoadLoFromBrx(s8 *, s32);
s32 PvAllocStackImpl__Fi(s32 *);
s32 PvAllocSwClearImpl__Fi(s32 *);
s32 PvAllocSwCopyImpl__FiPv(...);
s32 PvAllocSwImpl__Fi(s32 *);
s32 S32Read__18CBinaryInputStream(void);
s32 U8Read__18CBinaryInputStream(s32);
void Unknown1__18CBinaryInputStream(s32);
void LoadTaskFromBrx(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_s3;
    var_s3 = 0;
    CStackFrame_Construct(sp);
    sp10 = 0x200;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xAC) = PvAllocStackImpl__Fi(&sp10);
    sp10 = 0x300;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xB4) = PvAllocStackImpl__Fi(&sp10);
    LoadLoFromBrx(arg0, arg1);
    sp10 = M2C_FIELD(arg0, s32 *, 0xA8) * 0x10;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xAC) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0xAC));
    sp10 = M2C_FIELD(arg0, s32 *, 0xB0) * 0x18;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xB4) = PvAllocSwCopyImpl__FiPv(&sp10, M2C_FIELD(arg0, s32 *, 0xB4), 0x18);
    temp_v0 = U8Read__18CBinaryInputStream(arg1);
    M2C_FIELD(arg0, s32 *, 0x94) = temp_v0;
    sp10 = temp_v0 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x98) = PvAllocSwClearImpl__Fi(&sp10);
    sp10 = M2C_FIELD(arg0, s32 *, 0x94) * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0x90) = PvAllocSwImpl__Fi(&sp10);
    if (M2C_FIELD(arg0, s32 *, 0x94) > 0) {
        do {
            temp_v1 = var_s3 * 4;
            var_s3 += 1;
            *(s32 *)(temp_v1 + M2C_FIELD(arg0, s32 *, 0x90)) = S32Read__18CBinaryInputStream();
        } while (var_s3 < M2C_FIELD(arg0, s32 *, 0x94));
    }
    temp_v0_2 = U8Read__18CBinaryInputStream(arg1);
    var_s1 = 0;
    M2C_FIELD(arg0, s32 *, 0xA0) = temp_v0_2;
    sp10 = temp_v0_2 * 4;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    M2C_FIELD(arg0, s32 *, 0xA4) = PvAllocSwClearImpl__Fi(&sp10);
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    sp10 = M2C_FIELD(arg0, s32 *, 0xA0) * 4;
    M2C_FIELD(arg0, s32 *, 0x9C) = PvAllocSwImpl__Fi(&sp10);
    if (M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
        do {
            temp_v1_2 = var_s1 * 4;
            var_s1 += 1;
            *(s32 *)(temp_v1_2 + M2C_FIELD(arg0, s32 *, 0x9C)) = S32Read__18CBinaryInputStream();
        } while (var_s1 < M2C_FIELD(arg0, s32 *, 0xA0));
    }
    Unknown1__18CBinaryInputStream(arg1);
    CStackFrame_Destructor(sp, 2);
}
}
