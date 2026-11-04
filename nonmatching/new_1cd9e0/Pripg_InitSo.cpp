#include "sly2.h"
struct DL;
struct SO { char pad[0x40]; unsigned *grf; char pad1[0x148 - 0x44]; unsigned long grfso; int unk150; };
void InitDl(DL *, int);
extern "C" {
void InitSo(SO *);
void func_001A6CA8(SO *, int);
void EnsureSoOxa(SO *);
void SetSoNoXpsAll(SO *, int);
}
extern "C" void Pripg_InitSo(SO *so)
{
    InitSo(so);
    InitDl((DL *)((char *)so + 0x15C), 0xC);
    func_001A6CA8(so, 1);
    unsigned bits = (unsigned)so->grf;
    if (!(bits & 1)) {
        *so->grf = (*so->grf & 1) | 0xE;
    } else {
        so->grf = (unsigned *)((bits & 1) | 0xE);
    }
    so->grfso &= ~0x800000000UL;
    if (so->unk150 == 1) {
        EnsureSoOxa(so);
        SetSoNoXpsAll(so, 1);
    }
}
