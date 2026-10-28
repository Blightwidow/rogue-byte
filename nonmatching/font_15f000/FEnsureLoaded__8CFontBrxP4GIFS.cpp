// SPDX-License-Identifier: GPL-3.0-or-later
struct QW;
struct DMAS { void AddDmaCnt(); void AddDmaRefs(int, QW *); void EndDmaCnt(); };
struct GIFS : DMAS { char pad[8]; };
struct CFontBrx {
    int fontk; char pad0[0x58 - 4];
    int cbBmp; QW *pqwBmp; char pad1[0xC0 - 0x60];
    int cbBmp2; QW *pqwBmp2; int cbClut; QW *pqwClut; char pad2[0x130 - 0xD0];
    int cb3; QW *pqw3;
    int FEnsureLoaded(GIFS *);
};
extern GIFS B_002DEA00;
extern "C" char *g_2dea4c;
int CFontBrx::FEnsureLoaded(GIFS *pgifs)
{
    int fLoad;
    if (pgifs == &B_002DEA00) {
        unsigned bit = 1u << fontk;
        unsigned loaded = *(unsigned *)(g_2dea4c + 0x2C);
        *(unsigned *)(g_2dea4c + 0x2C) = loaded | bit;
        fLoad = (loaded & bit) == 0;
    } else
        fLoad = 1;
    if (fLoad) {
        pgifs->EndDmaCnt();
        pgifs->AddDmaRefs(cbBmp, pqwBmp);
        pgifs->AddDmaRefs(cbBmp2, pqwBmp2);
        if (cbClut != 0) {
            pgifs->AddDmaRefs(cbClut, pqwClut);
            pgifs->AddDmaRefs(cb3, pqw3);
        }
        pgifs->AddDmaCnt();
    }
    return fLoad;
}
