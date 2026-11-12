// SPDX-License-Identifier: GPL-3.0-or-later
struct SAVE;
extern "C" SAVE B_003D4A60;
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int n;
    int tagk;
    int pad[2];
    CRef(int tag, int value) { tagk = tag; n = value; }
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern "C" {
CRef RefSetGameSaveValue(int path, CRef *value, SAVE *save);
}
inline void SetGameSaveValue(int path, CRef value, SAVE *save)
{
    RefSetGameSaveValue(path, &value, save);
}
extern "C" {
extern int g_2c2d8c;
extern int B_003E0FD8;
}

// Retail: switch on the audio mode (beq 2, slti 3, beq 3: cases 0 and 1 are explicit no-ops in the decision tree).
// Cases 2 and 3 store CRef{0x17, 0 or 1} as the save value at path B_003E0FD8 in save B_003D4A60. Each case
// builds the CRef at sp+0, copy-constructs it to sp+0x10 (by-value parameter), calls RefSetGameSaveValue
// (a0 = result at sp+0x20, a1 = path, a2 = &copy, a3 = save; its own disassembly forwards all four), then
// destroys result, copy and original in that order: an inline helper taking the CRef by value gives exactly that.
// The path is loaded before the copy in both cases (a local). Still differs (NEAR 13): in case 2 retail keeps only
// %hi(B_003D4A60) in $s0 across the copy and adds %lo straight into $a3 after it; the save local here keeps the full
// address in $s0 (lui+addiu before the call, move after). Case 3 (address taken after the copy) matches.
extern "C" void StoreAudioModeInSave(void)
{
    switch (g_2c2d8c) {
    case 0:
    case 1:
        break;
    case 2: {
        SAVE *save = &B_003D4A60;
        int path = B_003E0FD8;
        CRef mode(0x17, 0);
        SetGameSaveValue(path, mode, save);
        break;
    }
    case 3: {
        int path = B_003E0FD8;
        CRef mode(0x17, 1);
        SetGameSaveValue(path, mode, &B_003D4A60);
        break;
    }
    }
}
