#include "sly2.h"
struct Spawner { char pad0[0x50]; int count; void *points; char pad58[0x3C]; void *templates; int offsetCount; void *offsets; };
extern "C" QW g_2a2dd0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackImpl__Fi(void *);
extern "C" void *PvAllocStackClearImpl__Fi(void *);
extern "C" void *PvAllocSwCopyImpl__FiPv(void *, void *);
extern "C" void AddSpawnerOffset(Spawner *, QW);
extern "C" void LoadLoFromBrx(Spawner *, void *);
extern "C" void func_001731B8(Spawner *spawner, void *bis)
{
    char frame[0x10];
    int reqStorage[2];
    CStackFrame_Construct(frame);
    int *req = reqStorage;
    req[0] = 0xE00;
    req[1] = 0x10;
    spawner->points = PvAllocStackClearImpl__Fi(req);
    req[0] = 0x100;
    req[1] = 0x10;
    spawner->offsets = PvAllocStackImpl__Fi(req);
    req[0] = 0x20;
    req[1] = 0x10;
    spawner->templates = PvAllocStackImpl__Fi(req);
    AddSpawnerOffset(spawner, g_2a2dd0);
    LoadLoFromBrx(spawner, bis);
    req[0] = spawner->count * 0x1C;
    req[1] = 0x10;
    spawner->points = PvAllocSwCopyImpl__FiPv(req, spawner->points);
    req[0] = spawner->offsetCount << 4;
    req[1] = 0x10;
    spawner->offsets = PvAllocSwCopyImpl__FiPv(req, spawner->offsets);
    void *oldTemplates = spawner->templates;
    req[0] = 0x20;
    req[1] = 0x10;
    spawner->templates = PvAllocSwCopyImpl__FiPv(req, oldTemplates);
    CStackFrame_Destructor(frame, 2);
}
