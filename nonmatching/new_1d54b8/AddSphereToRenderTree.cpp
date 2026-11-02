typedef int QW __attribute__((mode(TI)));
struct RTB_1D6508;
struct BITS_1D6508 {
    unsigned long low : 32;
    long kind : 4;
    long grf : 8;
    unsigned long flag : 1;
    unsigned long rest : 19;
};
struct RTE_1D6508 {
    float x, y, z, radius;
    union {
        float sRadius;
        BITS_1D6508 bits;
    };
    RTB_1D6508 *child;
    int pad;
};
struct RTB_1D6508 { RTE_1D6508 aentry[3]; float x, y, z, radius; unsigned long bits; RTB_1D6508 *child; RTB_1D6508 *next; };
struct TREE_1D6508 { char pad[0x3E5C]; RTB_1D6508 *root; };
extern "C" {
RTB_1D6508 *AllocRenderTreeNode();
extern float g_2a7870;
}

static inline float GMin(float a, float b) { return a < b ? a : b; }

extern "C" RTE_1D6508 *AddSphereToRenderTree(TREE_1D6508 *tree, QW pos, int grf, float radius, float sRadius)
{
    RTB_1D6508 *pblock = tree->root;
    RTB_1D6508 *pb;
    RTE_1D6508 *pfree;
    asm("qmtc2.ni %0, vf3" : : "r"(pos));
    while (pblock != 0) {
        float best = g_2a7870;
        RTB_1D6508 *pnext = 0;
        pb = pblock;
        pfree = 0;
        for (;;) {
            RTB_1D6508 *chain = pb->next;
            RTE_1D6508 *pe = (RTE_1D6508 *)pb;
            for (unsigned int i = 0; i < 4; i++, pe++) {
                long kind = pe->bits.kind;
                if (kind == -1) {
                    if (pfree == 0)
                        pfree = pe;
                } else if (kind == 1) {
                    int bitsDist;
                    float dist;
                    asm("lqc2 vf1, %0\n\tvsub.xyzw vf1, vf3, vf1" : : "m"(*(QW *)pe));
                    float r = pe->radius;
                    asm volatile("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r"(bitsDist));
                    asm("mtc1 %1, %0" : "=f"(dist) : "r"(bitsDist));
                    if (dist + radius <= r) {
                        float s = pe->sRadius;
                        if ((s == 1e10f || dist + sRadius <= s) && (grf & ~pe->bits.grf) == 0) {
                            float m = GMin(100000.0f, s);
                            float d = r * m * m;
                            if (d < best) {
                                best = d;
                                pnext = pe->child;
                            }
                        }
                    }
                }
            }
            if (chain == 0)
                break;
            pb = chain;
        }
        if (pnext == 0) {
            if (pfree == 0) {
                RTB_1D6508 *pnew = AllocRenderTreeNode();
                pb->next = pnew;
                pfree = (RTE_1D6508 *)pnew;
            }
            pfree->sRadius = sRadius;
            *(QW *)pfree = pos;
            pfree->radius = radius;
            pfree->bits.grf = grf;
            pfree->bits.rest = 0;
            return pfree;
        }
        pblock = pnext;
    }
    return 0;
}
