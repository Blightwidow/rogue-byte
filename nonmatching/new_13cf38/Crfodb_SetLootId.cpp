typedef int s32;
typedef signed char s8;
extern "C" {
s32 CRef_CopyConstruct(s32 *, s32 *);
void CRef_Destruct(s32 *);
s32 CStackFrame_Construct(s8 *, s32);
void CStackFrame_Destructor(s8 *, int);
void Crfodb_SpawnLoot(s8 *, s32);
s32 PpathCrfodbLoot(s8 *);
s32 RefSetGameSaveValue(s32 *, s32, s32 *);
void SetLootState(s32, int);
s32 Crfodb_SetLootId(s8 *arg0, s32 arg1) {
    s8 sp[0x20] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s32 sp20;
    s32 sp30;
    s32 temp_a0;
    s32 temp_v0;
    temp_a0 = *(s32 *)(arg0 + 0x194);
    if (temp_a0 != 0) {
        SetLootState(temp_a0, 0);
    }
    CStackFrame_Construct(sp, arg1);
    temp_v0 = PpathCrfodbLoot(arg0);
    sp10 = 0x15;
    sp14 = arg1;
    CRef_CopyConstruct(&sp20, &sp10);
    RefSetGameSaveValue(&sp30, temp_v0, &sp20);
    CRef_Destruct(&sp30);
    CRef_Destruct(&sp10);
    CRef_Destruct(&sp20);
    if (arg1 != -1) {
        Crfodb_SpawnLoot(arg0, arg1);
    }
    CStackFrame_Destructor(sp, 2);
    return temp_v0;
}
}
