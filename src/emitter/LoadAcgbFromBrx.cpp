// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct KGB_k02 { float t; float g; float a; float b; };
struct ACGB_k02 { int unk0; int ckgb; KGB_k02 *akgb; };
struct ALLOCREQ_k02 { int cb; int cbAlign; };
extern unsigned short U16Read__18CBinaryInputStream(void *);
extern float F32Read__18CBinaryInputStream(void *);
extern void *PvAllocSwClearImpl__Fi(void *);
}
extern "C" void LoadAcgbFromBrx(ACGB_k02 *pacgb, void *pbis)
{
    int ikgb = 0;
    int ckgb = U16Read__18CBinaryInputStream(pbis);
    ALLOCREQ_k02 allocreq;
    allocreq.cb = ckgb << 4;
    allocreq.cbAlign = 0x10;
    pacgb->ckgb = ckgb;
    pacgb->akgb = (KGB_k02 *)PvAllocSwClearImpl__Fi(&allocreq);
    while (ikgb < pacgb->ckgb) {
        KGB_k02 *pkgb = &pacgb->akgb[ikgb];
        ikgb++;
        int frame = U16Read__18CBinaryInputStream(pbis);
        pkgb->t = (float)frame * 0.016666668f;
        pkgb->g = F32Read__18CBinaryInputStream(pbis);
        pkgb->a = F32Read__18CBinaryInputStream(pbis);
        pkgb->b = F32Read__18CBinaryInputStream(pbis);
    }
}
