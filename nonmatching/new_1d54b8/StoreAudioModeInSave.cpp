#include "sly2.h"
struct CRef;
extern "C" {
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
}
struct CRef {
    int tagk; int n; int p2; int p3;
    CRef() {}
    CRef(CRef &other) { CRef_CopyConstruct(this, &other); }
    ~CRef() { CRef_Destruct(this); }
};
extern int g_2c2d8c;
extern int B_003E0FD8;
extern int B_003D4A60;
extern "C" CRef RefSetGameSaveValue(int, CRef &, int *);

void StoreAudioModeInSave(void)
{
    switch (g_2c2d8c) {
    case 2: {
        CRef mode;
        mode.tagk = 0x17;
        mode.n = 0;
        int path = B_003E0FD8;
        CRef copy(mode);
        RefSetGameSaveValue(path, copy, &B_003D4A60);
        break;
    }
    case 3: {
        CRef mode;
        mode.tagk = 0x17;
        mode.n = 1;
        int path = B_003E0FD8;
        CRef copy(mode);
        RefSetGameSaveValue(path, copy, &B_003D4A60);
        break;
    }
    case 0:
    case 1:
        break;
    }
}
