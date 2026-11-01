// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk;
    int n;
    int pad0;
    int pad1;
    CRef(int tag, int count) { tagk = tag; n = count; }
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern "C" {
CRef RefSetGameSaveValue(int, CRef, int *);
extern int g_2c2d8c;
extern int B_003E0FD8;
extern int B_003D4A60;
void StoreAudioModeInSave(void)
{
    switch (g_2c2d8c) {
    case 0:
    case 1:
        break;
    case 2: {
        CRef mode(0x17, 0);
        int path = B_003E0FD8;
        RefSetGameSaveValue(path, mode, &B_003D4A60);
        break;
    }
    case 3: {
        CRef mode(0x17, 1);
        int path = B_003E0FD8;
        RefSetGameSaveValue(path, mode, &B_003D4A60);
        break;
    }
    }
}
}
