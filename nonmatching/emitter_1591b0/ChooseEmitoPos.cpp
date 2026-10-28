#include "sly2.h"
struct Vec3 { float x, y, z; };
struct Tri { int a, b, c; float area; };
struct Mesh { int pad0; QW *apos; int ctri; Tri *atri; QW *anormal; float sTotalArea; };
struct Locals { QW a, b, c, scratch[4]; QW normalTmp; QW posSave; };
extern "C" {
extern QW g_2a2da0;
extern char B_002DDF40[];
float GRandInRange(float, float);
void GetPathPosFromS(float, void *, QW *, QW *);
char *PmatLoWorld(void *);
void ChooseEmitoPos(char *pemitb, int iParticle, int cParticle, QW *pposRet, QW *pnormalRet)
{
    Locals l;
    char *pemito = pemitb + 0x10;
    float *plm = (float *)(pemitb + 0x24);
    int emitok = *(int *)(pemitb + 0x10);
    switch (emitok) {
    case 0:
        *pposRet = *(QW *)(pemito + 0x20);
        break;
    case 1: {
        float *pbox = *(float **)(pemito + 0x20);
        ((float *)pposRet)[0] = GRandInRange(pbox[0], pbox[4]);
        ((float *)pposRet)[1] = GRandInRange(pbox[1], pbox[5]);
        ((float *)pposRet)[2] = GRandInRange(pbox[2], pbox[6]);
        break;
    }
    case 2: {
        char *pemitref = *(char **)(pemitb + 8);
        char *pcrv = *(char **)(pemitref + 4);
        if (pcrv == 0) {
            ((int *)pposRet)[0] = 0;
            ((int *)pposRet)[2] = 0;
            ((int *)pposRet)[1] = 0;
            return;
        }
        float sTotal = (*(float **)(pcrv + 0xF0))[*(int *)(pcrv + 0xE8) - 1];
        float ds = sTotal / (float)cParticle;
        float sStart = (float)iParticle * ds;
        float s = GRandInRange(sStart, sStart + ds);
        int emitnk = *(int *)(pemito + 4);
        if (emitnk == 2) {
            GetPathPosFromS(s, pcrv, pposRet, pnormalRet);
            goto normalize;
        } else if (emitnk == 3) {
            GetPathPosFromS(s, pcrv, pposRet, &l.a);
            asm("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvopmula.xyz ACC, vf1, vf2\n\tvopmsub.xyz vf1, vf2, vf1\n\tsqc2 vf1, %0" : "=m"(*pnormalRet) : "m"(*(QW *)(pemitb + 0x40)), "m"(l.a));
            goto normalize;
        } else {
            GetPathPosFromS(s, pcrv, pposRet, 0);
        }
        break;
    }
    case 3: {
        float gPick = GRandInRange(0.0f, 1.0f);
        Mesh *pmesh = *(Mesh **)(pemito + 0x20);
        int i = 0;
        Tri *ptri = pmesh->atri;
        if (pmesh->ctri > 0) {
            float gLeft = gPick * pmesh->sTotalArea - ptri->area;
            Tri *ppick = ptri;
            while (!(gLeft <= 0.0f)) {
                i++;
                if (!(i < pmesh->ctri))
                    break;
                gLeft -= ptri[i].area;
                ppick = &ptri[i];
            }
            ptri = ppick;
        }
        l.a = pmesh->apos[ptri->a];
        l.b = pmesh->apos[ptri->b];
        l.c = pmesh->apos[ptri->c];
        float gA = GRandInRange(0.0f, 1.0f);
        float gRest = 1.0f - gA;
        float gB = GRandInRange(0.0f, gRest);
        gRest = gRest - gB;
        QW qa, qb, qc;
        asm("mfc1 %0, %1" : "=r"(qa) : "f"(gA));
        asm("mfc1 %0, %1" : "=r"(qb) : "f"(gB));
        asm("mfc1 %0, %1" : "=r"(qc) : "f"(gRest));
        asm("qmtc2.ni %1, vf6" : "=m"(l.scratch[0]) : "r"(qa));
        asm("qmtc2.ni %0, vf5" : : "r"(qb));
        asm("qmtc2.ni %0, vf4" : : "r"(qc));
        asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tlqc2 vf1, %3\n\tvmulax.xyzw ACC, vf2, vf6x\n\tvmaddax.xyzw ACC, vf3, vf5x\n\tvmaddx.xyzw vf2, vf1, vf4x\n\tsqc2 vf2, %0" : "=m"(*pposRet) : "m"(l.a), "m"(l.b), "m"(l.c));
        if (*(int *)(pemito + 4) == 5) {
            QW *an = pmesh->anormal;
            asm("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tlqc2 vf1, %3\n\tvmulax.xyzw ACC, vf2, vf6x\n\tvmaddax.xyzw ACC, vf3, vf5x\n\tvmaddx.xyzw vf2, vf1, vf4x\n\tsqc2 vf2, %0" : "=m"(*pnormalRet) : "m"(an[ptri->a]), "m"(an[ptri->b]), "m"(an[ptri->c]));
            goto normalize;
        }
        break;
    }
    }
    {
        int emitnk = *(int *)(pemito + 4);
        switch (emitnk) {
        case 0:
            *pnormalRet = *(QW *)(pemito + 0x30);
            break;
        case 1:
            asm("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(*pnormalRet) : "m"(*pposRet), "m"(*(QW *)(pemito + 0x30)));
            break;
        case 4: {
            char *pref = *(char **)(pemitb + 8);
            void *palo = *(void **)pref;
            if (palo != 0) {
                char *pmat = PmatLoWorld(palo);
                asm("lqc2 vf4, %1\n\tlqc2 vf3, %2\n\tlqc2 vf5, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tvmulax.xyz ACC, vf5, vf4x\n\tvmadday.xyz ACC, vf1, vf4y\n\tvmaddz.xyz vf4, vf2, vf4z\n\tlqc2 vf2, %6\n\tlqc2 vf1, %7\n\tvmul.xyzw vf7, vf2, vf4\n\tvmaxw.xyzw vf8, vf0, vf0w\n\tvmul.xyzw vf6, vf1, vf4\n\tvmul.xyzw vf5, vf3, vf4\n\tvadday.x ACC, vf7, vf7y\n\tvmaddz.x vf2, vf8, vf7z\n\tvaddax.y ACC, vf6, vf6x\n\tvmaddz.y vf2, vf8, vf6z\n\tvaddax.z ACC, vf5, vf5x\n\tvmaddy.z vf2, vf8, vf5y\n\tsqc2 vf2, %0" : "=m"(*pnormalRet) : "m"(*(QW *)(pemito + 0x30)), "m"(*(QW *)(pmat + 0x20)), "m"(*(QW *)(B_002DDF40 + 0x60)), "m"(*(QW *)(B_002DDF40 + 0x80)), "m"(*(QW *)(B_002DDF40 + 0x70)), "m"(*(QW *)pmat), "m"(*(QW *)(pmat + 0x10)));
            } else {
                asm("lqc2 vf2, %1\n\tlqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf1, %4\n\tvmulax.xyz ACC, vf4, vf2x\n\tvmadday.xyz ACC, vf1, vf2y\n\tvmaddz.xyz vf2, vf3, vf2z\n\tsqc2 vf2, %0" : "=m"(*pnormalRet) : "m"(*(QW *)(pemito + 0x30)), "m"(*(QW *)(B_002DDF40 + 0x60)), "m"(*(QW *)(B_002DDF40 + 0x80)), "m"(*(QW *)(B_002DDF40 + 0x70)));
            }
            break;
        }
        default:
            *pnormalRet = g_2a2da0;
            break;
        }
    }
normalize:
    QW unit = g_2a2da0;
    float length;
    asm("lqc2 vf3, %1\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(length) : "m"(*pnormalRet));
    if (length < 0.0001f) {
        l.normalTmp = unit;
    } else {
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q\n\tsqc2 vf2, %0" : "=m"(l.normalTmp));
    }
    *pnormalRet = l.normalTmp;
    l.posSave = *pposRet;
    float g = GRandInRange(*(float *)(pemito + 0x14), plm[1]);
    QW gq;
    asm("mfc1 %0, %1" : "=r"(gq) : "f"(g));
    asm("qmtc2.ni %1, vf1\n\tlqc2 vf3, %2\n\tvmulx.xyzw vf2, vf3, vf1x\n\tsqc2 vf1, %3\n\tlqc2 vf3, %4\n\tvadd.xyzw vf1, vf3, vf2\n\tsqc2 vf1, %0" : "=m"(*pposRet) : "r"(gq), "m"(l.normalTmp), "m"(l.scratch[0]), "m"(l.posSave));
}
}
