struct ASEG { char pad[0x74]; float tMax; float svtMaster; };
struct XF { char pad[0x80]; float tMin; float tMax; float *ptCurrent; };
struct ALO;
struct ACTVT { char pad[0x20]; short delta; short idx; void (*fn)(void *); };
struct ACT { char pad0[4]; ALO *palo; XF *pxf; char pad1[0xC]; ACTVT *vt; char pad2[0xC]; ACT *pactNext; };
struct ASEGA {
    char pad0[0x14]; ASEG *paseg; char pad1[4]; float tLocal; float tTarget; char pad2[0x10];
    ACT *pactFirst; char pad3[8]; float svtLocal; float svt; float svtMaster; float factor;
};
extern "C" int FAsegaGone(ASEGA *);
extern "C" void FWrapAsegaTime(ASEGA *, float *, float *);
void UpdateAsegaIeaCur__FP5ASEGA(ASEGA *);
extern "C" int FActDrivesXf(ACT *);
extern "C" void WakeXf(ALO *, XF *);
extern "C" void SnapAsega(ASEGA *, int);

extern "C" void SeekAsega(ASEGA *pasega, int seek, float dtLocal, float svtLocal)
{
    if (FAsegaGone(pasega))
        return;
    pasega->svt = svtLocal;
    pasega->svtLocal = svtLocal * pasega->svtMaster * pasega->factor;
    float tNew;
    switch (seek) {
    case 0: tNew = dtLocal; break;
    case 1: tNew = pasega->tLocal + dtLocal; break;
    case 2: tNew = pasega->paseg->tMax + dtLocal; break;
    }
    if (tNew != pasega->tLocal) {
        pasega->tLocal = tNew;
        FWrapAsegaTime(pasega, &pasega->tLocal, &pasega->svtLocal);
        UpdateAsegaIeaCur__FP5ASEGA(pasega);
        for (ACT *pact = pasega->pactFirst; pact != 0; pact = pact->pactNext) {
            if (!FActDrivesXf(pact))
                continue;
            float tCurrent = *pact->pxf->ptCurrent;
            if (tCurrent < pact->pxf->tMin || pact->pxf->tMax < tCurrent)
                pact->vt->fn((char *)pact + pact->vt->delta);
            WakeXf(pact->palo, pact->pxf);
        }
        SnapAsega(pasega, 0);
    }
    pasega->tTarget = pasega->tLocal;
}
