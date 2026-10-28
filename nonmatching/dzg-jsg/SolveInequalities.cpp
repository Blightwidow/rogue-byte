#include "sly2.h"
struct ALLOC { int cb; int align; };
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void func_0011A550(void *, int);
void *PvAllocStackImpl__Fi(ALLOC *);
void CopyAb__FPvT0Ui(void *, const float *, unsigned int);
void AppendDlEntry(void *, void *);
void SolveDzgPrefilled(void *);
}

void SolveInequalities(int c, const float *aag, const float *ag, float *agSoln, float sfMax)
{
    char frame[0x10];
    CStackFrame_Construct(frame);
    char pdzg[0x50];
    func_0011A550(pdzg, c);
    ALLOC alloc;
    int cbRow = c * 4;
    for (int idz = 0; idz < c; idz++) {
        char *pdz = *(char **)(pdzg + 0x8) + idz * 0x28;
        *(float *)(pdz + 0x8) = sfMax;
        alloc.cb = cbRow;
        alloc.align = 0x10;
        void *mpidzg = PvAllocStackImpl__Fi(&alloc);
        *(void **)(pdz + 0x18) = mpidzg;
        CopyAb__FPvT0Ui(mpidzg, aag + idz * c, cbRow);
        *(float *)(pdz + 0x10) = ag[idz];
        AppendDlEntry(pdzg + 0x30, pdz);
    }
    *(int *)(pdzg + 0x4) = c;
    SolveDzgPrefilled(pdzg);
    for (int idz = 0; idz < c; idz++)
        agSoln[idz] = *(float *)(*(char **)(pdzg + 0x8) + idz * 0x28 + 0xC);
    CStackFrame_Destructor(frame, 2);
}
