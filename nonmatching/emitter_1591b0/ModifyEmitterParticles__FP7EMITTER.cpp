// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct EMITFOLLOW { void *ploTarget; };
struct EMITB_159A20 { u8 unknown_0x0[0x4]; s32 fFree; EMITFOLLOW *pfollow; };
struct EMITBLOCK {
    u8 unknown_0x0[0x1080];
    s32 iSlot;
    s32 cparticle;
    u8 unknown_0x1088[0x8];
    EMITBLOCK *pnext;
};
struct PARTBUF { VECTOR avec[0x84]; };
struct EMITLISTOWNER { u8 unknown_0x0[0x448]; EMITBLOCK *pblockFirst; };
struct EMITTER {
    u8 unknown_0x0[0xE4];
    EMITB_159A20 *pemitb;
    u8 unknown_0xE8[0x58];
    f32 sRadius;
    u8 unknown_0x144[0xC];
    EMITLISTOWNER *powner;
};
union VU_SCALE { QW q; VECTOR v; };

extern "C" {
QW PosLoWorld(void *);
f32 GModPositive__Fff(f32, f32);
}

static inline QW MinusOneScalar()
{
    VU_SCALE minusOne;
    minusOne.q = VectorFromFloat(-1.0f);
    return minusOne.q;
}

extern "C" void ModifyEmitterParticles__FP7EMITTER(EMITTER *pemitter)
{
    VECTOR vecScale;
    VECTOR vecMin;
    VECTOR vecMax;
    VECTOR vecDelta;
    VECTOR *pvec;
    if (pemitter->sRadius > 0.0001f) {
        vecScale.z = pemitter->sRadius;
        vecScale.y = pemitter->sRadius;
        vecScale.x = pemitter->sRadius;
        void *plo = pemitter->pemitb->pfollow->ploTarget;
        if (plo != 0) {
            QW pos = PosLoWorld(plo);
            *(QW *)&vecMin = VectorSub(pos, *(QW *)&vecScale);
            *(QW *)&vecMax = VectorAdd(PosLoWorld(pemitter->pemitb->pfollow->ploTarget), *(QW *)&vecScale);
        } else {
            *(QW *)&vecMin = VectorScaleX(*(QW *)&vecScale, MinusOneScalar());
            *(QW *)&vecMax = *(QW *)&vecScale;
        }
        f32 sRange = 2.0f * pemitter->sRadius;
        vecScale.z = sRange;
        vecScale.y = sRange;
        vecScale.x = sRange;
        if (pemitter->pemitb->fFree == 0) {
            if (pemitter->powner != 0) {
                for (EMITBLOCK *pblock = pemitter->powner->pblockFirst; pblock != 0; pblock = pblock->pnext) {
                    s32 i = 0;
                    pvec = ((PARTBUF *)pblock)[pblock->iSlot].avec;
                    if (pblock->cparticle > 0) {
                        do {
                            if (pvec->x < vecMin.x || vecMax.x < pvec->x) {
                                vecDelta.x = (vecMin.x + GModPositive__Fff(pvec->x - vecMin.x, vecScale.x)) - pvec->x;
                                pvec->x = pvec->x + vecDelta.x;
                            }
                            if (pvec->y < vecMin.y || vecMax.y < pvec->y) {
                                vecDelta.y = (vecMin.y + GModPositive__Fff(pvec->y - vecMin.y, vecScale.y)) - pvec->y;
                                pvec->y = pvec->y + vecDelta.y;
                            }
                            if (pvec->z < vecMin.z || vecMax.z < pvec->z) {
                                vecDelta.z = (vecMin.z + GModPositive__Fff(pvec->z - vecMin.z, vecScale.z)) - pvec->z;
                                pvec->z = pvec->z + vecDelta.z;
                            }
                            i++;
                            pvec++;
                        } while (i < pblock->cparticle);
                    }
                }
            }
        }
    }
}
