typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_Crfodb_SetLootId {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ char pad24[0xC];                     /* maybe part of sp20[4]? */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0x6C];
};                                                  /* size = 0xA0 */
s32 CRef_CopyConstruct(s32 *, s32 *);
void CRef_Destruct(s32 *);
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
void Crfodb_SpawnLoot(s8 *, M2C_UNK);
s32 PpathCrfodbLoot(s8 *);
s32 RefSetGameSaveValue(s32 *, s32, s32 *);
void SetLootState(s32, M2C_UNK);
extern M2C_UNK B_003D4A60;
s32 Crfodb_SetLootId(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s32 sp20;
    s32 sp30;
    s32 temp_a0;
    s32 temp_v0;
    temp_a0 = M2C_FIELD(arg0, s32 *, 0x194);
    if (temp_a0 != 0) {
        SetLootState(temp_a0, 0);
    }
    CStackFrame_Construct(sp);
    temp_v0 = PpathCrfodbLoot(arg0);
    sp10 = 0x15;
    sp14 = arg1;
    CRef_CopyConstruct(&sp20, &sp10);
    RefSetGameSaveValue(&sp30, temp_v0, &sp20);
    CRef_Destruct(&sp30);
    CRef_Destruct(&sp10);
    CRef_Destruct(&sp20);
    if (arg1 != -1) {
        Crfodb_SpawnLoot(arg0, 0);
    }
    CStackFrame_Destructor(sp, 2);
    return temp_v0;
}
}
