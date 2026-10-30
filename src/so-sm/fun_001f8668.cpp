#include "sly2.h"
struct ALO { char pad0[0x24]; ALO *next; char pad28[0x3C]; ALO *child; char pad68[0x148 - 0x68]; unsigned long low : 35; unsigned long hid : 1; unsigned long high : 28; };
extern "C" void AddAloToRenderTree(ALO *);
extern "C" void RemoveAloFromRenderTree(ALO *);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern int B_003E12EC[];
extern "C" void func_001F8668(ALO *, long);

extern "C" void func_001F8668(ALO *alo, long hidden)
{
    if (hidden == alo->hid) return;
    alo->hid = hidden;
    if (B_003E12EC[0]) {
        if (hidden) AddAloToRenderTree(alo);
        else RemoveAloFromRenderTree(alo);
    }
    for (ALO *child = alo->child; child; child = child->next) {
        if (FIsBasicDerivedFrom(child, 0x30)) {
            func_001F8668(child, hidden);
        }
    }
}
