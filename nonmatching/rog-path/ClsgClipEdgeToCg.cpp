#include "sly2.h"
struct CGNODE { float nx, ny, gDist; unsigned short aichild[2]; };
struct CLIPREC { CGNODE *pnode; unsigned pface; float u; float pad; QW plane; };
struct CLIPSEG { QW pos1; QW pos2; QW planeStart; QW planeEnd; float u1, u2; int kind; unsigned pface; char pad[0x10]; };
extern "C" {
int CbskFromG(float);
}
#define PROBEVEC(vec, pos) do { \
    QW rotated, packed; \
    float x, y, z = -1.0f; \
    int bitsX, bitsY, bitsZ; \
    asm("prot3w %0, %1" : "=r" (rotated) : "r" (pos)); \
    asm("mtc1 %1, %0" : "=f" (x) : "r" (pos)); \
    asm("mtc1 %1, %0" : "=f" (y) : "r" (rotated)); \
    asm("mfc1 %0, %1" : "=r" (bitsX) : "f" (x)); \
    asm("mfc1 %0, %1" : "=r" (bitsY) : "f" (y)); \
    asm("pextlw %0, %1, %2" : "=r" (packed) : "r" (bitsY), "r" (bitsX)); \
    asm("mfc1 %0, %1" : "=r" (bitsZ) : "f" (z)); \
    asm("pcpyld %0, %1, %2" : "=r" (vec) : "r" (bitsZ), "r" (packed)); \
    junk = vec; \
    asm("" : : "m" (junk)); \
} while (0)
#define LERP(out, pos1, pos2, u) do { \
    int bitsU, bitsV; \
    float v = 1.0f - (u); \
    float uu = (u); \
    asm("mfc1 %0, %1" : "=r" (bitsU) : "f" (uu)); \
    asm("mfc1 %0, %1" : "=r" (bitsV) : "f" (v)); \
    asm("lqc2 vf3, %0" : : "m" (pos1)); \
    asm("lqc2 vf4, %0" : : "m" (pos2)); \
    asm("qmtc2.ni %0, vf2" : : "r" (bitsU)); \
    asm("qmtc2.ni %0, vf1" : : "r" (bitsV)); \
    asm("sqc2 vf1, %0" : "=m" (junk)); \
    asm("sqc2 vf2, %0" : "=m" (junk)); \
    asm("vmulax.xyzw ACC, vf3, vf1x\n\tvmaddx.xyzw vf1, vf4, vf2x\n\tsqc2 vf1, %0" : "=m" (out)); \
} while (0)
static inline void Select(CLIPREC *rec, unsigned child, CGNODE *anode, CGNODE *pnodeEnd, unsigned aface, unsigned grfLeaf)
{
    if (child & 0x8000) {
        rec->pnode = pnodeEnd;
        rec->pface = (child & grfLeaf) ? aface + (child & 0x3FFF) * 12 : 0;
    } else {
        rec->pnode = anode + child;
    }
}
extern "C" int ClsgClipEdgeToCg(char *pcg, QW pos1, QW pos2, int clsgMax, CLIPSEG *alsg, unsigned grf)
{
    unsigned aface = *(unsigned *)(pcg + 0xC);
    CGNODE *anode = *(CGNODE **)(pcg + 0x14);
    CGNODE *pnodeEnd = anode + *(int *)(pcg + 0x10);
    unsigned grfLeaf = (grf & 1) ? 0x8000 : 0x4000;
    CLIPREC cur;
    CLIPREC astack[32];
    QW junk;
    memset(&cur, 0, sizeof(cur));
    cur.pnode = anode;
    memset(astack, 0, sizeof(CLIPREC));
    astack[0].u = 1.0f;
    CLIPREC *top = astack;
    QW probe1;
    PROBEVEC(probe1, pos1);
    QW probe2;
    PROBEVEC(probe2, pos2);
    int clsg = 0;
    CLIPSEG *plsgLast = 0;
    CLIPSEG *plsgNext = alsg;
    for (;;) {
        if (cur.pnode == pnodeEnd) {
            do {
                if (cur.pface) {
                    float uNext = top->u;
                    int extend = 0;
                    if (plsgLast && cur.u == plsgLast->u2) {
                        if ((grf & 2) || cur.pface == plsgLast->pface)
                            extend = 1;
                    }
                    if (extend) {
                        LERP(plsgLast->pos2, pos1, pos2, uNext);
                        plsgLast->u2 = top->u;
                        plsgLast->planeEnd = top->plane;
                    } else {
                        if (clsg >= clsgMax)
                            return clsgMax;
                        CLIPSEG *plsg = plsgNext;
                        plsgLast = plsg;
                        memset(plsg, 0, sizeof(CLIPSEG));
                        plsgNext++;
                        LERP(plsg->pos1, pos1, pos2, cur.u);
                        LERP(plsg->pos2, pos1, pos2, top->u);
                        plsg->kind = 3;
                        plsg->u1 = cur.u;
                        plsg->u2 = top->u;
                        plsg->planeStart = cur.plane;
                        plsg->planeEnd = top->plane;
                        plsg->pface = cur.pface;
                        clsg++;
                    }
                }
                if (top <= astack)
                    return clsg;
                cur = *top;
                top--;
            } while (cur.pnode == pnodeEnd);
        }
        float g1, g2;
        asm("lqc2 vf1, %2\n\tlqc2 vf4, %3\n\tvmul.xyz vf3, vf1, vf4\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf2, vf3z\n\tlqc2 vf5, %4\n\tvmul.xyz vf1, vf1, vf5\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\tqmfc2.ni %0, vf3\n\tqmfc2.ni %1, vf1" : "=r" (g1), "=r" (g2) : "m" (*cur.pnode), "m" (probe1), "m" (probe2));
        int cbsk1 = CbskFromG(g1);
        int cbsk2 = CbskFromG(g2);
        int anyBehind = 0;
        if (cbsk1 == 1 || cbsk2 == 1)
            anyBehind = 1;
        int anyFront = 0;
        if (cbsk1 == 0 || cbsk2 == 0)
            anyFront = 1;
        if (anyBehind && anyFront) {
            float uEnd = top->u;
            float uSplit = g1 / (g1 - g2);
            float gStart = cur.u * g2 + (1.0f - cur.u) * g1;
            float gEnd = uEnd * g2 + (1.0f - uEnd) * g1;
            if (cur.u < uSplit && uSplit < uEnd) {
                top++;
                top->u = uSplit;
                float *plane = (float *)&top->plane;
                plane[0] = cur.pnode->nx;
                plane[1] = cur.pnode->ny;
                plane[2] = 0.0f;
                plane[3] = cur.pnode->gDist;
                Select(top, cur.pnode->aichild[gStart <= plane[2] ? 1 : 0], anode, pnodeEnd, aface, grfLeaf);
            }
            int behind = 0;
            if (gStart < 0.0f || (gStart == 0.0f && gEnd <= 0.0f))
                behind = 1;
            Select(&cur, cur.pnode->aichild[behind ? 0 : 1], anode, pnodeEnd, aface, grfLeaf);
        } else {
            Select(&cur, cur.pnode->aichild[anyFront ? 1 : 0], anode, pnodeEnd, aface, grfLeaf);
        }
    }
}
