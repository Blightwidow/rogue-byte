#include "sly2.h"
struct PRIPG { char pad[0x158]; float lift; };
struct CLQ { float a, b, c; };
struct SRC { char pad[8]; PRIPG *pripg; char pad2[0x14 - 0xC]; float tCreated; float dt; char pad3[4]; CLQ clq; };
struct STK;
struct VTS { char pad[8]; short delta; short idx; void (*fn)(void *, QW, void *, float); };
struct STK {
    char pad0[0x18]; float dtLifetime; void *palo; char pad1[0x28 - 0x20]; float c2; char pad2[0x40 - 0x2C];
    QW row0, row1, row2; char pad3[0x78 - 0x70]; float posz; char pad4[0x90 - 0x7C]; QW v;
    char pad5[0xEC - 0xA0]; VTS *vptr; void *pxf;
};
extern "C" STK *PripNewRipg(void *, int, void *);
extern "C" QW ConvertXfPos(void *, void *, QW);
extern "C" float GRandInRange(float, float);
extern "C" void GetNormalVectors__FP6VECTORN30(QW, QW, QW, QW *);
extern "C" void LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(void *, QW);
extern "C" void BuildRotateVectorsMatrix(void *, QW, QW);
extern "C" char B_003DD490[];
extern "C" QW g_2a2da0, g_2a2db0, g_2a2dc0;
extern "C" float g_2dded0;

struct FR {
    QW posLocal; QW surf[3]; struct { float x, y, z, w; } euler; QW j50, j60, j70; QW em[3]; QW jB0, jC0, jD0; QW rot[3];
};

extern "C" STK *CreateStuck__FP3RIPP3ALOP2SOP6VECTORT3PP5STUCK(SRC *src, void *palo, void *pxf, QW pos, QW normal)
{
    STK *stuck = 0;
    FR f;
    if (palo != 0) {
        stuck = PripNewRipg(B_003DD490, 10, 0);
        if (stuck != 0) {
            float zero = 0.0f;
            f.posLocal = ConvertXfPos(0, pxf, pos);
            float u = (g_2dded0 - src->tCreated) / src->dt;
            CLQ *clq = &src->clq;
            float scale = clq->a + u * (u + clq->b * clq->c);
            scale = scale * GRandInRange(0.8f, 1.4f);
            stuck->vptr->fn((char *)stuck + stuck->vptr->delta, f.posLocal, 0, scale);
            stuck->palo = palo;
            stuck->dtLifetime = 5.0f;
            stuck->c2 = -scale;
            stuck->pxf = pxf;
            QW *pda = &g_2a2da0;
            QW *pdb = &g_2a2db0;
            GetNormalVectors__FP6VECTORN30(normal, *pda, *pdb, f.surf);
            f.surf[2] = normal;
            f.euler.y = zero;
            f.euler.x = zero;
            f.euler.z = GRandInRange(zero, 6.2831855f);
            LoadRotateMatrixEuler__FP6VECTORP7MATRIX3(f.em, *(QW *)&f.euler);
            QW *up = &g_2a2dc0;
            asm("lqc2 vf2, %0" : : "m"(f.surf[1]));
            asm("lqc2 vf1, %0" : : "m"(f.surf[2]));
            asm("lqc2 vf8, %0" : : "m"(f.em[0]));
            asm("lqc2 vf7, %0" : : "m"(f.em[1]));
            asm("lqc2 vf5, %0" : : "m"(f.em[2]));
            asm("lqc2 vf3, %0" : : "m"(f.surf[0]));
            asm("vmulax.xyz ACC, vf3, vf8x\n\tvmadday.xyz ACC, vf2, vf8y\n\tvmaddz.xyz vf4, vf1, vf8z\n\tvmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddz.xyz vf6, vf1, vf5z\n\tvmulax.xyz ACC, vf3, vf7x\n\tvmadday.xyz ACC, vf2, vf7y\n\tvmaddz.xyz vf3, vf1, vf7z");
            asm("sqc2 vf6, %0" : "=m"(f.em[2]));
            asm("sqc2 vf3, %0" : "=m"(f.em[1]));
            asm("sqc2 vf3, %0" : "=m"(f.jC0));
            asm("sqc2 vf8, %0" : "=m"(f.j50));
            asm("sqc2 vf7, %0" : "=m"(f.j60));
            asm("sqc2 vf5, %0" : "=m"(f.j70));
            asm("sqc2 vf4, %0" : "=m"(f.jB0));
            asm("sqc2 vf4, %0" : "=m"(f.em[0]));
            asm("sqc2 vf6, %0" : "=m"(f.jD0));
            asm("sqc2 vf4, %0" : "=m"(stuck->row0));
            float lim = 0.7f;
            stuck->row1 = f.em[1];
            stuck->row2 = f.em[2];
            float dotv;
            asm("lqc2 vf1, %0" : : "m"(*up));
            asm("lqc2 vf3, %0" : : "m"(normal));
            asm("vmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
            int bits;
            asm("qmfc2.ni %0, vf1" : "=r"(bits));
            asm("mtc1 %1, %0\n\tnop" : "=f"(dotv) : "r"(bits));
            if ((dotv < 0 ? -dotv : dotv) < lim) {
                QW nxy;
                asm("qmfc2.ni %0, vf3" : "=r"(nxy));
                f.em[0] = nxy;
                ((float *)&f.em[0])[2] = zero;
                BuildRotateVectorsMatrix(f.rot, f.em[0], nxy);
                float m50 = -50.0f;
                asm("lqc2 vf4, %0" : : "m"(f.rot[0]));
                asm("lqc2 vf2, %0" : : "m"(f.rot[1]));
                asm("lqc2 vf3, %0" : : "m"(f.rot[2]));
                int mb;
                asm("mfc1 %0, %1" : "=r"(mb) : "f"(m50));
                asm("lqc2 vf1, %0" : : "m"(*up));
                asm("qmtc2.ni %0, vf5" : : "r"(mb));
                asm("vmulx.xyzw vf1, vf1, vf5x");
                asm("sqc2 vf4, %0" : "=m"(f.em[1]));
                asm("vmulax.xyz ACC, vf4, vf1x\n\tvmadday.xyz ACC, vf2, vf1y\n\tvmaddz.xyz vf1, vf3, vf1z");
                asm("sqc2 vf2, %0" : "=m"(f.em[2]));
                asm("sqc2 vf3, %0" : "=m"(f.jB0));
                asm("sqc2 vf5, %0" : "=m"(f.jC0));
                asm("sqc2 vf1, %0" : "=m"(stuck->v));
            }
            stuck->posz = stuck->posz + src->pripg->lift;
        }
    }
    return stuck;
}
