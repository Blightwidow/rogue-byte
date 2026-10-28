#include "sly2.h"
struct ENTRY { void *next; void *dest; int a; void *owner; int sl; };
extern "C" int B_003DA790;
extern "C" ENTRY B_003DA798[];
extern "C" void ClearSle(void *);
extern "C" void PrependSlEntry(void *, void *);
extern "C" void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, void *, void *);
extern "C" void func_001EC718(void *);
extern "C" int func_001ED960(char *node, int source, void *vifs)
{
    ENTRY stackEntry;
    ENTRY *entry;
    if (B_003DA790 < 0x200) {
        entry = &B_003DA798[B_003DA790++];
        ClearSle((char *)entry + 0x10);
        PrependSlEntry(node + 0x34, entry);
        entry->owner = node;
    } else {
        entry = &stackEntry;
    }
    UnpackHelper__4VIFS3UPKiiPiPPUi(vifs, 0xD, 1, source, entry, (char *)entry + 8);
    entry->dest = node + 0x24;
    func_001EC718(entry);
    return 1;
}
