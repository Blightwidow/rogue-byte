#include "sly2.h"
struct M3_224EC8 { QW row[3]; };
struct XF_224EC8 { char pad0[0x30]; QW pos; char pad40[0xA0 - 0x40]; void *pxfParent; char padA4[0xB0 - 0xA4]; int vel[3]; };
struct Gadget_224EC8 {
    char pad0[0x58]; XF_224EC8 *pxfA; XF_224EC8 *pxfB; char pad60[0x150 - 0x60];
    int state; float tState; int stateNext; int kind; void *ploTarget; char pad164[4]; void *psma;
    char pad16C[0x17C - 0x16C]; void *pactB; void *pactA; char pad184[0x190 - 0x184]; QW dirLocal;
};
struct Frame_224EC8 { union { M3_224EC8 matCopy; QW dpos; }; M3_224EC8 mat; void *aplo[0x20]; QW posOther; QW dirA; };
extern "C" {
void BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M3_224EC8 *, QW, QW);
QW ConvertXfVec(int, void *, QW);
int CploFindSwObjectsByClass(void *, int, int, void *, int, void **);
QW DecomposeRotateMatrixEuler(M3_224EC8 *);
int FGadgetObjIsKindB(Gadget_224EC8 *);
void FadeAloOut(Gadget_224EC8 *, float);
QW PosLoWorld(void *);
void RecalcSwOxfFilterForObject(void *, void *);
void SetSmaGoalIfReachable(void *, int);
void SetSoCnstrForce(Gadget_224EC8 *, int);
void SetSoCnstrTorque(Gadget_224EC8 *, int);
void *func_0012DC18(Gadget_224EC8 *, XF_224EC8 *, int, int, int, QW);
void func_0012E460(void *);
void func_001A58D0(Gadget_224EC8 *, int, int);
extern char B_003DD490;
extern int D_002C4398[];
extern QW g_2a2dc0;
extern struct CLOCK_224EC8 { float t; float dt; } g_2dded0;
extern void *g_2e1e40;
}
static inline void ClearVel(XF_224EC8 *pxf)
{
    int *pvel = pxf->vel;
    pvel[2] = 0;
    pvel[1] = 0;
    pxf->vel[0] = 0;
}
extern "C" void SetGadgetObjState(Gadget_224EC8 *gadget, int stateNew)
{
    Frame_224EC8 frame;
    int statePrev = gadget->state;
    if (stateNew == statePrev)
        return;
    gadget->state = stateNew;
    gadget->tState = g_2dded0.t;
    gadget->stateNext = -1;
    func_0012E460(&gadget->pactA);
    func_0012E460(&gadget->pactB);
    if (statePrev == 0 || statePrev == 4)
        RecalcSwOxfFilterForObject(&B_003DD490, gadget);
    switch (gadget->state) {
    case 0: {
        SetSoCnstrForce(gadget, 0);
        SetSoCnstrTorque(gadget, 0);
        ClearVel(gadget->pxfA);
        ClearVel(gadget->pxfB);
        QW pos = gadget->pxfA->pos;
        QW euler = DecomposeRotateMatrixEuler((M3_224EC8 *)gadget->pxfB);
        gadget->pactA = func_0012DC18(gadget, gadget->pxfA, 0, 7, 2, pos);
        gadget->pactB = func_0012DC18(gadget, gadget->pxfB, 0, 7, 2, euler);
        RecalcSwOxfFilterForObject(&B_003DD490, gadget);
        break;
    }
    case 2: {
        SetSoCnstrForce(gadget, 1);
        SetSoCnstrTorque(gadget, 1);
        ClearVel(gadget->pxfA);
        ClearVel(gadget->pxfB);
        if (FGadgetObjIsKindB(gadget) != 0 && gadget->pxfB != 0) {
            int fenceA, fenceB;
            QW dirA = ConvertXfVec(0, gadget->pxfB->pxfParent, gadget->dirLocal);
            asm("qmtc2.ni %1, vf1" : "=r"(fenceA) : "r"(dirA));
            void *pxfParent = gadget->pxfB->pxfParent;
            asm("vmul.xyz vf3, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf2, vf3z" : "=r"(fenceB) : "r"(fenceA));
            asm("vsqrt Q, vf3x\n\tvwaitq\n\tvaddq.x vf3, vf0, Q" : "=r"(fenceA) : "r"(fenceB));
            asm("vdiv Q, vf0w, vf3x\n\tvwaitq\n\tvmulq.xyzw vf3, vf1, Q" : "=r"(fenceB) : "r"(fenceA));
            asm("sqc2 vf3, %0" : "=m"(frame.dirA) : "r"(fenceB));
            QW dirB = ConvertXfVec(0, pxfParent, g_2a2dc0);
            asm("lqc2 vf3, %1" : "=r"(fenceA) : "m"(frame.dirA));
            asm("qmtc2.ni %1, vf2" : "=r"(fenceB) : "r"(dirB), "r"(fenceA));
            asm("vmul.xyz vf1, vf2, vf2\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z" : "=r"(fenceA) : "r"(fenceB));
            QW a;
            asm("qmfc2.ni %0, vf3" : "=r"(a), "=r"(fenceB) : "r"(fenceA));
            asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r"(fenceA) : "r"(fenceB));
            asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf3, vf2, Q" : "=r"(fenceB) : "r"(fenceA));
            QW b;
            asm("qmfc2.ni %0, vf3" : "=r"(b) : "r"(fenceB));
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&frame.mat, a, b);
            frame.matCopy = frame.mat;
            QW euler = DecomposeRotateMatrixEuler(&frame.matCopy);
            gadget->pactB = func_0012DC18(gadget, gadget->pxfB, 0, 7, 2, euler);
        }
        break;
    }
    case 1:
        func_001A58D0(gadget, 0, 0xF);
        SetSoCnstrForce(gadget, 0);
        if (gadget->kind != 0x29) {
            SetSoCnstrTorque(gadget, 0);
        } else {
            SetSoCnstrTorque(gadget, 1);
            int cplo = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x38, 0, 0x20, frame.aplo);
            void *ploBest = g_2e1e40;
            float sBest = 3.4028235e38f;
            for (int iplo = 0; iplo < cplo; iplo++) {
                {
                    void *plo = frame.aplo[iplo];
                    int fenceA, fenceB;
                    QW posOther = PosLoWorld(plo);
                    asm("qmtc2.ni %1, vf1" : "=r"(fenceA) : "r"(posOther));
                    asm("sqc2 vf1, %0" : "=m"(frame.posOther) : "r"(fenceA));
                    QW posSelf = PosLoWorld(gadget);
                    asm("qmtc2.ni %1, vf2" : "=r"(fenceA) : "r"(posSelf));
                    asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(frame.dpos) : "m"(frame.posOther), "r"(fenceA));
                    ((float *)&frame.dpos)[2] *= 2.0f;
                    float s;
                    int bits;
                    asm("lqc2 vf1, %2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f"(s), "=r"(bits) : "m"(frame.dpos));
                    if (s < sBest) {
                        sBest = s;
                        ploBest = plo;
                    }
                }
            }
            gadget->ploTarget = ploBest;
        }
        break;
    case 4:
        RecalcSwOxfFilterForObject(&B_003DD490, gadget);
        FadeAloOut(gadget, 0.25f);
        break;
    }
    if (gadget->psma != 0 && gadget->state >= 0)
        SetSmaGoalIfReachable(gadget->psma, D_002C4398[gadget->state]);
}
