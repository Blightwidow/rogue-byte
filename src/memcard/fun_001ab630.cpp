struct MEMCARD;
struct SLOT { char pad[0x5464]; };
struct SAVE {
    char pad0[8]; int state; int want; char pad1[0x14]; SLOT aslot[3];
    char pad2[0xFD5C - 0x24 - 3 * 0x5464];
    char mc[1];
};
extern "C" {
extern int g_savedata_3e0ea8;
void SetMemcardThreadHighPrio__FP7MEMCARD(MEMCARD *);
int ValidateSaveSlot(SAVE *, SLOT *);
void SetSaveState(SAVE *, int);
}
void func_001AB630(SAVE *psave)
{
    if (psave->state == 5 && g_savedata_3e0ea8 != 0) {
        SLOT *pslot = psave->aslot;
        SetMemcardThreadHighPrio__FP7MEMCARD((MEMCARD *)psave->mc);
        for (int index = 2; index >= 0; index--, pslot++)
            ValidateSaveSlot(psave, pslot);
        psave->want = 6;
        SetSaveState(psave, 6);
    }
}
