#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct MATRIX { float m[16]; };
struct CNode { int pad0; int pad4; int tagk; union { int n; float g; QW *pv; MATRIX *pm; }; CNode *pnext; };
struct CRef { int tagk; union { int n; float g; QW *pv; MATRIX *pm; }; int fhas; CNode *pnode; };
struct CFrame;
extern "C" {
void CRef_Destruct(CRef *);
CRef *CRef_CopyConstruct(CRef *, CRef *);
void CRef_SetS32(CRef *, int);
void CRef_SetF32(CRef *, float);
void CRef_SetVectorPtr(CRef *, QW *);
void CRef_SetMatrixPtr(CRef *, MATRIX *);
}
extern "C" CRef *RefOpAdd(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef refSum;
    refSum.tagk = -1;
    int tagk = aref->tagk;
    CNode *pnode = aref->fhas != 0 ? aref->pnode : 0;
    switch (tagk) {
    case 0x15:
    case 0x16: {
        float sum;
        int fint;
        if (tagk == 0x15) {
            sum = (float)aref->n;
            fint = 1;
        } else {
            sum = aref->g;
            fint = 0;
        }
        for (; pnode != 0; pnode = pnode->pnext) {
            if (pnode->tagk == 0x15)
                sum = sum + (float)pnode->n;
            else {
                fint = 0;
                sum = sum + pnode->g;
            }
        }
        if (fint)
            CRef_SetS32(&refSum, (int)sum);
        else
            CRef_SetF32(&refSum, sum);
        break;
    }
    case 0x1A:
        CRef_SetVectorPtr(&refSum, aref->pv);
        for (; pnode != 0; pnode = pnode->pnext)
            asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m" (*refSum.pv) : "m" (*pnode->pv), "m" (*refSum.pv));
        break;
    case 0x1B:
        CRef_SetMatrixPtr(&refSum, aref->pm);
        for (; pnode != 0; pnode = pnode->pnext) {
            MATRIX *pbox = refSum.pm;
            MATRIX *pterm = pnode->pm;
                pbox->m[0] = pbox->m[0] + pterm->m[0];
                pbox->m[1] = pbox->m[1] + pterm->m[1];
                pbox->m[2] = pbox->m[2] + pterm->m[2];
                pbox->m[3] = pbox->m[3] + pterm->m[3];
                pbox->m[4] = pbox->m[4] + pterm->m[4];
                pbox->m[5] = pbox->m[5] + pterm->m[5];
                pbox->m[6] = pbox->m[6] + pterm->m[6];
                pbox->m[7] = pbox->m[7] + pterm->m[7];
                pbox->m[8] = pbox->m[8] + pterm->m[8];
                pbox->m[9] = pbox->m[9] + pterm->m[9];
                pbox->m[10] = pbox->m[10] + pterm->m[10];
                pbox->m[11] = pbox->m[11] + pterm->m[11];
                pbox->m[12] = pbox->m[12] + pterm->m[12];
                pbox->m[13] = pbox->m[13] + pterm->m[13];
                pbox->m[14] = pbox->m[14] + pterm->m[14];
                pbox->m[15] = pbox->m[15] + pterm->m[15];
        }
        break;
    }
    CRef_CopyConstruct(pret, &refSum);
    CRef_Destruct(&refSum);
    return pret;
}
