typedef int QW __attribute__((mode(TI)));
void *memcpy(void *, const void *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
struct M4 { QW row[4]; };
struct W16 { int w[16]; };
struct W4 { int w[4]; };
union FR {
    struct { char lightset[0x30]; M4 m_matGlob; M4 m_matLocal; M4 m_matTemp; } a;
    struct { char pad[0x70]; W4 m_awBlock; M4 m_matPose; } b;
    struct { char pad[0xC0]; M4 m_matEntry; } c;
    struct { char pad[0xF0]; M4 m_matTemp2; } d;
    struct { char pad[0x130]; M4 m_matTemp3; } e;
};
struct DMAS2 { char pad[0xC]; unsigned *cursor; };
struct LIGHTSET { char pad0[0x14]; unsigned cq; unsigned pb; char pad1[0x18]; };
struct GLOBSET { char pad0[0x24]; int csaa; void **apsaa; int cglob; char *aglob; char *aglobi; char *abnd; char pad1[8]; unsigned long grf_unused; };
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
extern "C" DMAS2 g_2dea28;
extern "C" char B_003DD490;
extern "C" const W16 RO_002A2D30;
extern "C" int FUpdatableSaa__FP3SAA(void *);
extern "C" void func_001A4AD8(void *, int, void *, void *);
extern "C" int func_001BEE10(void *, int);
extern "C" void CopyAb__FPvT0Ui(void *, void *, unsigned);
extern "C" void __ml__FRC7MATRIX4T0(M4 *, const M4 &, const M4 &);
extern "C" M4 mlval(const M4 &, const M4 &) __asm__("__ml__FRC7MATRIX4T0");
extern "C" void InvertMatrix4Affine(M4 *, M4 *);
extern "C" unsigned *OnGameLoad__FP4GAME(void);
extern "C" QW PosLoWorld(void *);
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
extern "C" void func_00169198(char *pglobset, char *pso)
{
    char fr[0x170] __attribute__((aligned(16)));
    char *lightset = fr;
    char *plightset;
    if (*(int *)(pso + 0x104) != 0) {
        memset(lightset, 0, 0x30);
        plightset = lightset;
        func_001A4AD8(&B_003DD490, *(int *)(pso + 0x104), pso + 0x108, lightset);
    } else {
        plightset = 0;
    }
    for (int isaa = 0; isaa < *(int *)(pglobset + 0x24); isaa++) {
        void *psaa = (*(void ***)(pglobset + 0x28))[isaa];
        if (FUpdatableSaa__FP3SAA(psaa) != 0) {
            VT *vt = *(VT **)((char *)psaa + 0xC);
            vt->fn((char *)psaa + vt->delta);
        }
    }
    for (int iglob = 0; iglob < *(int *)(pglobset + 0x38); iglob++) {
        char *pglob = *(char **)(pglobset + 0x3C) + iglob * 0x14;
        char *pglobi = *(char **)(pglobset + 0x40) + iglob * 0x28;
        unsigned grf = *(unsigned *)(pglobi + 0xC);
        if (grf & 0x800) continue;
        if ((grf & 7) == 2) continue;
        int ipassSo = func_001BEE10(pso, (grf >> 3) & 0x1F);
        if (ipassSo == -1) continue;
        M4 &matGlob = *(M4 *)(fr + 0x30);
        M4 &matLocal = *(M4 *)(fr + 0x70);
        M4 &matTemp = *(M4 *)(fr + 0xB0);
        if (*(unsigned *)(pglobi + 0xC) & 0x1000) {
            CopyAb__FPvT0Ui(&matGlob, (void *)(*(char **)(pglobi + 0x10) + 0x14), 0x40);
        } else {
            memcpy(&matLocal, *(char **)(pglobi + 4) + 0x40, 0x40);
            char *pnode = *(char **)(pglobi + 8);
            if (pnode != 0) {
                __ml__FRC7MATRIX4T0(&matTemp, matLocal, *(M4 *)pnode);
                memcpy(&matLocal, &matTemp, 0x40);
            }
            matGlob = matLocal;
        }
        QW posRelative;
        if (*(char **)(pglobi + 0x24) != 0) {
            QW node = **(QW **)(pglobi + 0x24);
            QW world = PosLoWorld(pso);
            asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvsub.xyzw vf2, vf1, vf2\n\tsqc2 vf2, %0" : "=m" (posRelative) : "r" (world), "m" (node));
        } else {
            CopyAb__FPvT0Ui(&matLocal, *(char **)(pglobset + 0x44) + iglob * 0x18, 0xC);
            asm("lqc2 vf5, %1\n\tlqc2 vf4, %2\n\tlqc2 vf3, %3\n\tlqc2 vf2, %4\n\tlqc2 vf1, %5\n\tvmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf6, vf1, vf0w\n\tsqc2 vf6, %0" : "=m" (posRelative) : "m" (matLocal.row[0]), "m" (matGlob.row[0]), "m" (matGlob.row[1]), "m" (matGlob.row[2]), "m" (matGlob.row[3]));
        }
                unsigned *pwChain = g_2dea28.cursor;
        if (*(unsigned *)(pglobi + 0xC) & 0x100) {
            DmaTag(*(int *)(plightset + 0x14) | 0x40000000, *(int *)(plightset + 0x18));
        }
        unsigned *pwTag = g_2dea28.cursor;
        DmaTag(0x10000000, 0);
        if (*(int *)(pglobi + 0x18) != 0) {
            DmaWord(0x6C04C000);
            DmaQuads(&RO_002A2D30, 4);
        } else {
            DmaWord(0x6C04C000);
            DmaQuads(&matGlob, 4);
        }
        W4 &awBlock = *(W4 *)(fr + 0x70);
        ((float *)&awBlock)[2] = *(float *)(pglobset + 0x50);
        ((float *)&awBlock)[1] = 1.0f;
        ((float *)&awBlock)[0] = 1.0f;
        awBlock.w[3] = (*(unsigned *)(pglobi + 0xC) & 0x200) ? *(int *)(pglobset + 0x34) : 0;
        DmaWord(0x6C01C008);
        DmaQuads(&awBlock, 1);
        if (*(char **)(pglobi + 0x18) != 0) {
            for (int ipose = 0; ipose < *(signed char *)(pglob + 1); ipose++) {
                M4 &matPose = *(M4 *)(fr + 0x80);
                M4 &matTemp2 = *(M4 *)(fr + 0xF0);
                char *ppose = *(char **)(pglobi + 0x18) + ipose * 0x50;
                if (*(char **)(ppose + 0xC) != 0) {
                    __ml__FRC7MATRIX4T0(&matTemp2, *(M4 *)(*(char **)(ppose + 0xC) + 0x40), *(M4 *)(ppose + 0x10));
                    matPose = matTemp2;
                } else {
                    matPose = *(M4 *)(ppose + 0x10);
                }
                DmaWord(((ipose << 2) + *(int *)(pglob + 0xC)) | 0x6C04C000);
                DmaQuads(&matPose, 4);
            }
        }
        char *pvu = *(char **)(pglobi + 0x1C);
        if (pvu != 0) {
            M4 &matInverse = *(M4 *)(fr + 0x80);
            InvertMatrix4Affine(&matInverse, &matGlob);
            int ivu = *(int *)(pvu + 0x20);
            for (int imat = 0; imat < *(int *)(pvu + 0x10); imat++) {
                if (*(int *)(pvu + 0x14) != 0) {
                    M4 &matEntry = *(M4 *)(fr + 0xC0);
                    M4 &matTemp3 = *(M4 *)(fr + 0x130);
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
        prec[0] = ipassSo;
        if (*(unsigned *)(pglobi + 0xC) & 0x400) {
            *(float *)&prec[1] = *(float *)(pglob + 4);
        } else {
            QW dot;
            asm("lqc2 vf3, %1\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dot) : "m" (posRelative));
            prec[1] = (unsigned)dot;
        }
        prec[2] = (unsigned)pwChain;
        prec[3] = *(unsigned *)(pglobi + 0x10);
    }
}
