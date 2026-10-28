#include "sly2.h"
struct CRef { int tagk; union { int n; float g; QW *pv; }; };
extern "C" CRef *func_00122730(CRef *prefReturn, int carg, CRef *aref) { QW *pvecA = aref[0].pv; QW *pvecB = aref[1].pv; int result; int tag = 0x16; asm("lqc2 vf1, %0\n\tlqc2 vf2, %1\n\tvmul.xyz vf1, vf1, vf2\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf3, vf1z" : : "m" (*pvecA), "m" (*pvecB)); prefReturn->tagk = tag; asm("qmfc2.ni %0, vf1" : "=r" (result)); prefReturn->n = result; return prefReturn; }
