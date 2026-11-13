#include "so.h"

struct PRIPG : SO {
    /* 0x150 */ s32 unk150;
};
void InitDl(DL *, int);
extern "C" {
void InitSo(SO *);
void func_001A6CA8(SO *, int);
void EnsureSoOxa(SO *);
void SetSoNoXpsAll(SO *, int);
}
extern "C" void Pripg_InitSo(PRIPG *so)
{
    InitSo(so);
    InitDl((DL *)((char *)so + 0x15C), 0xC);
    func_001A6CA8(so, 1);
    unsigned bits = so->grfSw;
    if (!(bits & 1)) {
        *(unsigned *)bits = (*(unsigned *)bits & 1) | 0xE;
    } else {
        so->grfSw = (bits & 1) | 0xE;
    }
    so->grfso &= ~0x800000000UL;
    if (so->unk150 == 1) {
        EnsureSoOxa(so);
        SetSoNoXpsAll(so, 1);
    }
}
