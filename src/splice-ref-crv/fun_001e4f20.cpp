// SPDX-License-Identifier: GPL-3.0-or-later
struct TNVT { char pad[0x40]; short deltaAdd; short idxAdd; void (*fnAdd)(void *); short deltaRemove; short idxRemove; void (*fnRemove)(void *); };
struct TN { char pad0[0xC]; TNVT *vt; char pad1[0x18]; unsigned long flags; char pad2[0xB0]; void *pfollow; };
struct SEQNODE { char pad0[0x24]; void *psubject; char pad1[0x44]; TN *ptn; int fAdded; };
extern "C" void SetTnTnsOverride(TN *, int);
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void *PpoSwFocus(char *);
extern char B_003DD490[];

extern "C" void func_001E4F20(SEQNODE *pseqnode, TN *ptn)
{
    if (pseqnode->ptn != 0) {
        SetTnTnsOverride(pseqnode->ptn, -1);
        pseqnode->ptn->pfollow = 0;
        if (pseqnode->fAdded != 0)
            pseqnode->ptn->vt->fnRemove((char *)pseqnode->ptn + pseqnode->ptn->vt->deltaRemove);
        pseqnode->ptn = 0;
    }
    if (ptn != 0) {
        pseqnode->ptn = ptn;
        unsigned bit = (ptn->flags >> 60) & 1; int fAdd = (unsigned char)bit < 1;
        pseqnode->fAdded = fAdd;
        if (fAdd)
            ptn->vt->fnAdd((char *)ptn + ptn->vt->deltaAdd);
        void *pfollow;
        if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x30) != 0)
            pfollow = pseqnode->psubject;
        else
            pfollow = PpoSwFocus(B_003DD490);
        ptn->pfollow = pfollow;
        SetTnTnsOverride(ptn, 1);
    }
}
