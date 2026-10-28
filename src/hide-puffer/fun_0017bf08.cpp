#include "sly2.h"
extern "C" void func_001EEF70(void *);
extern "C" QW PosLoWorld(void *);
extern "C" void FFindPathzoneCrv(void *, QW, QW, void *);
extern "C" void func_0017C550(void *, int);

void func_0017BF08(void *pgoal)
{
    func_001EEF70(pgoal);
    char *pguard = (char *)((void **)pgoal)[0x10 / 4];
    if ((((unsigned *)pguard)[0xFE8 / 4] & 4) != 0) {
        char *pobject = (char *)((void **)pguard)[0xE8 / 4];
        char *pzoneHolder = 0;
        if (pobject != 0)
            pzoneHolder = (char *)((void **)pobject)[0xDC / 4];
        void *ppathzone = 0;
        if (pzoneHolder != 0)
            ppathzone = ((void **)pzoneHolder)[0x10 / 4];
        QW posFrom = PosLoWorld(pguard);
        QW posTo = PosLoWorld(((void **)pgoal)[0x10 / 4]);
        FFindPathzoneCrv(ppathzone, posFrom, posTo, ((void **)((void **)pgoal)[0x10 / 4])[0x294 / 4]);
        func_0017C550(pgoal, 1);
    } else {
        func_0017C550(pgoal, 0);
    }
}
