#include "sly2.h"
struct LO { char pad[0xC]; char *vt; LO *parent; LO **link; char pad18[0x24 - 0x18]; LO *next; unsigned long grf; };
struct VB0 { char pad[0xB0]; short d; short i; void (*f)(void *); };
struct VB8 { char pad[0xB8]; short d; short i; void (*f)(void *); };
struct V68 { char pad[0x68]; short d; short i; void (*f)(void *, LO *, LO *); };
struct VE0 { char pad[0xE0]; short d; short i; int (*f)(void *, LO ***); };
struct V50 { char pad[0x50]; short d; short i; void (*f)(void *, LO *, int, int); };
struct V58 { char pad[0x58]; short d; short i; void (*f)(void *); };
struct V60 { char pad[0x60]; short d; short i; void (*f)(void *); };
extern "C" {
void AppendDlEntry(void *, void *);
int FIsLoInWorld(LO *);
void InsertDlEntryBefore(void *, void *, void *);
void RemoveDlEntry(void *, void *);
void func_00148300(void *, LO *);
void func_001A5448(LO *, void **, LO ***);
extern char B_003DD490;
extern char B_003DD4BC;
void SetLoParent(LO *plo, LO *parent, int arg2, int arg3);
}
void SetLoParent(LO *plo, LO *parent, int arg2, int arg3) {
    unsigned long newActive = 0;
    unsigned long grf = plo->grf;
    unsigned long wasActive = (grf >> 60) & 1;
    void *oldList;
    LO **oldFirst;
    void *newList;
    LO **newFirst;
    LO **children;
    if (parent == 0 || ((parent->grf >> 60) & 1)) {
        newActive = 1;
        if (grf & (1UL << 56)) {
            newActive = 0;
        }
    }
    func_001A5448(plo->parent, &oldList, &oldFirst);
    func_001A5448(parent, &newList, &newFirst);
    if ((plo->grf & (1UL << 56)) != 0) {
        if (plo == *oldFirst) {
            *oldFirst = plo->next;
        }
        RemoveDlEntry(oldList, plo);
        AppendDlEntry(newList, plo);
        if (*newFirst == 0) {
            *newFirst = plo;
        }
    } else {
        RemoveDlEntry(oldList, plo);
        InsertDlEntryBefore(newList, *newFirst, plo);
    }
    if (FIsLoInWorld(plo) != 0) {
        VB0 *vtable = (VB0 *)plo->vt;
        vtable->f((char *)plo + vtable->d);
        LO **link = plo->link;
        if (*link == plo) {
            RemoveDlEntry(&B_003DD4BC, link);
        }
    }
    LO *oldParent = plo->parent;
    V68 *vtable68 = (V68 *)plo->vt;
    plo->parent = parent;
    int index = 0;
    vtable68->f((char *)plo + vtable68->d, plo, oldParent);
    VE0 *vtableE0 = (VE0 *)plo->vt;
    int count = vtableE0->f((char *)plo + vtableE0->d, &children);
    if (count > 0) {
        do {
            LO *child = children[index];
            index += 1;
            V50 *vtable50 = (V50 *)child->vt;
            vtable50->f((char *)child + vtable50->d, parent, arg2, arg3);
        } while (index < count);
    }
    if (newActive != wasActive) {
        if (newActive != 0) {
            V58 *vtable58 = (V58 *)plo->vt;
            vtable58->f((char *)plo + vtable58->d);
        } else {
            V60 *vtable60 = (V60 *)plo->vt;
            vtable60->f((char *)plo + vtable60->d);
        }
    }
    if (FIsLoInWorld(plo) != 0) {
        VB8 *vtableB8 = (VB8 *)plo->vt;
        vtableB8->f((char *)plo + vtableB8->d);
    } else if (plo->parent == 0 && newActive != 0) {
        func_00148300(&B_003DD490, plo);
    }
}
