#include "sly2.h"
struct CRV_1DE5D8;
struct CRVVT_1DE5D8 { char pad[0xF8]; short delta; short pad2; QW *(*pfnMatrix)(CRV_1DE5D8 *); };
struct CRV_1DE5D8 { char pad0[0xC]; CRVVT_1DE5D8 *pvt; char pad10[0xE8 - 0x10]; int ccv; char padEC[8]; QW *apos; };
struct SEG_1DE5D8 { float s, v, a, dt, t; };
struct PARAMS_1DE5D8 { char bytes[0x10]; };
struct PARAMSF_1DE5D8 { float u, speed, period; int mode; float sAccel, sDecel; };
struct END_1DE5D8 {
    int oid;
    int kind;
    int pad8[2];
    union {
        QW pos;
        struct {
            CRV_1DE5D8 *pcrv;
            float s;
            union {
                PARAMS_1DE5D8 params;
                struct { int cseg; SEG_1DE5D8 aseg[6]; int iseg; };
            };
        };
    };
};
struct BEAM_1DE5D8 { END_1DE5D8 aend[2]; char pad[0x10]; };
struct ALLOCREQ_1DE5D8 { int cb; int cbAlign; };
struct GEOM_1DE5D8 { char pad[0x14]; QW *apos; };
struct LASERSO_1DE5D8 {
    int xf;
    void *plaser;
    int pad8;
    int field0C;
    unsigned long grf;
    char pad18[0x78 - 0x18];
    int cpos;
    QW *apos;
    char pad80[0x10];
    GEOM_1DE5D8 geom;
};
struct LASER_1DE5D8 {
    char pad0[0x18];
    int field18;
    char pad1C[0x28 - 0x1C];
    unsigned long grfSo;
    char pad30[0x40 - 0x30];
    unsigned int flags;
    char pad44[0x60 - 0x44];
    int xf;
    char pad64[0xE0 - 0x64];
    int fHasSo;
    LASERSO_1DE5D8 *pso;
    char padE8[0x198 - 0xE8];
    int cbeam;
    BEAM_1DE5D8 *abeam;
};
struct LOCALS_1DE5D8 {
    PARAMSF_1DE5D8 params;
    char pad18[8];
    QW mat[4];
    QW posMin;
    QW posMax;
};
extern "C" {
void RemoveSoGeomsFromOxa(LASER_1DE5D8 *);
void AddSoGeomsToOxa(LASER_1DE5D8 *);
void *PloFindSwObject_thunk(void *, int, int, void *);
int FIsBasicDerivedFrom(void *, int);
float SMaxCrv(void *);
void GetPathPosFromS(void *, QW *, void *, float);
QW PosLoWorld(void *);
QW ConvertXfPos(int, int, QW);
void *PvAllocSwClearImpl__Fi(ALLOCREQ_1DE5D8 *);
void CloneGeom(int *, void *, GEOM_1DE5D8 *);
extern char B_003DD490[];
extern float D_002C3610;
extern const QW RO_002A2DF0;
extern const QW RO_002A2E00;
}

extern "C" void BuildLaserBeams(LASER_1DE5D8 *plaser)
{
    LOCALS_1DE5D8 l;
    RemoveSoGeomsFromOxa(plaser);
    l.posMin = RO_002A2DF0;
    l.posMax = RO_002A2E00;
    for (int ibeam = 0; ibeam < plaser->cbeam; ibeam++) {
        BEAM_1DE5D8 *pbeam = &plaser->abeam[ibeam];
        for (unsigned int iend = 0; iend < 2; iend++) {
            END_1DE5D8 *pend = &pbeam->aend[iend];
            pend->kind = -1;
            if (pend->oid != -1) {
                void *plo = PloFindSwObject_thunk(B_003DD490, 1, pend->oid, plaser);
                if (plo != 0) {
                    if (FIsBasicDerivedFrom(plo, 0xA) != 0) {
                        *(PARAMS_1DE5D8 *)&l.params = pend->params;
                        int fReverse = 0;
                        if (l.params.u < 0.0f)
                            l.params.u = 0.0f;
                        else if (1.0f < l.params.u)
                            l.params.u = 1.0f;
                        if (l.params.speed < 0.0f) {
                            fReverse = 1;
                            l.params.speed = -l.params.speed;
                        }
                        l.params.period = __builtin_fabsf(l.params.period);
                        if (l.params.mode != 8 && l.params.mode != 0x10 && l.params.mode != 0)
                            l.params.mode = 8;
                        float sMax = SMaxCrv(plo);
                        if (0.0f < l.params.period)
                            l.params.speed = sMax / l.params.period;
                        else if (0.0f < l.params.speed)
                            l.params.period = sMax / l.params.speed;
                        float s = l.params.u * sMax;
                        if (l.params.speed == 0.0f || l.params.period == 0.0f) {
                            pend->kind = 0;
                            GetPathPosFromS(plo, &pend->pos, 0, s);
                        } else {
                            pend->pcrv = (CRV_1DE5D8 *)plo;
                            pend->kind = 1;
                            pend->s = s;
                            memset(pend->aseg, 0, sizeof(pend->aseg));
                            switch (l.params.mode) {
                            case 8:
                                pend->cseg = 1;
                                if (fReverse) {
                                    pend->aseg[0].s = sMax;
                                    pend->aseg[0].v = -l.params.speed;
                                    pend->aseg[0].t = (1.0f - l.params.u) * l.params.period;
                                } else {
                                    pend->aseg[0].v = l.params.speed;
                                    pend->aseg[0].t = l.params.u * l.params.period;
                                }
                                pend->aseg[0].dt = l.params.period;
                                pend->iseg = 0;
                                break;
                            case 0:
                                pend->cseg = 2;
                                if (fReverse) {
                                    pend->aseg[0].s = sMax;
                                    pend->aseg[0].v = -l.params.speed;
                                    pend->aseg[0].t = (1.0f - l.params.u) * l.params.period;
                                } else {
                                    pend->aseg[0].v = l.params.speed;
                                    pend->aseg[0].t = l.params.u * l.params.period;
                                }
                                pend->aseg[0].dt = l.params.period;
                                pend->aseg[1].s = fReverse ? 0.0f : sMax;
                                pend->aseg[1].t = 0.0f;
                                pend->aseg[1].v = 0.0f;
                                pend->iseg = 0;
                                break;
                            case 0x10: {
                                if (D_002C3610 * 3.0f <= sMax)
                                    l.params.sAccel = D_002C3610;
                                else
                                    l.params.sAccel = sMax * 0.2f;
                                float sAccel2 = l.params.sAccel + l.params.sAccel;
                                l.params.sDecel = sMax - l.params.sAccel;
                                float dtAccel = sAccel2 * l.params.period / (sMax + sAccel2);
                                float dtCruise = l.params.period - (dtAccel + dtAccel);
                                l.params.speed = (sMax - sAccel2) / dtCruise;
                                float accel = l.params.speed * l.params.speed / sAccel2;
                                pend->cseg = 6;
                                pend->aseg[0].dt = dtAccel;
                                pend->aseg[0].a = accel;
                                pend->aseg[1].s = l.params.sAccel;
                                pend->aseg[1].dt = dtCruise;
                                pend->aseg[1].v = l.params.speed;
                                pend->aseg[2].s = l.params.sDecel;
                                pend->aseg[2].dt = dtAccel;
                                pend->aseg[2].v = l.params.speed;
                                pend->aseg[2].a = -accel;
                                pend->aseg[3].s = sMax;
                                pend->aseg[3].dt = dtAccel;
                                pend->aseg[3].a = -accel;
                                pend->aseg[4].s = l.params.sDecel;
                                pend->aseg[4].dt = dtCruise;
                                pend->aseg[4].v = -l.params.speed;
                                pend->aseg[5].s = l.params.sAccel;
                                pend->aseg[5].dt = dtAccel;
                                pend->aseg[5].a = accel;
                                pend->aseg[5].v = -l.params.speed;
                                pend->iseg = 0;
                                do {
                                    SEG_1DE5D8 *pseg = &pend->aseg[pend->iseg];
                                    if (s < pseg[1].s) {
                                        float t = (s - pseg->s) * 2.0f / (pseg->v + pseg[1].v);
                                        if (fReverse) {
                                            pend->iseg = 5 - pend->iseg;
                                            pend->aseg[pend->iseg].t = pend->aseg[pend->iseg].dt - t;
                                        } else {
                                            pseg->t = t;
                                        }
                                        break;
                                    }
                                } while (++pend->iseg < 3);
                                break;
                            }
                            }
                            unsigned int flags = plaser->flags;
                            if ((flags ^ 1) & 1)
                                *(unsigned int *)flags |= 2;
                            else
                                plaser->flags = flags | 2;
                        }
                    } else if (FIsBasicDerivedFrom(plo, 3) != 0 || FIsBasicDerivedFrom(plo, 0x30) != 0) {
                        pend->kind = 0;
                        pend->pos = PosLoWorld(plo);
                    }
                }
            }
            if (pend->kind == -1) {
                pend->kind = 0;
                pend->pos = PosLoWorld(plaser);
            }
            if (pend->kind == 0) {
                QW pos;
                asm("lqc2 vf1, %3\n\tlqc2 vf2, %0\n\tlqc2 vf6, %1\n\tvmini.xyz vf2, vf2, vf1\n\tvmax.xyz vf6, vf6, vf1\n\tsqc2 vf2, %0\n\tqmfc2.ni %2, vf1\n\tsqc2 vf6, %1"
                    : "+m"(l.posMin), "+m"(l.posMax), "=r"(pos) : "m"(pend->pos));
                pend->pos = ConvertXfPos(0, plaser->xf, pos);
            } else if (pend->kind == 1) {
                CRV_1DE5D8 *pcrv = pend->pcrv;
                QW *pmat = pcrv->pvt->pfnMatrix((CRV_1DE5D8 *)((char *)pcrv + pcrv->pvt->delta));
                QW m0 = pmat[0];
                l.mat[0] = m0;
                QW m1 = pmat[1];
                l.mat[1] = m1;
                QW m2 = pmat[2];
                l.mat[2] = m2;
                QW m3 = pmat[3];
                l.mat[3] = m3;
                CRV_1DE5D8 *pcrvCv = pend->pcrv;
                if (0 < pcrvCv->ccv) {
                    asm volatile("qmtc2.ni %0, vf4\n\tqmtc2.ni %1, vf5\n\tqmtc2.ni %2, vf3\n\tqmtc2.ni %3, vf2" : : "r"(m1), "r"(m0), "r"(m2), "r"(m3));
                    for (int icv = 0; icv < pcrvCv->ccv; icv++) {
                        asm volatile("lqc2 vf6, %1\n\tlqc2 vf1, %2\n\tvmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf4, vf1y\n\tvmaddaz.xyz ACC, vf3, vf1z\n\tvmaddw.xyz vf1, vf2, vf0w\n\tvmax.xyz vf6, vf6, vf1\n\tsqc2 vf6, %1\n\tlqc2 vf6, %0\n\tvmini.xyz vf6, vf6, vf1\n\tsqc2 vf6, %0"
                                     : "+m"(l.posMin), "+m"(l.posMax) : "m"(pcrvCv->apos[icv]));
                    }
                }
            }
        }
    }
    if (plaser->cbeam != 0) {
        ALLOCREQ_1DE5D8 *preq = (ALLOCREQ_1DE5D8 *)&l.params;
        plaser->fHasSo = 1;
        preq->cb = 0xB0;
        preq->cbAlign = 0x10;
        LASERSO_1DE5D8 *pso = (LASERSO_1DE5D8 *)PvAllocSwClearImpl__Fi(preq);
        plaser->pso = pso;
        pso->xf = plaser->xf;
        pso->plaser = plaser;
        pso->cpos = 2;
        pso->field0C = plaser->field18;
        pso->grf |= 0x8000L << 33;
        preq->cbAlign = 0x10;
        preq->cb = 0x20;
        pso->apos = (QW *)PvAllocSwClearImpl__Fi(preq);
        CloneGeom(&pso->cpos, 0, &pso->geom);
        pso->geom.apos[0] = l.posMin;
        pso->geom.apos[1] = l.posMax;
        pso->apos[0] = ConvertXfPos(0, plaser->xf, l.posMin);
        pso->apos[1] = ConvertXfPos(0, plaser->xf, l.posMax);
    }
    if ((int)(plaser->grfSo >> 60) & 1)
        AddSoGeomsToOxa(plaser);
}
