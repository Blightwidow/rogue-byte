typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJtLootSave {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s8 *sp10;                          /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[8];                       /* maybe part of sp14[3]? */
    /* 0x20 */ s8 *sp20;                          /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ char pad28[8];                       /* maybe part of sp24[3]? */
    /* 0x30 */ s8 *sp30;                          /* inferred */
    /* 0x34 */ char pad34[0xC];                     /* maybe part of sp30[4]? */
    /* 0x40 */ s8 *sp40;                          /* inferred */
    /* 0x44 */ char pad44[0xC];                     /* maybe part of sp40[4]? */
    /* 0x50 */ s8 *sp50;                          /* inferred */
    /* 0x54 */ char pad54[0xC];                     /* maybe part of sp50[4]? */
    /* 0x60 */ s8 *sp60;                          /* inferred */
    /* 0x64 */ s32 sp64;                            /* inferred */
    /* 0x68 */ char pad68[0x88];
};                                                  /* size = 0xF0 */
#define sp14 (*(s32 *)(sp + 0x14))
s32 CRef_CopyConstruct(s8 **, s8 **);
void CRef_Destruct(s8 **);
s32 CStackFrame_Construct(s8 *);
void CStackFrame_Destructor(s8 *, M2C_UNK);
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 IdCurrentLevel();
s32 LootId(s8 *);
s32 PpathCrfodbLoot(s8 *);
s32 PpathFindBootyOid(s32);
s32 RefSetGameSaveValue(s8 **, s32, s8 **, M2C_UNK *);
void __as__4CRefRC4CRef(s8 **, s8 **);
s32 *func_00143AF0(s8 *, s32);
void func_001D8A38(s8 **, M2C_UNK *, M2C_UNK *, s8 **);
void func_001D8B20(s8 **, s8 **, M2C_UNK *, M2C_UNK *);
s32 *func_002109B8(s32);
s32 memcmp(s8 *, s32, M2C_UNK);
void sprintf(s8 **, M2C_UNK *, s32);
extern M2C_UNK B_003D4A60;
extern M2C_UNK B_003DD490;
extern M2C_UNK RO_002A4D50;
extern M2C_UNK RO_002A4DB0;
void UpdateJtLootSave(s8 *arg0, s32 arg1, s8 *arg2) {
    s8 sp[0x30] __attribute__((aligned(16)));
    s8 *sp10;
    s8 *sp20;
    s32 sp24;
    s8 *sp30;
    s8 *sp40;
    s8 *sp50;
    s8 *sp60;
    s32 sp64;
    M2C_UNK *temp_s0_2;
    M2C_UNK *temp_s2;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 var_a0;
    s32 var_a2;
    s32 var_v0;
    u16 var_a0_2;
    s8 *temp_a0;
    s8 *temp_s1;
    s8 *temp_v0_5;
    s8 *temp_v0_7;
    s8 *temp_v1;
    s8 *temp_v1_2;
    s8 *var_a1;
    CStackFrame_Construct(sp);
    switch (arg1) {                                 /* irregular */
    case 0:
        temp_a0 = M2C_FIELD(arg2, s8 **, 0x194);
        if (temp_a0 != NULL) {
            var_v0 = LootId(temp_a0);
        } else {
            var_v0 = -1;
        }
        sp24 = var_v0;
        sp20 = (s8 *)0x15;
        temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
        func_001D8B20(&sp10, &sp20, M2C_FIELD(temp_v1, M2C_UNK *(**)(s8 *), 0x33C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x338)), &RO_002A4DB0);
        CRef_Destruct(&sp20);
        if (M2C_FIELD(arg0, s8 **, 0x11A8) == NULL) {
            temp_v0 = PpathCrfodbLoot(arg2);
            sp20 = (s8 *)0x15;
            sp24 = M2C_FIELD(arg0, s32 *, 0x18);
            CRef_CopyConstruct(&sp30, &sp20);
            RefSetGameSaveValue(&sp40, temp_v0, &sp30, &B_003D4A60);
            CRef_Destruct(&sp40);
            CRef_Destruct(&sp30);
            CRef_Destruct(&sp20);
        } else {
            if (M2C_FIELD(arg2, s8 **, 0x194) == NULL) {
                temp_v0_2 = PpathFindBootyOid(M2C_FIELD(arg0, s32 *, 0x18));
                sp30 = (s8 *)0x15;
                M2C_FIELD(&sp30, s32 *, 4) = -1;
                CRef_CopyConstruct(&sp40, &sp30);
                RefSetGameSaveValue(&sp50, temp_v0_2, &sp40, &B_003D4A60);
                CRef_Destruct(&sp50);
                CRef_Destruct(&sp40);
                CRef_Destruct(&sp30);
            }
            temp_s0 = PpathCrfodbLoot(arg2);
            temp_v0_3 = LootId(M2C_FIELD(arg0, s8 **, 0x11A8));
            sp20 = (s8 *)0x15;
            sp24 = temp_v0_3;
            CRef_CopyConstruct(&sp30, &sp20);
            RefSetGameSaveValue(&sp40, temp_s0, &sp30, &B_003D4A60);
            CRef_Destruct(&sp40);
            CRef_Destruct(&sp30);
            CRef_Destruct(&sp20);
        }
        CRef_Destruct(&sp10);
        break;
    case 1:
        temp_v0_4 = PpathFindBootyOid(M2C_FIELD(arg0, s32 *, 0x18));
        if (temp_v0_4 != 0) {
            sp10 = (s8 *)0x15;
            M2C_FIELD(&sp10, s32 *, 4) = -1;
            CRef_CopyConstruct(&sp20, &sp10);
            RefSetGameSaveValue(&sp30, temp_v0_4, &sp20, &B_003D4A60);
            CRef_Destruct(&sp30);
            CRef_Destruct(&sp20);
            CRef_Destruct(&sp10);
        }
        sp20 = (s8 *)0x15;
        M2C_FIELD(&sp20, s32 *, 4) = -1;
        temp_v1_2 = M2C_FIELD(arg0, s8 **, 0xC);
        func_001D8B20(&sp10, &sp20, M2C_FIELD(temp_v1_2, M2C_UNK *(**)(s8 *), 0x33C)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0x338)), &RO_002A4DB0);
        CRef_Destruct(&sp20);
        temp_a2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x11A8), s8 **, 0x158), s32 *, 4);
        if (temp_a2 != -1) {
            sprintf(&sp20, &RO_002A4D50, temp_a2);
            temp_s0_2 = (M2C_UNK *)("loot");
            temp_s2 = (M2C_UNK *)("mplootkc");
            func_001D8A38(&sp40, temp_s0_2, temp_s2, &sp20);
            __as__4CRefRC4CRef(&sp10, &sp40);
            CRef_Destruct(&sp40);
            sp60 = (s8 *)0x15;
            sp64 = sp14 + 1;
            func_001D8B20(&sp40, &sp60, temp_s0_2, temp_s2);
            __as__4CRefRC4CRef(&sp10, &sp40);
            CRef_Destruct(&sp40);
            CRef_Destruct(&sp60);
        }
        CRef_Destruct(&sp10);
        break;
    case 2:
        temp_s1 = (s8 *)(func_00143AF0(arg0, LootId(M2C_FIELD(arg0, s8 **, 0x11A8))));
        temp_a0_2 = IdCurrentLevel();
        if ((temp_s1 != NULL) && (temp_a0_2 != -1)) {
            temp_v0_5 = (s8 *)(func_002109B8(temp_a0_2));
            var_a0 = 0;
            if (M2C_FIELD(temp_v0_5, s32 *, 0) >= 4) {
                var_a0 = (memcmp(M2C_FIELD(temp_s1, s8 **, 4), M2C_FIELD(temp_v0_5, s32 *, 4), 8) == 0) ? 1 : 0;
            }
            if (var_a0 != 0) {
                temp_v0_6 = CploFindSwObjectsByClass(&B_003DD490, 5, 0x25, 0);
                var_a2 = 0;
                if (temp_v0_6 > 0) {
                    temp_v0_7 = M2C_FIELD(temp_s1, s8 **, 4);
                    var_a1 = sp10;
                    var_a0_2 = M2C_FIELD(temp_v0_7, u16 *, 0xC);
loop_32:
                    var_a2 += 1;
                    if (M2C_FIELD(var_a1, s32 *, 0x180) == var_a0_2) {
                        M2C_FIELD(M2C_FIELD(arg0, s8 **, 0x11A8), s8 **, 0x15C) = var_a1;
                    } else if (var_a2 < temp_v0_6) {
                        var_a0_2 = M2C_FIELD(temp_v0_7, u16 *, 0xC);
                        var_a1 = (&sp10)[var_a2];
                        goto loop_32;
                    }
                }
            }
        }
        break;
    }
    CStackFrame_Destructor(sp, 2);
}
}
