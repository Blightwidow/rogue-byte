#include "sly2.h"
struct GIFS { char pad[0x30]; };
struct SFRAME { int a; QW *pqw; int pad[2]; };
struct Shd { char p0[0x14]; long *ptex0; };
struct Chr { char p0[4]; int kind; char p1[0x10 - 8]; int oid; char p2[0x1C - 0x14]; int slot; int slotCopy; };
struct Blot { char p0[0xC4]; void *pheap; };
extern "C" void CStackFrame_Construct(SFRAME *);
extern "C" void CStackFrame_Destructor(SFRAME *, int);
extern "C" Shd *PshdframesFromOid(int);
extern "C" void __4GIFS(GIFS *);
extern "C" void AllocStack__4DMASi(GIFS *, int);
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddPrimEnd__4GIFS(GIFS *);
extern "C" void DMAS_DetachCopy(GIFS *, void *, int *, int, int *);
void func_002155C0(Blot *pblot, Chr *pchr)
{
    SFRAME frame;
    CStackFrame_Construct(&frame);
    if (pchr->kind == 7) {
        pchr->slot = 0;
        pchr->slotCopy = 0;
        Shd *pshd = PshdframesFromOid(pchr->oid);
        if (pshd != 0) {
            GIFS gifs;
            __4GIFS(&gifs);
            AllocStack__4DMASi(&gifs, 0x10);
            AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
            PackAD__4GIFSll(&gifs, 6, *pshd->ptex0);
            PackAD__4GIFSll(&gifs, 0x14, 0x60);
            PackAD__4GIFSll(&gifs, 8, 5);
            AddPrimEnd__4GIFS(&gifs);
            DMAS_DetachCopy(&gifs, pblot->pheap, &pchr->slot, 0, &pchr->slotCopy);
        }
    }
    CStackFrame_Destructor(&frame, 2);
}
