#include "sly2.h"
struct VT20 { char pad[0x20]; short delta; short index; void (*fn)(void *, void *); };
struct VT18 { char pad[0x18]; short delta; short index; void (*fn)(void *, void *, void *); };
struct VT10 { char pad[0x10]; short delta; short index; void (*fn)(void *, void *, void *); };
struct CPLCY { char pad[0xC]; char *vptr; };
struct SO { int x; };
struct CPR { int cpp; CPLCY *pcplcy; SO *pso; void *pv; };
struct CM { char pad[0x30C]; int ccpr; CPR acpr[8]; char pad2[0x390 - 0x390 + 0]; };
struct CMX { char pad[0x390]; float t; };
extern "C" void *memmove(void *, const void *, unsigned int);
extern "C" float g_2dded0;
enum CPP { CPP_dummy };
// Retail (score 9 here): everything matches except the memmove argument block. Retail builds one base
// B = (icpr << 4) + pcm, then a1 = B; a0 = B + 0x320; a1 += 0x310. This source adds the offsets first
// (addiu s0,0x320 / addu pcm). Every form that shares the base (CPR * local, &acpr[icpr] + 1, char * sums,
// pointer-walking loop) drops pcm to 15 refs (lreg dump: floor_log2(15)*15/69 = 0.652) below icpr
// (10 refs / 44-45 insns = 0.667-0.682), so global alloc swaps pcm/icpr between s1 and s2 (score 28-35).
// Initialising icpr before the ccpr > 7 test restores the order (live length 94) but moves the set (score 10).
void SetCmPolicy(CM *pcm, CPP cpp, CPLCY *pcplcy, SO *psoFocus, void *pv)
{
    if ((unsigned)pcm->ccpr > 7)
        return;
    int icpr;
    for (icpr = 0; icpr < pcm->ccpr; icpr++)
        if (pcm->acpr[icpr].cpp < cpp)
            break;
    memmove(&pcm->acpr[icpr + 1], &pcm->acpr[icpr], (pcm->ccpr - icpr) * sizeof(CPR));
    pcm->acpr[icpr].cpp = cpp;
    pcm->acpr[icpr].pcplcy = pcplcy;
    pcm->acpr[icpr].pso = psoFocus;
    pcm->acpr[icpr].pv = pv;
    pcm->ccpr = pcm->ccpr + 1;
    VT20 *vt = (VT20 *)((char *)pcplcy->vptr);
    vt->fn((char *)pcplcy + vt->delta, pv);
    if (icpr == 0) {
        if (pcm->ccpr > 1) {
            CPLCY *prev = pcm->acpr[1].pcplcy;
            VT18 *vt2 = (VT18 *)prev->vptr;
            vt2->fn((char *)prev + vt2->delta, pcm->acpr[1].pso, pcm->acpr[1].pv);
        }
        ((CMX *)pcm)->t = g_2dded0;
        VT10 *vt3 = (VT10 *)pcplcy->vptr;
        vt3->fn((char *)pcplcy + vt3->delta, psoFocus, pv);
    }
}
