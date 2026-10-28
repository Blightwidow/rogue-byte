// SPDX-License-Identifier: GPL-3.0-or-later
struct VT {
    char pad[0x18];
    short delta;
    short index;
    void (*fn)(void *, float, float, float *, int);
};
struct CHN {
    int unk0;
    void **panim;
};
struct ASEG {
    char pad[0x74];
    float duration;
};
struct ENT { ASEG *paseg_unused; ASEG *paseg; int u8; float speed; };
struct PIPE {
    void *pjt;
    char pad[0x4C];
    ENT aent[2];
    int unk70;
};
extern "C" {
CHN *PchnFindAseg(ASEG *, void *, int, int);
void EnsureAsegBlendDynamic(void *, int, int, void *, int, void *, void *, void *);
}
struct PIPE2;
void PostJtLoadPipe(PIPE *ppipe)
{
    float agStart[4];
    float agEnd[4];
    int i = 1;
    ENT *pent = &ppipe->aent[0];
    do {
        ASEG *paseg = pent->paseg;
        if (paseg != 0) {
            CHN *pchn = PchnFindAseg(paseg, ppipe->pjt, 1, 1);
            if (pchn != 0) {
                register void *panim asm("$7") = pchn->panim;
                VT *vt = *(VT **)panim;
                vt->fn((char *)panim + vt->delta, 0.0f, 1.0f, agStart, 0);
                register void *panim2 asm("$7") = pchn->panim;
                VT *vt2 = *(VT **)panim2;
                vt2->fn((char *)panim2 + vt2->delta, paseg->duration, 1.0f, agEnd, 0);
                pent->speed = (agStart[2] - agEnd[2]) / paseg->duration;
            }
        }
        pent++;
    } while (--i >= 0);
    EnsureAsegBlendDynamic(ppipe->pjt, 0x10, 2, &ppipe->aent[0], 0, 0, 0, &ppipe->unk70);
}
