#include "sly2.h"
struct DMAS2 { char pad[0xC]; unsigned *cursor; };
struct VEnt { short delta; short index; void (*fn)(void *); };
struct SAAVT { char pad[0x40]; VEnt slot40; };
struct SAA { char pad[0xC]; SAAVT *vptr; };
struct RTE { QW sphere; long bits; int child; int next; };
struct RTN { RTE arte[4]; };
struct GLOBSETX { char pad0[0x24]; int csaa; SAA **pasaa; char pad1[0x3C - 0x2C]; char *pparts; char *paux; char pad2[0x48 - 0x44]; int prootNode; int frameDrawn; float uAlpha; };
struct MATRIX44 { QW row[4]; };
struct SKIN { char pad0[4]; unsigned uVifAddress; char pad1[4]; char *pbBones; int cBone; int fBoneMatrix; int fRawMatrix; };
struct PART { char pad[4]; char *pvOwner; MATRIX44 *pmatLocal; unsigned grf; int nExtra; char pad2[0xC]; SKIN *pskin; };
struct AUX { char pad[4]; float zSort; };
struct RENDERREC { int kind; float zSort; int pbPacket; int nExtra; };
extern "C" int FUpdatableSaa__FP3SAA(SAA *);
extern "C" void func_001681F8(GLOBSETX *);
extern "C" void PushRenderNode(void *, int);
extern "C" int PopRenderNode(void *);
extern "C" void __ml__FRC7MATRIX4T0(MATRIX44 *, const MATRIX44 *, const MATRIX44 *);
extern "C" void InvertMatrix4Affine(MATRIX44 *, const MATRIX44 *);
extern "C" DMAS2 g_2dea28;
extern "C" struct { char pad[0x14]; int grfPass; char pad2[0x1C - 0x18]; int unk1c; char pad3[0x48 - 0x20]; float gRadiusPad; } B_002DDF40;
extern "C" struct { char pad[0x3D5C]; int frame; } B_003DD490;
extern "C" RENDERREC *B_003D4A50;
extern "C" RENDERREC B_003B3980[];

static inline void DmaPutWord(unsigned word) { *g_2dea28.cursor = word; g_2dea28.cursor++; }
static inline void DmaCopyQuads(const void *psrc, int cquad)
{
    unsigned *pdst = g_2dea28.cursor;
    const unsigned *psource = (const unsigned *)psrc;
    int count = cquad * 4 - 4;
    do {
        pdst[0] = psource[0]; pdst[1] = psource[1]; pdst[2] = psource[2]; pdst[3] = psource[3];
        psource += 4; count -= 4; pdst += 4;
    } while (count >= 0);
    g_2dea28.cursor = (unsigned *)((char *)g_2dea28.cursor + cquad * 16);
}
static inline void DmaPadToQuad()
{
    while (((unsigned)g_2dea28.cursor & 0xF) != 0) { *g_2dea28.cursor = 0; g_2dea28.cursor++; }
}

void RenderGlobsetTree(void *pstack, GLOBSETX *pglobset)
{
    char buf[0x8D0] __attribute__((aligned(16)));
    unsigned *apvDeferred = (unsigned *)buf;
    int cDeferred;
    for (int isaa = 0; isaa < pglobset->csaa; isaa++) {
        SAA *psaa = pglobset->pasaa[isaa];
        if (FUpdatableSaa__FP3SAA(psaa) != 0) {
            SAAVT *vt = psaa->vptr;
            vt->slot40.fn((char *)psaa + vt->slot40.delta);
        }
    }
    if (pglobset->frameDrawn != B_003DD490.frame)
        func_001681F8(pglobset);
    cDeferred = 0;
    PushRenderNode(pstack, pglobset->prootNode);
    int grfPass = B_002DDF40.grfPass;
    RTN *prtn;
    while ((prtn = (RTN *)PopRenderNode(pstack)) != 0) {
        for (unsigned irte = 0; irte < 4; irte++) {
            RTE *prte = &prtn->arte[irte];
            long bits = prte->bits;
            int rtet = (int)((bits << 28) >> 60);
            if (rtet == -1) continue;
            asm("qmtc2.ni %0, vf14" : : "r"(B_002DDF40.unk1c));
            asm("qmtc2.ni %0, vf16" : : "r"(*(int *)((char *)prte + 0xC)));
            asm("lqc2 vf15, %0" : : "m"(prte->sphere));
            asm("qmtc2.ni %0, vf17" : : "r"(*(int *)((char *)prte + 0x10)));
            asm("lqc2 vf10, %0" : : "m"(*(QW *)0x2DDFE0));
            asm("lqc2 vf11, %0" : : "m"(*(QW *)0x2DDFF0));
            asm("lqc2 vf12, %0" : : "m"(*(QW *)0x2DE000));
            asm("lqc2 vf13, %0" : : "m"(*(QW *)0x2DDFD0));
            asm volatile("vcallms 0x1C0");
            bits = prte->bits;
            if ((((int)((bits << 20) >> 56)) & grfPass) == 0) continue;
            int token;
            asm volatile("cfc2.i $0, $vi0");
            asm volatile("qmfc2.ni %0, vf19" : "=r"(token));
            float uVisible;
            asm volatile("mtc1 %1, %0\n\tnop" : "=f"(uVisible) : "r"(token));
            if (uVisible == 0.0f) continue;
            QW posView;
            asm volatile("vmove.xyzw vf3, vf18");
            if (rtet == 1) {
                PushRenderNode(pstack, prte->child);
            } else if (rtet == 0) {
                if ((bits & (1L << 50)) != 0) continue;
                unsigned iPart = (unsigned long)bits >> 51;
                PART *ppart = (PART *)(pglobset->pparts + iPart * 0x28);
                AUX *paux = (AUX *)(pglobset->paux + iPart * 0x14);
                if ((unsigned)(((char *)B_003D4A50 - (char *)B_003B3980) >> 4) >= 0x2000) continue;
                RENDERREC *prr = B_003D4A50;
                B_003D4A50 = prr + 1;
                prr->kind = (int)((bits << 14) >> 58);
                if (uVisible < 1.0f) {
                    int kind = (int)((prte->bits << 14) >> 58);
                    if (kind == 3) prr->kind = 5;
                    else if (kind == 4) prr->kind = 6;
                }
                float zSort;
                if ((ppart->grf & 0x400) != 0) zSort = paux->zSort;
                else {
                    asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
                    int zbits;
                    asm volatile("qmfc2.ni %0, vf1" : "=r"(zbits));
                    asm volatile("mtc1 %1, %0" : "=f"(zSort) : "r"(zbits));
                }
                prr->zSort = zSort;
                unsigned *ptag = g_2dea28.cursor;
                *(unsigned long *)ptag = 0x10000000;
                g_2dea28.cursor += 4;
                MATRIX44 *pmatWorld = (MATRIX44 *)(buf + 0x810);
                if (ppart->pmatLocal != 0) {
                    __ml__FRC7MATRIX4T0((MATRIX44 *)(buf + 0x850), ppart->pmatLocal, (MATRIX44 *)(ppart->pvOwner + 0x40));
                    *pmatWorld = *(MATRIX44 *)(buf + 0x850);
                } else {
                    *pmatWorld = *(MATRIX44 *)(ppart->pvOwner + 0x40);
                }
                DmaPutWord(0x6C04C000);
                DmaCopyQuads(pmatWorld, 4);
                SKIN *pskin = ppart->pskin;
                if (pskin != 0) {
                    MATRIX44 *pmatInverse = (MATRIX44 *)(buf + 0x800);
                    if (ppart->pmatLocal != 0) {
                        __ml__FRC7MATRIX4T0((MATRIX44 *)(buf + 0x890), ppart->pmatLocal, (MATRIX44 *)(ppart->pvOwner + 0x40));
                        InvertMatrix4Affine((MATRIX44 *)(buf + 0x840), (MATRIX44 *)(buf + 0x890));
                    } else {
                        InvertMatrix4Affine((MATRIX44 *)(buf + 0x840), (MATRIX44 *)(ppart->pvOwner + 0x40));
                    }
                    *pmatInverse = *(MATRIX44 *)(buf + 0x840);
                    unsigned uVifAddress = pskin->uVifAddress;
                    for (int ibone = 0; ibone < pskin->cBone; ibone++) {
                        if (pskin->fBoneMatrix != 0) {
                            __ml__FRC7MATRIX4T0((MATRIX44 *)(buf + 0x880), pmatInverse, (MATRIX44 *)(pskin->pbBones + ibone * 0x40 + 0x6F0));
                            *(MATRIX44 *)(buf + 0x840) = *(MATRIX44 *)(buf + 0x880);
                            DmaPutWord(uVifAddress | 0x6C04C000);
                            DmaCopyQuads(buf + 0x840, 4);
                            uVifAddress += 4;
                        }
                        if (pskin->fRawMatrix != 0) {
                            DmaPutWord(uVifAddress | 0x6C04C000);
                            DmaCopyQuads(pskin->pbBones + ibone * 0x40 + 0x7F0, 4);
                            uVifAddress += 4;
                        }
                    }
                }
                float *vecFade = (float *)(buf + 0x800);
                vecFade[0] = uVisible; vecFade[1] = 1.0f; vecFade[2] = pglobset->uAlpha; vecFade[3] = 0.0f;
                DmaPutWord(0x6C01C008);
                DmaCopyQuads(vecFade, 1);
                if ((unsigned)(((int)((prte->bits << 14) >> 58)) - 7) < 2) {
                    float gRadius = *(float *)((char *)prte + 0xC) + B_002DDF40.gRadiusPad;
                    asm volatile("vmul.xyz vf2, vf3, vf3\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z");
                    int dbits;
                    asm volatile("qmfc2.ni %0, vf2" : "=r"(dbits));
                    float gDist;
                    asm volatile("mtc1 %1, %0" : "=f"(gDist) : "r"(dbits));
                    gRadius = gRadius * gRadius;
                    int fInside = gDist < gRadius ? 1 : 0;
                    DmaPutWord(0x6001C012);
                    DmaPutWord(fInside);
                }
                DmaPadToQuad();
                *ptag |= (((char *)g_2dea28.cursor - (char *)ptag) >> 4) - 1;
                *(unsigned long *)g_2dea28.cursor = 0x60000000;
                g_2dea28.cursor += 4;
                prr->pbPacket = (int)ptag;
                prr->nExtra = ppart->nExtra;
            } else if (rtet == 3) {
                if ((bits & (1L << 50)) != 0) continue;
                if ((unsigned)(((char *)B_003D4A50 - (char *)B_003B3980) >> 4) >= 0x2000) continue;
                RENDERREC *prr = B_003D4A50;
                B_003D4A50 = prr + 1;
                int kind = (int)((bits << 14) >> 58);
                prr->kind = kind;
                int zbits;
                asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
                asm volatile("qmfc2.ni %0, vf1" : "=r"(zbits));
                prr->zSort = *(float *)&zbits;
                if (uVisible < 1.0f) {
                    if (kind == 3) prr->kind = 5;
                    else if (kind == 4) prr->kind = 6;
                }
                if (1.0f <= uVisible) {
                    prr->pbPacket = prte->child;
                    prr->nExtra = 0;
                } else {
                    float *vecFade = (float *)(buf + 0x800);
                    vecFade[0] = uVisible; vecFade[1] = 1.0f; vecFade[2] = pglobset->uAlpha; vecFade[3] = 0.0f;
                    prr->pbPacket = (int)g_2dea28.cursor;
                    prr->nExtra = prte->child + 0x70;
                    *(unsigned long *)g_2dea28.cursor = ((unsigned long)(prte->child + 0x10) << 32) | 0x40000006;
                    g_2dea28.cursor += 4;
                    *(unsigned long *)g_2dea28.cursor = 0x10000002;
                    g_2dea28.cursor += 4;
                    DmaPutWord(0x6C01C008);
                    DmaCopyQuads(vecFade, 1);
                    DmaPadToQuad();
                    *(unsigned long *)g_2dea28.cursor = 0x60000000;
                    g_2dea28.cursor += 4;
                }
            } else if (rtet == 4) {
                if (cDeferred < 0x200) apvDeferred[cDeferred++] = prte->child;
            }
        }
        if (prtn->arte[3].next != 0) PushRenderNode(pstack, prtn->arte[3].next);
    }
    for (int ideferred = 0; ideferred < cDeferred; ideferred++) {
        SAA *pobj = (SAA *)apvDeferred[ideferred];
        VEnt *pent = (VEnt *)((char *)pobj->vptr + 0x98);
        pent->fn((char *)pobj + pent->delta);
    }
}
