// SPDX-License-Identifier: GPL-3.0-or-later
typedef void (*VCall_k02)(void *, void *, int, float, float);
struct VT_k02 { char pad[0x18]; short delta; char pad2[2]; VCall_k02 fn; };
struct ENT_k02 { int f0; void *psource; int f8; float fC; };
struct TWOVEC_k02 { float first[4]; float second[4]; };
extern "C" {
void *PchnFindAseg(void *, void *, int, int);
void EnsureAsegBlendDynamic(void *, int, int, void *, int, int, int, void *);
}
extern "C" void PostJtLoadPipe(char *pthis)
{
    ENT_k02 *pentry = (ENT_k02 *)(pthis + 0x50);
    int countdown = 1;
    do {
        char *psource = (char *)pentry->psource;
        if (psource != 0) {
            char *pobj = (char *)PchnFindAseg(psource, *(void **)pthis, 1, 1);
            if (pobj != 0) {
                TWOVEC_k02 vecs;
                VT_k02 *vt = *(VT_k02 **)(*(char **)(pobj + 4));
                vt->fn((char *)*(char **)(pobj + 4) + vt->delta, &vecs, 0, 0.0f, 1.0f);
                vt = *(VT_k02 **)(*(char **)(pobj + 4));
                vt->fn((char *)*(char **)(pobj + 4) + vt->delta, vecs.second, 0, *(float *)(psource + 0x74), 1.0f);
                pentry->fC = (vecs.first[2] - vecs.second[2]) / *(float *)(psource + 0x74);
            }
        }
        pentry++;
        countdown--;
    } while (countdown >= 0);
    EnsureAsegBlendDynamic(*(void **)pthis, 0x10, 2, pthis + 0x50, 0, 0, 0, pthis + 0x70);
}
