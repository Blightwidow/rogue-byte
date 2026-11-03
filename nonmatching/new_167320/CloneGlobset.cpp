#include "sly2.h"
struct REQ { int size; int align; };
struct OBJ { char pad0[0x20]; int flags; char pad24[0x44 - 0x24]; int count44; void **ptr48; };
struct BITS { unsigned lo : 13; unsigned start : 9; unsigned end : 9; unsigned hi : 1; };
struct DST { int f0; int f4; int f8; BITS bits; void *p10; int f14; void *p18; int f1c; OBJ *pobj; int f24; };
struct SRC { char b0; signed char count; signed char flags; char pad3[5]; int f8; int fC; int f10; };
struct ENT { char pad[0xC]; };
struct SLE { int f0; int f4; int f8; OBJ *pobj; int f10; };
struct P12 { char pad[0xC]; };
struct VOBJ : P12 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void emit(int, void *);
};
struct GS {
    VOBJ *pparent; char pad4[0x24 - 4]; int cobj; void **pobj; char pad2C[0x38 - 0x2C];
    int cdst; SRC *psrc; DST *pdst; char pad44[0x58 - 0x44]; int f58;
};
struct SLENT { int f0; int f4; int f8; OBJ *pobj; int sle; };
extern "C" {
extern int B_003DA790;
extern SLENT B_003DA798[];
void ClearSle(void *);
void CopyAb__FPvT0Ui(void *, void *, unsigned);
void CopyGlobDmaChain(SRC *, DST *, int, void *, int, void *, void *);
void PrependSlEntry(void *, void *);
void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
void func_001EC740(int, int, int, void *, void *);
OBJ *func_001ED850(OBJ *);
}

extern "C" void CloneGlobset(GS *self, VOBJ *parent, int arg)
{
    REQ req;
    self->pparent = parent;
    req.size = self->cdst * 0x28;
    req.align = 0x10;
    self->pdst = (DST *)PvAllocSwCopyImpl__FiPv(&req, self->pdst);
    self->f58 = 0;
    int index = 0;
    if (self->cobj > 0) {
        do {
            if (((OBJ *)self->pobj[index])->flags & 4) {
                req.size = self->cobj * 4;
                req.align = 0x10;
                self->pobj = (void **)PvAllocSwCopyImpl__FiPv(&req, self->pobj);
                break;
            }
            index++;
        } while (index < self->cobj);
    }
    for (int index = 0; index < self->cdst; index++) {
        DST *pdst = &self->pdst[index];
        SRC *psrc = (SRC *)((char *)self->psrc + index * 0x14);
        parent->emit(arg, &pdst->f4);
        req.size = psrc->count * 0x50;
        req.align = 0x10;
        pdst->p18 = PvAllocSwCopyImpl__FiPv(&req, pdst->p18);
        for (int ient = 0; ient < psrc->count; ient++)
            parent->emit(arg, (char *)pdst->p18 + ient * 0x50 + 0xC);
        OBJ *pobj = pdst->pobj;
        int fresh = pobj != 0 && (pobj->flags & 4);
        if (fresh != 0) {
            OBJ *pnew = func_001ED850(pobj);
            for (int iobj = 0; iobj < self->cobj; iobj++) {
                if (self->pobj[iobj] == pdst->pobj) {
                    self->pobj[iobj] = pnew;
                    break;
                }
            }
            pdst->pobj = pnew;
        }
        if (psrc->f8 != 0 || fresh != 0) {
            int cdma = 0;
            void *pold = 0;
            void *pnew = 0;
            if (psrc->flags & 1) {
                cdma = psrc->f10;
                pold = pdst->p10;
                req.size = cdma * 0x10;
                req.align = 0x10;
                pnew = PvAllocSwCopyImpl__FiPv(&req, pold);
                pdst->p10 = pnew;
            } else {
                if (pdst->pobj != 0) {
                    pnew = pdst->pobj->ptr48;
                    cdma = pdst->pobj->count44;
                    if (fresh != 0) {
                        pold = pnew;
                        req.size = cdma * 0x10;
                        req.align = 0x10;
                        pdst->pobj->ptr48 = (void **)PvAllocSwCopyImpl__FiPv(&req, pold);
                        pnew = pdst->pobj->ptr48;
                    }
                }
                CopyGlobDmaChain(psrc, pdst, psrc->f10, pdst->p10, cdma, pnew, pold);
            }
            if (pdst->pobj != 0) {
                unsigned start = pdst->bits.start;
                unsigned count = pdst->bits.end - start;
                int dmaBytes = cdma * 0x10;
                CopyAb__FPvT0Ui(&B_003DA798[B_003DA790], &B_003DA798[start], count * sizeof(SLENT));
                pdst->bits.start = B_003DA790;
                B_003DA790 += count;
                pdst->bits.end = B_003DA790;
                for (unsigned ientry = pdst->bits.start; ientry < pdst->bits.end; ientry++) {
                    SLENT *pentry = &B_003DA798[ientry];
                    if (fresh != 0) {
                        pentry->f4 = (int)pdst->pobj + 0x24;
                        pentry->pobj = pdst->pobj;
                    }
                    ClearSle(&B_003DA798[ientry].sle);
                    PrependSlEntry((char *)pentry->pobj + 0x34, pentry);
                }
                func_001EC740(pdst->bits.start, pdst->bits.end, dmaBytes, pold, pnew);
            }
        }
    }
}
