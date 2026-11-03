typedef int QW __attribute__((mode(TI)));
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct CAND { QW pos; float g; int pad[3]; };
struct SEARCH { QW posOrigin; float yaw; int ccand; int pad18[2]; CAND acand[64]; QW posCand; };
struct OUT { QW pos; QW posOrig; };
struct SELF { char pad0[0x10]; void *palo; char pad14[0x3C - 0x14]; float g3C; char pad40[0x50 - 0x40]; OUT aout[4]; char padD0[0xD0 - 0xD0]; int fD0; };
struct LO { char pad[0x104]; LO *pnext; char pad108[0x10C - 0x108]; union { float rad; int radBits; }; };
struct CRV { char pad[0x1B4]; CRV *pnext; };
struct SO2 { char pad[0x174]; SO2 *pnext; };
struct ALO2 { char pad[0xE0]; ALO2 *pnext; int pad2; int grf; };
extern "C" {
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
int FAddSearchCand(SEARCH *);
int FIsBasicDerivedFrom(void *, int);
void FindCrvClosestPointAll(void *, QW, int, QW *, int, int, int);
float GRandInRange(float, float);
QW PosLoWorld(void *);
float RadYawSo(void *);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
void qsort(void *, int, int, int (*)(const void *, const void *));
int func_00172888(const void *, const void *);
extern char B_003DD490[];
extern ALO2 *B_003E13B4;
extern CRV *B_003E13C0;
extern CRV *B_003E13CC;
extern LO *B_003E13D8;
extern SO2 *B_003E13E4;
extern CRV *B_003E13F0;
extern LO *B_003E13FC;
extern LO *B_003E1408;
extern SO2 *B_003E1450;
extern float D_002BE5A8[2];
extern float D_002BE5B0[2];
extern const float RO_002A53D0;
extern QW g_2a2da0;
extern QW g_2a2dc0;
}

extern "C" void func_001728B0(SELF *self)
{
    SEARCH search;
    VECTOR dpos;
    VECTOR posRadius;
    int fence;

    search.posOrigin = PosLoWorld(self->palo);
    search.yaw = RadYawSo(self->palo);
    search.ccand = 0;
    for (LO *plo = B_003E13FC; plo != 0; plo = plo->pnext) {
        QW pos = PosLoWorld(plo);
        QW posFallback = g_2a2da0;
        // fence tokens: each block reads the VU registers the previous one wrote
        asm("qmtc2.ni %1, vf5\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf5\n\tsqc2 vf1, %0" : "=m"(dpos) : "r"(pos), "m"(search.posOrigin));
        dpos.z = 0.0f;
        asm("lqc2 vf3, %1\n\tvmul.xyz vf2, vf3, vf3\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z" : "=r"(fence) : "m"(dpos));
        asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fence) : "r"(fence));
        asm("qmtc2.ni %1, vf4" : "=r"(fence) : "r"(plo->radBits), "r"(fence));
        int lengthBits;
        asm("qmfc2.ni %0, vf1" : "=r"(lengthBits) : "r"(fence));
        float length;
        asm("mtc1 %1, %0" : "=f"(length) : "r"(lengthBits));
        asm("sqc2 vf4, %0" : "=m"(posRadius) : "r"(fence));
        if (length < 0.0001f)
            asm("qmtc2.ni %1, vf1" : "=r"(fence) : "r"(posFallback));
        else
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q" : "=r"(fence) : "r"(fence));
        asm("vadda.xyzw ACC, vf5, vf0\n\tvmaddx.xyzw vf1, vf1, vf4x" : "=r"(fence) : "r"(fence));
        asm("sqc2 vf1, %0" : "=m"(search.posCand) : "r"(fence));
        FAddSearchCand(&search);
    }
    for (CRV *pcrv = B_003E13F0; pcrv != 0; pcrv = pcrv->pnext) {
        FindCrvClosestPointAll(pcrv, search.posOrigin, 0, &search.posCand, 0, 0, 0);
        FAddSearchCand(&search);
    }
    for (LO *plo = B_003E1408; plo != 0; plo = plo->pnext) {
        search.posCand = PosLoWorld(plo);
        FAddSearchCand(&search);
    }
    for (SO2 *pso = B_003E13E4; pso != 0; pso = pso->pnext) {
        search.posCand = PosLoWorld(pso);
        FAddSearchCand(&search);
    }
    for (CRV *pcrv = B_003E13C0; pcrv != 0; pcrv = pcrv->pnext) {
        FindCrvClosestPointAll(pcrv, search.posOrigin, 0, &search.posCand, 0, 0, 0);
        FAddSearchCand(&search);
    }
    for (LO *plo = B_003E13D8; plo != 0; plo = plo->pnext) {
        search.posCand = PosLoWorld(plo);
        FAddSearchCand(&search);
    }
    for (CRV *pcrv = B_003E13CC; pcrv != 0; pcrv = pcrv->pnext) {
        FindCrvClosestPointAll(pcrv, search.posOrigin, 0, &search.posCand, 0, 0, 0);
        FAddSearchCand(&search);
    }
    for (ALO2 *palo = B_003E13B4; palo != 0; palo = palo->pnext) {
        if ((palo->grf & 1) && FIsBasicDerivedFrom(palo, 0x13)) {
            search.posCand = PosLoWorld(palo);
            FAddSearchCand(&search);
        }
    }
    void *aploA[0x100];
    int cplo = CploFindSwObjectsByClass(B_003DD490, 0x505, 0x23, 0, 0x100, aploA);
    for (int iplo = 0; iplo < cplo; iplo++) {
        search.posCand = PosLoWorld(aploA[iplo]);
        FAddSearchCand(&search);
    }
    void *aploB[0x20];
    cplo = CploFindSwObjectsByClass(B_003DD490, 0x505, 0x67, 0, 0x20, aploB);
    for (int iplo = 0; iplo < cplo; iplo++) {
        search.posCand = PosLoWorld(aploB[iplo]);
        FAddSearchCand(&search);
    }
    void *aploC[0x80];
    cplo = CploFindSwObjectsByClass(B_003DD490, 0x505, 0x1B, 0, 0x80, aploC);
    for (int iplo = 0; iplo < cplo; iplo++) {
        search.posCand = PosLoWorld(aploC[iplo]);
        FAddSearchCand(&search);
    }
    for (SO2 *pso = B_003E1450; pso != 0; pso = pso->pnext) {
        search.posCand = PosLoWorld(pso);
        FAddSearchCand(&search);
    }
    qsort(search.acand, search.ccand, sizeof(CAND), func_00172888);

    unsigned cout = 0;
    float g = 0.0f;
    OUT *poutPrev = 0;
    CAND *pcand = search.acand;
    int ccand = search.ccand;
    asm("lqc2 vf6, %1" : "=r"(fence) : "m"(search.posOrigin));
    for (int icand = 0; icand < ccand && cout < 4; icand++, pcand++) {
        QW posFallback = g_2a2da0;
        asm("lqc2 vf5, %1" : "=r"(fence) : "m"(pcand->pos), "r"(fence));
        asm("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf5, vf6\n\tvmul.xyz vf2, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z"
            : "=r"(fence) : "m"(g_2a2dc0), "r"(fence));
        asm("vmulx.xyzw vf2, vf1, vf2x\n\tvsub.xyzw vf2, vf3, vf2\n\tvmul.xyz vf1, vf2, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q"
            : "=r"(fence) : "r"(fence));
        int lengthBits;
        asm("qmfc2.ni %0, vf1" : "=r"(lengthBits) : "r"(fence));
        float length;
        asm("mtc1 %1, %0" : "=f"(length) : "r"(lengthBits));
        if (length < 0.0001f)
            asm("qmtc2.ni %1, vf2" : "=r"(fence) : "r"(posFallback));
        else
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf2, Q" : "=r"(fence) : "r"(fence));
        asm("qmtc2.ni %2, vf1\n\tvadda.xyzw ACC, vf6, vf0\n\tvmaddx.xyzw vf3, vf2, vf1x\n\tsqc2 vf1, %0" : "=m"(dpos), "=r"(fence) : "r"(0x43480000), "r"(fence));
        asm("vmove.xyzw vf2, vf3" : "=r"(fence) : "r"(fence));
        if (poutPrev != 0) {
            int distanceBits;
            asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
                : "=r"(distanceBits) : "m"(poutPrev->pos), "r"(fence));
            float distance;
            asm("mtc1 %1, %0" : "=f"(distance) : "r"(distanceBits));
            if (distance < 150.0f)
                continue;
        }
        poutPrev = &self->aout[cout];
        g = pcand->g;
        cout++;
        asm("sqc2 vf5, %0\n\tsqc2 vf3, %1" : "=m"(self->aout[cout - 1].posOrig), "=m"(self->aout[cout - 1].pos) : "r"(fence));
    }
    QW posAround;
    QW posBase = search.posOrigin;
    QW offset = SetVectorCylind__FP6VECTORfff(search.yaw + 3.1415927f, -350.0f, 0.0f);
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2" : "=r"(fence) : "r"(offset), "m"(posBase));
    asm("vadd.xyzw vf2, vf1, vf2\n\tsqc2 vf2, %0" : "=m"(posAround) : "r"(fence));
    for (; cout < 4; cout++) {
        g += GRandInRange(D_002BE5A8[0], D_002BE5A8[1]);
        float yaw = g + search.yaw;
        QW offsetRand = SetVectorCylind__FP6VECTORfff(yaw, GRandInRange(D_002BE5B0[0], D_002BE5B0[1]), 0.0f);
        asm("lqc2 vf3, %2\n\tqmtc2.ni %3, vf2\n\tvadd.xyzw vf1, vf3, vf2\n\tsqc2 vf1, %0\n\tsqc2 vf1, %1" : "=m"(self->aout[cout].posOrig), "=m"(self->aout[cout].pos) : "m"(posAround), "r"(offsetRand));
    }
    self->fD0 = 0;
    self->g3C = RO_002A53D0;
}
