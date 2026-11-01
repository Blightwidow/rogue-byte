// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VTXfm2315F0 {
    char pad[0xE8];
    short deltaSetMat; short indexSetMat; void (*fnSetMat)(void *, QW);
    short deltaSetPos; short indexSetPos; void (*fnSetPos)(void *, MATRIX4 *);
    short deltaGetMat; short indexGetMat; MATRIX4 *(*fnGetMat)(void *);
};
struct XfmParent2315F0;
struct Xfm2315F0 {
    char pad0[0xC];
    VTXfm2315F0 *vptr;
    char pad10[0x18];
    unsigned long flags;
    char pad30[0x20];
    Xfm2315F0 *pxfmChild;
    char pad54[0xC];
    MATRIX4 matLocal;
    Xfm2315F0 *pxfmNext;
};
MATRIX4 operator*(const MATRIX4 &, const MATRIX4 &);
extern "C" void SetLoParent(Xfm2315F0 *, Xfm2315F0 *, Xfm2315F0 *, int);

extern "C" void SetXfmParent(Xfm2315F0 *pxfm, Xfm2315F0 *pparent, Xfm2315F0 *pchild, int grfsxfm) {
    MATRIX4 matSave;
    if (grfsxfm & 3) {
        if ((unsigned)(pxfm->flags >> 60) & 1) {
            VTXfm2315F0 *vt = pxfm->vptr;
            matSave = *vt->fnGetMat((char *)pxfm + vt->deltaGetMat);
        } else {
            matSave = pxfm->matLocal;
            for (Xfm2315F0 *pnode = pxfm->pxfmChild; pnode != 0; pnode = pnode->pxfmNext)
                matSave = *(MATRIX4 *)pnode * matSave;
        }
    }
    if (pchild != 0)
        pxfm->pxfmChild = pchild;
    else if (pparent != 0)
        pxfm->pxfmChild = *(Xfm2315F0 **)((char *)pparent + 0x60);
    else
        pxfm->pxfmChild = 0;
    SetLoParent(pxfm, pparent, pchild, grfsxfm);
    if (grfsxfm & 1) {
        VTXfm2315F0 *vt = pxfm->vptr;
        vt->fnSetMat((char *)pxfm + vt->deltaSetMat, *(QW *)matSave.mat[3]);
    }
    if (grfsxfm & 2) {
        VTXfm2315F0 *vt = pxfm->vptr;
        vt->fnSetPos((char *)pxfm + vt->deltaSetPos, &matSave);
    }
}
