struct SOVT { char pad[0x298]; short delta; short idx; void (*fn)(void *, int, int); };
struct SO { char pad0[0xC]; SOVT *vt; };
struct SEQNODE { char pad0[0xA4]; int cattach; SO *aso[4]; int an1[4]; int an2[4]; };
extern "C" int FIsBasicDerivedFrom(void *, int);

extern "C" void AttachSeqnodeObject(SEQNODE *pseqnode, SO *pso, int n1, int n2)
{
    if (FIsBasicDerivedFrom(pso, 0x33) == 0)
        return;
    for (int iattach = 0; iattach < pseqnode->cattach; iattach++) {
        if (pseqnode->aso[iattach] == pso)
            return;
    }
    unsigned cattach = pseqnode->cattach;
    if (cattach < 4) {
        pseqnode->an1[cattach] = n1;
        pseqnode->an2[pseqnode->cattach] = n2;
        pseqnode->aso[pseqnode->cattach] = pso;
        pseqnode->cattach++;
        pso->vt->fn((char *)pso + pso->vt->delta, n1, n2);
    }
}
