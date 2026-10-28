// SPDX-License-Identifier: GPL-3.0-or-later
typedef int QW __attribute__((mode(TI)));
struct PO { char p0[0x1044]; int fLook; float rad; char p1[0x14]; QW look; QW dir; };
struct SEQNODE { char pad0[0x24]; void *psubject; char pad1[0x4C]; void *plook; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" QW PosLoWorld(PO *);
extern "C" void GetSeqnodeObjectPosRad(SEQNODE *, void *, QW *, void *);
extern QW g_2a2dd0;

extern "C" void func_001E5000(SEQNODE *pseqnode, void *pso)
{
    PO *ppo;
    if (pseqnode->psubject != 0 && FIsBasicDerivedFrom(pseqnode->psubject, 0x34) != 0)
        ppo = (PO *)pseqnode->psubject;
    else
        ppo = 0;
    if (pseqnode->plook != 0) {
        if (ppo != 0) {
            ppo->fLook = 0;
            QW look = ppo->look;
            QW pos = PosLoWorld(ppo);
            asm("lqc2 vf2, %0" : : "m" (look));
            asm("qmtc2.ni %0, vf3" : : "r" (pos));
            asm("vsub.xyzw vf1, vf2, vf3");
            asm("sqc2 vf1, %0" : "=m" (ppo->dir));
            ((float *)&ppo->dir)[2] = 0.0f;
        }
        pseqnode->plook = 0;
    }
    if (pso != 0) {
        if (ppo != 0) {
            ppo->fLook = 1;
            GetSeqnodeObjectPosRad(pseqnode, pso, &ppo->look, 0);
            ((float *)&ppo->look)[2] += ppo->rad;
            ppo->dir = g_2a2dd0;
        }
        pseqnode->plook = pso;
    }
}
