#include "sly2.h"
struct REQ { int size; int align; };
struct ZPR { char pad[0x630]; };
extern "C" void *PvAllocSwImpl__Fi(REQ *);
extern "C" void *PvAllocSwClearImpl__Fi(REQ *);
extern "C" void InitSl(void *, int);
extern "C" void InitZpr__FP3ZPR3ZPKP2LO(ZPR *, int, int);
extern "C" void func_001BE398(void *, ZPR *);
extern "C" void bevy_camera_follow_activity(void *, int, int);
extern "C" char B_002DEB30[];
struct SW { char pad0[0x3BF4]; unsigned flags; };
void AllocSwBuffers(char *sw)
{
    REQ req;
    ZPR zpr;
    void **slot = (void **)(sw + 0x3CD4);
    for (int index = 2; index >= 0; index--) {
        req.size = 0x4800;
        req.align = 0x10;
        *slot++ = PvAllocSwImpl__Fi(&req);
    }
    unsigned index = 0;
    char *entry = sw + 0x45E8;
    req.size = 0x8000;
    req.align = 0x10;
    *(void **)(sw + 0x3F20) = PvAllocSwClearImpl__Fi(&req);
    req.size = 0x28;
    req.align = 0x10;
    int *record = (int *)PvAllocSwClearImpl__Fi(&req);
    *(int **)(sw + 0x3F0C) = record;
    *record = -1;
    (*(int **)(sw + 0x3F0C))[2] = -1;
    InitSl(*(char **)(sw + 0x3F0C) + 0x18, 0x14);
    InitZpr__FP3ZPR3ZPKP2LO(&zpr, 0x1400, 0x1800);
    for (; index < 2; index++) {
        func_001BE398(entry, &zpr);
        entry += 0x28;
    }
    if (*(unsigned *)(sw + 0x3BF4) & 0x20)
        *(int *)(sw + 0x3E38) = 1;
    bevy_camera_follow_activity(B_002DEB30, 2, 0);
}
