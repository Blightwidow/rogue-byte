#include "sly2.h"
struct CLQ { float a; int b; float c; };
struct SND {
    int unk0;
    int unk4;
    char pad0[4];
    int vtable;
    int unk10;
    char pad1[8];
    char heapA[0x18];
    char heapB[0x18];
    char dl[0xC];
    int unk58;
    char pad2[12];
    int unk68;
    char pad3[20];
    CLQ fitA;
    char pad4[4];
    CLQ fitB;
    char pad5[104];
    int unk104;
    char pad6[12];
    CLQ clqA;
    CLQ clqB;
    CLQ clqC;
    char pad7[200];
    int unk200;
    char pad8[4];
    int words[8];
    int unk228;
};
extern "C" {
extern char D_002CA510[];
extern float RO_FLT_002A83B8[2];
extern float RO_FLT_002A83C0[2];
void CreateSlotheapSwAlign(void *, int, int, int);
void InitDl__FP2DLi(void *, int);
void FitClq__FffffP3CLQ(float, float, float, float, CLQ *);
SND *func_001FCD38(SND *psnd)
{
    psnd->unk0 = 0;
    psnd->unk4 = 0;
    psnd->vtable = (int)D_002CA510;
    CreateSlotheapSwAlign(psnd->heapA, 0x70, 0x80, 0x10);
    CreateSlotheapSwAlign(psnd->heapB, 0x3C0, 0x10, 0x10);
    psnd->unk200 = 0;
    int *word = psnd->words;
    int count = 7;
    do { *word++ = 0; } while (--count != -1);
    psnd->unk228 = 0;
    float half = 0.5f;
    InitDl__FP2DLi(psnd->dl, 0x38);
    CLQ *clqC = &psnd->clqC;
    CLQ *clqB = &psnd->clqB;
    CLQ *clqA = &psnd->clqA;
    psnd->clqC.a = 1.0f;
    psnd->unk68 = 3;
    psnd->unk10 = 0;
    psnd->unk104 = 0;
    clqC->b = 0;
    clqC->c = 0.25f;
    psnd->clqB.a = 1.0f;
    clqB->b = 0;
    clqB->c = 0.25f;
    psnd->clqA.a = 3.0f;
    clqA->b = 0;
    float seed = *(float *)&clqA->b;
    FitClq__FffffP3CLQ((clqA->c = 0.25f, seed), RO_FLT_002A83B8[1], half, RO_FLT_002A83B8[0], &psnd->fitA);
    FitClq__FffffP3CLQ(seed, RO_FLT_002A83C0[1], half, RO_FLT_002A83C0[0], &psnd->fitB);
    psnd->unk58 = 0;
    return psnd;
}
}
