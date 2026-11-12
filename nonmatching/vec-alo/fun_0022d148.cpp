// SPDX-License-Identifier: GPL-3.0-or-later
#include "vu0inline.h"
#include "sly2.h"

struct RATENODE { char pad0[0x40]; MATRIX4 matWorld; char pad1[0x98 - 0x80]; short type; short pad2[2]; RATENODE *pnext; };
extern "C" {
void GetXfLocalRateMatrix(MATRIX4 *, RATENODE *);
void InvertMatrix4Affine(MATRIX4 *, MATRIX4 *);
void __ml__FRC7MATRIX4T0(MATRIX4 *, const MATRIX4 *, const MATRIX4 *);
}

static inline void AddMatrix(MATRIX4 *sum, const MATRIX4 &first, const MATRIX4 &second)
{
    for (int row = 0; row < 4; row++)
        sum->row[row] = VectorAdd(first.row[row], second.row[row]);
}

extern "C" MATRIX4 *func_0022D148(MATRIX4 *pmatOut, RATENODE *pfirst, RATENODE *pend)
{
    MATRIX4 local;
    MATRIX4 rate;
    MATRIX4 sum;
    MATRIX4 product;
    MATRIX4 inverse;
    memset(pmatOut, 0, sizeof(MATRIX4));
    for (RATENODE *pnode = pfirst; pnode != pend; pnode = pnode->pnext) {
        switch (pnode->type) {
        case 0:
        case 3:
        case 10:
        case 12:
        case 15:
        case 19:
            break;
        default:
            GetXfLocalRateMatrix(&rate, pnode);
            local = rate;
            MATRIX4 *pproduct = &product;
            if (pnode->pnext != 0) {
                __ml__FRC7MATRIX4T0(pproduct, &pnode->pnext->matWorld, &local);
                InvertMatrix4Affine(&inverse, &pnode->matWorld);
                __ml__FRC7MATRIX4T0(&sum, pproduct, &inverse);
                AddMatrix(&rate, *pmatOut, sum);
                memcpy(pmatOut, &rate, sizeof(MATRIX4));
            } else {
                InvertMatrix4Affine(pproduct, &pnode->matWorld);
                __ml__FRC7MATRIX4T0(&sum, &local, pproduct);
                AddMatrix(&rate, *pmatOut, sum);
                memcpy(pmatOut, &rate, sizeof(MATRIX4));
            }
            break;
        }
    }
    if (pend != 0) {
        InvertMatrix4Affine(&sum, &pend->matWorld);
        __ml__FRC7MATRIX4T0(&rate, &sum, pmatOut);
        memcpy(pmatOut, &rate, sizeof(MATRIX4));
    }
    return pmatOut;
}
