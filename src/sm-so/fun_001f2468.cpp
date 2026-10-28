#include "sly2.h"
struct REFC { int pad[2]; int count; };
struct NODE { char pad[0x24]; NODE *next; };
struct S {
    char pad0[0x64]; NODE *first; char pad1[0x08]; NODE *last; char pad2[0xC0]; REFC *ref;
};
extern char B_003E12D4[];
extern "C" void FreeSlotheapPv(char *, REFC *);
extern "C" int FIsBasicDerivedFrom(NODE *, int);
extern "C" void func_001F2468(S *);

extern "C" void func_001F2468(S *s)
{
    REFC *ref = s->ref;
    if (ref) {
        if (--ref->count == 0)
            FreeSlotheapPv(B_003E12D4, ref);
        s->ref = 0;
    }
    for (NODE *node = s->first; node != s->last; node = node->next) {
        if (FIsBasicDerivedFrom(node, 0x30))
            func_001F2468((S *)node);
    }
}
