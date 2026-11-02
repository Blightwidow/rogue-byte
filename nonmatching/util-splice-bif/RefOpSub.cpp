#include "sly2.h"
struct CRef { int tagk; int n; };
struct CFrame;
struct CPair { int pad0; int pad4; CRef ref; CPair *next; };
struct Mat16 { float value[16]; };
extern "C" {
void CRef_CopyConstruct(CRef *, CRef *);
void CRef_Destruct(CRef *);
CRef *CRef_SetS32(CRef *, int);
CRef *CRef_SetF32(CRef *, float);
CRef *CRef_SetVectorPtr(CRef *, void *);
CRef *CRef_SetMatrixPtr(CRef *, void *);
}
extern "C" CRef *RefOpSub(CRef *pref, int carg, CRef *aref, CFrame *pframe)
{
    CRef refResult;
    int op = aref[0].tagk;
    refResult.tagk = -1;
    CPair *node;
    if (aref[1].tagk != 0)
        node = (CPair *)aref[1].n;
    else
        node = 0;
    switch (op) {
    case 0x15:
    case 0x16: {
        float accumulator;
        int isInt;
        if (op == 0x15) {
            accumulator = (float)aref[0].n;
            isInt = 1;
        } else {
            accumulator = *(float *)&aref[0].n;
            isInt = 0;
        }
        if (node != 0) {
            do {
                if (node->ref.tagk == 0x15) {
                    accumulator -= (float)node->ref.n;
                } else {
                    accumulator -= *(float *)&node->ref.n;
                    isInt = 0;
                }
                node = node->next;
            } while (node != 0);
        }
        if (isInt)
            CRef_SetS32(&refResult, (int)accumulator);
        else
            CRef_SetF32(&refResult, accumulator);
        break;
    }
    case 0x1A:
        CRef_SetVectorPtr(&refResult, (void *)aref[0].n);
        for (; node != 0; node = node->next)
            asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0"
                : "=m"(*(QW *)refResult.n) : "m"(*(QW *)node->ref.n), "m"(*(QW *)refResult.n));
        break;
    case 0x1B:
        CRef_SetMatrixPtr(&refResult, (void *)aref[0].n);
        for (; node != 0; node = node->next) {
            Mat16 *destination = (Mat16 *)refResult.n;
            Mat16 *source = (Mat16 *)node->ref.n;
            destination->value[0] -= source->value[0];
            destination->value[1] -= source->value[1];
            destination->value[2] -= source->value[2];
            destination->value[3] -= source->value[3];
            destination->value[4] -= source->value[4];
            destination->value[5] -= source->value[5];
            destination->value[6] -= source->value[6];
            destination->value[7] -= source->value[7];
            destination->value[8] -= source->value[8];
            destination->value[9] -= source->value[9];
            destination->value[10] -= source->value[10];
            destination->value[11] -= source->value[11];
            destination->value[12] -= source->value[12];
            destination->value[13] -= source->value[13];
            destination->value[14] -= source->value[14];
            destination->value[15] -= source->value[15];
        }
        break;
    }
    CRef_CopyConstruct(pref, &refResult);
    CRef_Destruct(&refResult);
    return pref;
}
