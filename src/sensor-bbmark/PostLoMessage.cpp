#include "sly2.h"
struct LO;
struct SUB { LO *plo; int unk4; SUB *psubNext; };
struct LOD { int unk0; int unk4; SUB *psubFirst; };
struct LO : LOD {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void HandleMessage(int, void *);
};

void PostLoMessage(LO *plo, int msgid, void *pv)
{
    plo->HandleMessage(msgid, pv);
    SUB *psub = plo->psubFirst;
    while (psub) {
        LO *ploSub = psub->plo;
        psub = psub->psubNext;
        ploSub->HandleMessage(msgid, pv);
    }
}
