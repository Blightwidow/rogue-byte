// SPDX-License-Identifier: GPL-3.0-or-later
struct CRef { int tagk; int n; };
struct CFrame {
    char pad0[8];
    int cpframeParent;
    CFrame *pframeParent;
    char pad1[0x14];
    int unk0x24;
    void *PrefFindBinding(unsigned, int);
};
extern "C" CRef *CRef_CopyConstruct(CRef *, void *);
extern "C" CRef *func_00125510(CRef *pret, int carg, CRef *aref, CFrame *pframe)
{
    CRef * result;
    if (pframe != 0 && pframe->cpframeParent == 1) {
        CFrame *pframeCur = pframe;
        while (pframeCur->unk0x24 == 0) {
            pframeCur = pframeCur->pframeParent;
            if (pframeCur == 0 || pframeCur->cpframeParent != 1)
                goto fail;
        }
        void *pvBinding = pframeCur->pframeParent->PrefFindBinding(aref[0].n, 1);
        if (pvBinding != 0) {
            CRef_CopyConstruct(pret, pvBinding);
            { result = pret; goto done; }
        }
    }
fail:
    pret->tagk = 0x19;
    pret->n = 0x86;
    { result = pret; goto done; }
done:
    return result;
}
