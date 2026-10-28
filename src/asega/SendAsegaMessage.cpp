#include "sly2.h"
struct BASIC { char pad[0xC]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(int, void *); };
struct ASEGA : BASIC {
    char pad0[8]; BASIC *paloRoot;
};
void PostLoMessage(ASEGA *, int, void *);
struct HOLD {
    ASEGA *p;
    HOLD(ASEGA *a) { p = a; a->v0(); }
    ~HOLD() { p->v1(); }
};
void SendAsegaMessage(ASEGA *pasega, int msgid, void *pv)
{
    HOLD hold(pasega);
    BASIC *paloRoot = pasega->paloRoot;
    if (paloRoot != 0)
        paloRoot->v4(msgid, pv);
    PostLoMessage(pasega, msgid, pv);
}
