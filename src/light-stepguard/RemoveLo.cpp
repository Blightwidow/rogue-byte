#include "sly2.h"
struct LO { char pad[0xC]; char *vt; LO *parent; void *root; char pad2[0x28 - 0x18]; unsigned long grf; };
struct VB0 { char pad[0xB0]; short d; short i; void (*f)(void *); };
struct VE0 { char pad[0xE0]; short d; short i; int (*f)(void *, LO ***); };
struct V48 { char pad[0x48]; short d; short i; void (*f)(void *); };
struct V60 { char pad[0x60]; short d; short i; void (*f)(void *); };
extern "C" {
int FIsLoInWorld(LO *);
void RemoveDlEntry(void *, void *);
void AppendDlEntry(void *, void *);
void RemoveSwRoot(void *, void *);
void func_001A5448(LO *, void **, void ***);
}
extern char B_003DD4BC;
extern char B_003DD490;
void RemoveLo(LO *plo)
{
    if ((plo->grf & (1UL << 56)) != 0)
        return;
    if (FIsLoInWorld(plo) != 0) {
        VB0 *vt = (VB0 *)plo->vt;
        vt->f((char *)plo + vt->d);
        if (plo->parent == 0)
            RemoveDlEntry(&B_003DD4BC, plo->root);
    }
    if (plo->parent == 0)
        RemoveSwRoot(&B_003DD490, plo->root);
    unsigned long active = (plo->grf >> 60) & 1;
    void *pdl;
    void **pfirst;
    func_001A5448(plo->parent, &pdl, &pfirst);
    RemoveDlEntry(pdl, plo);
    AppendDlEntry(pdl, plo);
    if (*pfirst == 0)
        *pfirst = plo;
    plo->grf |= 1UL << 56;
    LO **achild;
    VE0 *vtc = (VE0 *)plo->vt;
    int cchild = vtc->f((char *)plo + vtc->d, &achild);
    for (int ichild = 0; ichild < cchild; ichild++) {
        LO *child = achild[ichild];
        V48 *vtk = (V48 *)child->vt;
        vtk->f((char *)child + vtk->d);
    }
    if (active) {
        V60 *vta = (V60 *)plo->vt;
        vta->f((char *)plo + vta->d);
    }
}
