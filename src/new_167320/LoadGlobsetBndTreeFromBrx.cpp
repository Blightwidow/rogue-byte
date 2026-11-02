// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct BIS_167870;
struct REQ_167870 { int size; int align; };
struct BND_167870 {
    float pos[3];
    float sRadius;
    float sMax;
    long bndk : 4;
    unsigned long cb : 8;
    unsigned long ib : 6;
    unsigned long fFlag : 1;
    unsigned long isubglob : 13;
    void *pv;
    int pad1C;
};
struct BNDNODE_167870 { BND_167870 abnd[4]; };
struct SUBGLOBI_167870 { signed char b; char pad[0x13]; };
struct SUBGLOB_167870 { char pad0[0xC]; unsigned grf; void *pv; char pad1[0x24 - 0x14]; BND_167870 *pbnd; };
struct GLOBSET_167870 { char pad0[0x3C]; SUBGLOBI_167870 *asubglobi; SUBGLOB_167870 *asubglob; char pad1[4]; BNDNODE_167870 *abndnode; };
extern "C" {
int S16Read__18CBinaryInputStream(BIS_167870 *);
int S8Read__18CBinaryInputStream(BIS_167870 *);
unsigned U8Read__18CBinaryInputStream(BIS_167870 *);
float F32Read__18CBinaryInputStream(BIS_167870 *);
void ReadVector__18CBinaryInputStreamP6VECTOR(BIS_167870 *, void *);
void *PvAllocSwClearImpl__Fi(REQ_167870 *);

void LoadGlobsetBndTreeFromBrx(GLOBSET_167870 *pglobset, BIS_167870 *pbis)
{
    int cnode = S16Read__18CBinaryInputStream(pbis);
    if (cnode == 0)
        return;
    REQ_167870 req;
    req.size = cnode << 7;
    req.align = 0x10;
    BNDNODE_167870 *anode = (BNDNODE_167870 *)PvAllocSwClearImpl__Fi(&req);
    for (int inode = 0; inode < cnode; inode++) {
        float sMaxLimit = 1e10f;
        BNDNODE_167870 *pnode = &anode[inode];
        for (unsigned ibnd = 0; ibnd < 4; ibnd++) {
            BND_167870 *pbnd = &pnode->abnd[ibnd];
            pbnd->bndk = S8Read__18CBinaryInputStream(pbis);
            int bndk = pbnd->bndk;
            if (bndk == -1) {
                for (; ibnd < 4; ibnd++)
                    pnode->abnd[ibnd].bndk = -1;
                break;
            }
            ReadVector__18CBinaryInputStreamP6VECTOR(pbis, pbnd);
            pbnd->sRadius = F32Read__18CBinaryInputStream(pbis);
            pbnd->sMax = F32Read__18CBinaryInputStream(pbis);
            pbnd->cb = U8Read__18CBinaryInputStream(pbis);
            pbnd->sMax = pbnd->sMax < sMaxLimit ? pbnd->sMax : sMaxLimit;
            switch (pbnd->bndk) {
            case 0: {
                int isubglob = S16Read__18CBinaryInputStream(pbis);
                SUBGLOBI_167870 *psubglobi = &pglobset->asubglobi[isubglob];
                SUBGLOB_167870 *psubglob = &pglobset->asubglob[isubglob];
                if (psubglob->grf & 0x1000) {
                    pbnd->bndk = 3;
                    pbnd->pv = psubglob->pv;
                }
                pbnd->ib = psubglobi->b;
                pbnd->fFlag = (psubglob->grf >> 11) & 1;
                pbnd->isubglob = isubglob;
                psubglob->pbnd = pbnd;
                break;
            }
            case 1:
                pbnd->pv = &anode[S16Read__18CBinaryInputStream(pbis)];
                break;
            }
        }
    }
    pglobset->abndnode = anode;
}
}
