#include "sly2.h"
static inline QW Rot(QW q) { QW r; asm volatile("prot3w %0, %1" : "=r" (r) : "r" (q)); return r; }
static inline QW Ext(QW q) { QW r; asm volatile("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
struct CRV;
struct ROWS3 { QW row[3]; };
struct GROUP { int cvertex; char pad[8]; float *pout; char pad2[0xC]; QW *avecBound; };
struct NODE { int pad; int cgroup; GROUP *agroup; NODE *pnext; };
struct SO { char pad[0xDC]; NODE *pnode; char pad2[0x150 - 0xE0]; CRV *pcrv; };
extern "C" {
void func_001F3C70(SO *);
float UMaxCrv(CRV *);
ROWS3 *PmatLoWorld(SO *);
void EvaluateCrvFromU(CRV *, float, QW *, QW *);
ROWS3 *BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(ROWS3 *, QW, QW);
void func_001E9AC0(SO *pso)
{
    struct { QW pos; QW tangent; ROWS3 junk; ROWS3 mat; } l;
    func_001F3C70(pso);
    float uMax = UMaxCrv(pso->pcrv);
    QW up = PmatLoWorld(pso)->row[2];
    for (NODE *pnode = pso->pnode; pnode != 0; pnode = pnode->pnext) {
        for (int igroup = 0; igroup < pnode->cgroup; igroup++) {
            GROUP *pgroup = &pnode->agroup[igroup];
            int ivertex = 0;
            QW *pbound = pgroup->avecBound;
            float *pout = pgroup->pout;
            while (ivertex < pgroup->cvertex) {
                float w = ((float *)pbound)[3];
                float u = w < uMax ? w : uMax;
                ivertex++;
                EvaluateCrvFromU(pso->pcrv, u, &l.pos, &l.tangent);
                BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&l.mat, l.tangent, up);
                register QW v2 asm("vf2") = l.mat.row[2];
                l.junk.row[2] = v2;
                register QW v5 asm("vf5") = l.mat.row[0];
                l.junk.row[0] = v5;
                register QW v4 asm("vf4") = l.mat.row[1];
                l.junk.row[1] = v4;
                QW pos;
                int chain;
                asm("lqc2 vf3, %1\n\tlqc2 vf1, %2\n\tvmulax.xyz ACC, vf5, vf1x\n\tvmadday.xyz ACC, vf4, vf1y\n\tvmaddz.xyz vf1, vf2, vf1z" : "=r" (chain) : "m" (l.pos), "m" (*pbound));
                pbound++;
                asm("vadd.xyzw vf2, vf1, vf3\n\tqmfc2.ni %0, vf2" : "=r" (pos) : "r" (chain));
                QW zlane = Ext(pos);
                asm volatile("sw %1, %0" : "=m" (*(int *)pout) : "r" (pos));
                float z = Lane(zlane);
                float y = Lane(Rot(pos));
                pout[2] = z;
                pout[1] = y;
                pout += 4;
            }
        }
    }
    func_001F3C70(pso);
}
}
