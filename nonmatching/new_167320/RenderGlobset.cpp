typedef int QW __attribute__((mode(TI)));
void *memcpy(void *, const void *, unsigned int);
struct M4 { QW row[4]; };
struct W4 { int w[4]; };
struct DMAS2 { char pad[0xC]; unsigned *cursor; };
extern "C" DMAS2 g_2dea28;
extern "C" char B_003DD490;
extern "C" char B_002DDF40[];
extern "C" char g_2ddfe0[];
extern "C" float g_2dded0;
extern "C" const M4 RO_002A2D30;
extern "C" int FUpdatableSaa__FP3SAA(void *);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned);
extern "C" void __ml__FRC7MATRIX4T0(M4 *, const M4 &, const M4 &);
extern "C" void InvertMatrix4Affine(M4 *, M4 *);
extern "C" unsigned *OnGameLoad__FP4GAME(void);
extern "C" float GMaxAxisScale(void *);
extern "C" QW func_00167DA0(void *, QW, float *);
extern "C" void func_001681F8(void *);
extern "C" void UploadGlobPoseMatrices(void *, void *, void *);
extern "C" int FInsideCmMrd(void *, QW, float *, float);
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
static inline void DmaWord(unsigned word) { *g_2dea28.cursor = word; g_2dea28.cursor = g_2dea28.cursor + 1; }
static inline void DmaTag(int lo, int hi) { *(long *)g_2dea28.cursor = (long)lo | ((long)hi << 32); g_2dea28.cursor = g_2dea28.cursor + 4; }
static inline void DmaQuads(const void *psrc, int cqw)
{
    const unsigned *src = (const unsigned *)psrc;
    unsigned *dst = g_2dea28.cursor;
    for (int i = 0; i < cqw * 4; i += 4) {
        unsigned w0 = src[i];
        unsigned w1 = src[i + 1];
        unsigned w2 = src[i + 2];
        unsigned w3 = src[i + 3];
        dst[i] = w0;
        dst[i + 1] = w1;
        dst[i + 2] = w2;
        dst[i + 3] = w3;
    }
    g_2dea28.cursor = g_2dea28.cursor + cqw * 4;
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
#define matGlob (*(M4 *)(fr + 0x10))
#define matLocal (*(M4 *)(fr + 0x50))
#define matTemp (*(M4 *)(fr + 0x90))
#define awBlock (*(W4 *)(fr + 0x50))
#define matInverse (*(M4 *)(fr + 0x60))
#define matEntry (*(M4 *)(fr + 0xD0))
#define matTemp3 (*(M4 *)(fr + 0x110))
extern "C" void RenderGlobset(char *pglobset, M4 *pmatXform, char *plightset, float gScaleA, float gScaleB)
{
    char fr[0x150] __attribute__((aligned(16)));
    float sRadius = *(float *)(pglobset + 0x20);
    char *palo = *(char **)pglobset;
    QW posCamera = *(QW *)(B_002DDF40 + 0x90);
    QW posWorld;
    int chain;
    char *pxfWorld = *(char **)(palo + 0x60);
    asm("lqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf5, %4\n\tlqc2 vf2, %5\n\tlqc2 vf1, %6\n\tvmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf3, vf1y\n\tvmaddaz.xyz ACC, vf2, vf1z\n\tvmaddw.xyz vf5, vf4, vf0w"
        : "=r" (chain), "=m" (sRadius) : "m" (*(QW *)(pxfWorld + 0x70)), "m" (*(QW *)(pxfWorld + 0x50)), "m" (*(QW *)(pxfWorld + 0x40)), "m" (*(QW *)(pxfWorld + 0x60)), "m" (*(QW *)(pglobset + 0x10)));
    if (pmatXform != 0) {
        asm("lqc2 vf4, %1\n\tlqc2 vf3, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf5, vf1, vf0w\n\tqmfc2.ni %0, vf5"
            : "=r" (posWorld) : "m" (pmatXform->row[0]), "m" (pmatXform->row[1]), "m" (pmatXform->row[2]), "m" (pmatXform->row[3]), "r" (chain));
        float scale = GMaxAxisScale(pmatXform);
        sRadius = sRadius * scale;
    } else {
        asm("qmfc2.ni %0, vf5" : "=r" (posWorld) : "r" (chain));
    }
    if ((*(unsigned long *)(pglobset + 0x50) & 0x200000000UL) != 0 && *(char **)(plightset + 0x24) != 0)
        posWorld = func_00167DA0(*(char **)(plightset + 0x24), posWorld, &sRadius);
    QW vis;
    int mrdbits = *(int *)(palo + 0x38);
    int cambits = *(int *)(g_2ddfe0 - 0x84);
    float radius = sRadius;
    asm("qmtc2.ni %1, vf14\n\tqmtc2.ni %2, vf16\n\tqmtc2.ni %3, vf17\n\tqmtc2.ni %7, vf15\n\tlqc2 vf10, %4\n\tlqc2 vf11, %5\n\tlqc2 vf12, %6\n\tlqc2 vf13, %8\n\tvcallms 0x1C0\n\tcfc2.i $0, $vi0\n\tqmfc2.ni %0, vf19"
        : "=r" (vis) : "r" (cambits), "r" (radius), "r" (mrdbits), "m" (*(QW *)g_2ddfe0), "m" (*(QW *)(g_2ddfe0 + 0x10)), "m" (*(QW *)(g_2ddfe0 + 0x20)), "r" (posWorld), "m" (posCamera));
    float gVisibleSet = Lane(vis);
    if (gVisibleSet == 0.0f) return;
    *(float *)(pglobset + 4) = g_2dded0;
    if (*(int *)(pglobset + 0x4C) != *(int *)(&B_003DD490 + 0x3D5C)) func_001681F8(pglobset);
    for (int isaa = 0; isaa < *(int *)(pglobset + 0x24); isaa++) {
        void *psaa = (*(void ***)(pglobset + 0x28))[isaa];
        if (FUpdatableSaa__FP3SAA(psaa) != 0) {
            VT *vt = *(VT **)((char *)psaa + 0xC);
            vt->fn((char *)psaa + vt->delta);
        }
    }
    int fAlt = 0;
    if ((*(unsigned long *)(pglobset + 0x50) & 0x400000000UL) != 0)
        fAlt = *(int *)(&B_003DD490 + 0x3BEC) == 0;
    for (int iglob = 0; iglob < *(int *)(pglobset + 0x38); iglob++) {
        char *pglob = *(char **)(pglobset + 0x3C) + iglob * 0x14;
        char *pglobi = *(char **)(pglobset + 0x40) + iglob * 0x28;
        char *pbnd = *(char **)(pglobset + 0x44) + iglob * 0x18;
        unsigned grf = *(unsigned *)(pglobi + 0xC);
        if (grf & 0x800) continue;
        if (*(unsigned *)(pglobi + 0xC) & 0x1000) {
            CopyAb__FPvT0Ui(&matGlob, (void *)(*(char **)(pglobi + 0x10) + 0x14), 0x40);
            if (pmatXform != 0) {
                __ml__FRC7MATRIX4T0(&matLocal, *pmatXform, matGlob);
                matGlob = matLocal;
            }
        } else {
            memcpy(&matLocal, *(char **)(pglobi + 4) + 0x40, 0x40);
            char *pnode = *(char **)(pglobi + 8);
            if (pnode != 0) {
                __ml__FRC7MATRIX4T0(&matTemp, matLocal, *(M4 *)pnode);
                memcpy(&matLocal, &matTemp, 0x40);
            }
            if (pmatXform != 0) {
                __ml__FRC7MATRIX4T0(&matTemp, *pmatXform, matLocal);
                memcpy(&matLocal, &matTemp, 0x40);
            }
            matGlob = matLocal;
        }
        CopyAb__FPvT0Ui(fr, pbnd, 0xC);
        QW posBndWorld;
        int chain2;
        asm("lqc2 vf5, %2\n\tlqc2 vf4, %3\n\tlqc2 vf3, %4\n\tlqc2 vf2, %5\n\tlqc2 vf1, %6\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf1, vf1, vf0w\n\tqmfc2.ni %0, vf1"
            : "=r" (posBndWorld), "=r" (chain2) : "m" (*(QW *)fr), "m" (matGlob.row[0]), "m" (matGlob.row[1]), "m" (matGlob.row[2]), "m" (matGlob.row[3]));
        float sRadiusBnd = GMaxAxisScale(&matGlob) * *(float *)(pbnd + 0xC);
        if ((grf & 7) == 2 && *(char **)(plightset + 0x24) != 0)
            posBndWorld = func_00167DA0(*(char **)(plightset + 0x24), posBndWorld, &sRadiusBnd);
        float gVisible;
        QW dposBnd;
        if (*(char **)(pglobi + 0x18) != 0) {
            asm("qmtc2.ni %1, vf1\n\tlqc2 vf2, %2\n\tvsub.xyzw vf2, vf1, vf2\n\tqmfc2.ni %0, vf2" : "=r" (dposBnd) : "r" (posBndWorld), "m" (posCamera));
            if (FInsideCmMrd(B_002DDF40, dposBnd, &gVisible, *(float *)(pbnd + 0x10)) == 0) continue;
        } else {
            QW visb;
            int cambits2 = *(int *)(g_2ddfe0 - 0x84);
            int mrdbits2 = *(int *)(pbnd + 0x10);
            asm("qmtc2.ni %2, vf16\n\tqmtc2.ni %3, vf14\n\tqmtc2.ni %4, vf17\n\tqmtc2.ni %8, vf15\n\tlqc2 vf13, %5\n\tlqc2 vf10, %6\n\tlqc2 vf11, %7\n\tlqc2 vf12, %9\n\tvcallms 0x1C0\n\tcfc2.i $0, $vi0\n\tqmfc2.ni %0, vf19\n\tqmfc2.ni %1, vf18"
                : "=r" (visb), "=r" (dposBnd) : "r" (sRadiusBnd), "r" (cambits2), "r" (mrdbits2), "m" (posCamera), "m" (*(QW *)g_2ddfe0), "m" (*(QW *)(g_2ddfe0 + 0x10)), "r" (posBndWorld), "m" (*(QW *)(g_2ddfe0 + 0x20)));
            gVisible = Lane(visb);
            if (gVisible == 0.0f) continue;
        }
        unsigned *pwChain = g_2dea28.cursor;
        if (*(unsigned *)(pglobi + 0xC) & 0x100)
            DmaTag(*(int *)(plightset + 0x14) | 0x40000000, *(int *)(plightset + 0x18));
        unsigned *pwTag;
        unsigned mode = *(unsigned *)(pglobi + 0xC) & 7;
        if (mode == 2) {
            if (*(int *)(plightset + 0x2C) == 0) continue;
            DmaTag(*(int *)(plightset + 0x28) | 0x40000000, *(int *)(plightset + 0x2C));
            pwTag = g_2dea28.cursor;
            DmaTag(0x10000000, 0);
        } else if (mode == 3) {
            pwTag = g_2dea28.cursor;
            DmaTag(0x10000000, 0);
            QW dcam;
            asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf1\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dcam) : "m" (posCamera), "r" (posBndWorld));
            float reach = sRadiusBnd + *(float *)(B_002DDF40 + 0x48);
            int fInside = Lane(dcam) < reach * reach;
            DmaWord(0x6001C012);
            DmaWord(fInside);
        } else {
            pwTag = g_2dea28.cursor;
            DmaTag(0x10000000, 0);
        }
        if (*(char **)(pglobi + 0x18) != 0) {
            DmaWord(0x6C04C000);
            DmaQuads(pmatXform != 0 ? (void *)pmatXform : (void *)&RO_002A2D30, 4);
        } else {
            DmaWord(0x6C04C000);
            DmaQuads(&matGlob, 4);
        }
        float fade = gVisibleSet < gVisible ? gVisibleSet : gVisible;
        float gScaleOut = gScaleA * fade;
        ((float *)&awBlock)[0] = gScaleOut;
        ((float *)&awBlock)[1] = gScaleB * fade;
        ((float *)&awBlock)[2] = *(float *)(pglobset + 0x50);
        awBlock.w[3] = (*(unsigned *)(pglobi + 0xC) & 0x200) ? *(int *)(pglobset + 0x34) : 0;
        DmaWord(0x6C01C008);
        DmaQuads(&awBlock, 1);
        if (*(char **)(pglobi + 0x18) != 0) UploadGlobPoseMatrices(pglobset, pglob, pglobi);
        char *pvu = *(char **)(pglobi + 0x1C);
        if (pvu != 0) {
            InvertMatrix4Affine(&matInverse, &matGlob);
            int ivu = *(int *)(pvu + 0x20);
            for (int imat = 0; imat < *(int *)(pvu + 0x10); imat++) {
                if (*(int *)(pvu + 0x14) != 0) {
                    __ml__FRC7MATRIX4T0(&matTemp3, matInverse, *(M4 *)(*(char **)(pvu + 0xC) + imat * 0x40 + 0x6F0));
                    matEntry = matTemp3;
                    DmaWord(ivu | 0x6C04C000);
                    DmaQuads(&matEntry, 4);
                    ivu += 4;
                }
                if (*(int *)(pvu + 0x18) != 0) {
                    DmaWord(ivu | 0x6C04C000);
                    DmaQuads(*(char **)(pvu + 0xC) + imat * 0x40 + 0x7F0, 4);
                    ivu += 4;
                }
            }
        }
        while (((unsigned)g_2dea28.cursor & 0xF) != 0) {
            *g_2dea28.cursor = 0;
            g_2dea28.cursor = g_2dea28.cursor + 1;
        }
        *pwTag |= (unsigned)(((char *)g_2dea28.cursor - (char *)pwTag) >> 4) - 1;
        DmaTag(0x60000000, 0);
        unsigned *prec = OnGameLoad__FP4GAME();
        unsigned ipass = (*(unsigned char *)(pglobi + 0xC)) >> 3;
        unsigned ipassOut = ipass;
        switch (ipass) {
        case 3:
        case 4:
            if (fAlt) {
                ipassOut = gScaleOut == 1.0f ? 0x16 : 0x17;
            } else if (gScaleOut != 1.0f) {
                ipassOut = ((*(unsigned *)(pglobi + 0xC) & 0xF8) == 0x18) ? 5 : 6;
            }
            break;
        case 5:
        case 6:
            if (fAlt) ipassOut = 0x17;
            break;
        case 9:
            if (fAlt) ipassOut = 0x18;
            break;
        case 10:
            if (fAlt) ipassOut = 0x19;
            break;
        default:
            break;
        }
        prec[0] = ipassOut;
        if (*(unsigned *)(pglobi + 0xC) & 0x400) {
            *(float *)&prec[1] = *(float *)(pglob + 4);
        } else {
            QW dot;
            asm("lqc2 vf3, %1\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dot) : "m" (dposBnd));
            prec[1] = (unsigned)dot;
        }
        prec[2] = (unsigned)pwChain;
        prec[3] = *(unsigned *)(pglobi + 0x10);
    }
}
