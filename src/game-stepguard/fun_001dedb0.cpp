struct LASERFX { void *plo; void *paseg; void *pasega; void *pchn; };
struct LASER { char pad[0x1A0]; LASERFX afx[2]; };
struct CHN { int pad; int value; };
extern "C" {
int CploFindSwObjectsByClass(void *, int, int, void *, int, void **);
void *PasegaFindAlo(void *, int);
void *PasegaApplyAseg(void *, void *, float, float, int);
CHN *PchnFindAseg(void *, void *, int, int);
}
extern char B_003DD490[];

void func_001DEDB0(LASER *plaser)
{
    for (unsigned iend = 0; iend < 2; iend++) {
        LASERFX *pfx = &plaser->afx[iend];
        void *plo = pfx->plo;
        if (plo == 0)
            continue;
        CploFindSwObjectsByClass(B_003DD490, 2, 0x6D, plo, 1, &pfx->paseg);
        char *paseg = (char *)pfx->paseg;
        if (paseg == 0)
            continue;
        void *pasega = PasegaFindAlo(plo, *(int *)(paseg + 0x18));
        pfx->pasega = pasega;
        if (pasega == 0) {
            pasega = PasegaApplyAseg(paseg, plo, 0.0f, 1.0f, 8);
            pfx->pasega = pasega;
            if (pasega == 0)
                continue;
        }
        CHN *pchn = PchnFindAseg(paseg, plo, 0xC, 1);
        if (pchn != 0)
            pfx->pchn = (void *)pchn->value;
    }
}
