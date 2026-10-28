#include "sly2.h"
int memcmp(const void *, const void *, unsigned int);
struct EMITB {
    int f0; int emitpk; void *ref; char pad0[4]; int f10; char pad1[0xC]; int oidReference; char pad2[0xC]; int oidCurve;
    char pad3[0x94]; int oidA; int oidB; int oidC; int oidSpline;
};
struct EMITTER { char pad[0xE4]; EMITB *emitb; };
struct REQ { int size; int align; };
extern "C" {
void PostLoLoad(EMITTER *);
void *PloFindSwObject_thunk(void *, int, int, void *);
void func_002590F0(EMITTER *, int);
void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
extern char B_003DD490[];
extern char D_002CE4B8[];
}
void PostSuvLoad(EMITTER *emitter)
{
    void *apv[5];
    PostLoLoad(emitter);
    int oidReference = emitter->emitb->oidReference;
    int oidCurve = -1;
    if (emitter->emitb->f10 == 2)
        oidCurve = emitter->emitb->oidCurve;
    memset(apv, 0, 0x14);
    if (oidReference != -1)
        apv[0] = PloFindSwObject_thunk(B_003DD490, 4, oidReference, emitter);
    if (oidCurve != -1) {
        apv[1] = PloFindSwObject_thunk(B_003DD490, 4, oidCurve, emitter);
        apv[0] = 0;
    }
    EMITB *emitb = emitter->emitb;
    int emitpk = emitb->emitpk;
    if (emitpk != 0) {
        if (emitpk == 1) {
            int oidA = emitb->oidA;
            int oidB = emitb->oidB;
            int oidC = emitb->oidC;
            if (oidA != -1)
                apv[2] = PloFindSwObject_thunk(B_003DD490, 4, oidA, emitter);
            if (oidB != -1)
                apv[3] = PloFindSwObject_thunk(B_003DD490, 4, oidB, emitter);
            if (oidC != -1)
                apv[4] = PloFindSwObject_thunk(B_003DD490, 4, oidC, emitter);
        }
    } else {
        int oid = emitb->oidSpline;
        if (oid != -1)
            apv[2] = PloFindSwObject_thunk(B_003DD490, 4, oid, emitter);
    }
    if (emitter->emitb->ref == 0)
        emitter->emitb->ref = D_002CE4B8;
    if (memcmp(emitter->emitb->ref, apv, 0x14) != 0) {
        func_002590F0(emitter, 1);
        REQ req;
        REQ *preq = &req;
        preq->size = 0x14;
        preq->align = 0x10;
        emitter->emitb->ref = PvAllocSwCopyImpl__FiPv(preq, apv);
    }
}
