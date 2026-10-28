/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XF { char local[0x40]; char world[0x40]; char pad80[0x20]; XF *parent; int generation; char padA8[0x58]; };
struct ALO { char pad[0x50]; int cxf; XF *axf; };
extern "C" {
extern const char RO_002A2D30[];
void func_0022FA20(ALO *);
void UpdateAloXfWorld(ALO *alo);
}
#define VU(text, ...) asm(text : "+r" (tok) : __VA_ARGS__)
void UpdateAloXfWorld(ALO *alo)
{
    register int tok asm("$24");
    register int ltok asm("$25");
    int count = alo->cxf;
    if (count > 0) {
        XF *xf = alo->axf;
        XF *end = xf + count;
        XF *last;
        register QW t1 asm("$9");
        register QW t0 asm("$8");
        register QW a3 asm("$7");
        register QW a2 asm("$6");
        register QW t5 asm("$13");
        register QW t4 asm("$12");
        register QW t3 asm("$11");
        register QW t2 asm("$10");
        register XF *parent asm("$3") = xf->parent;
        last = end - 1;
        if (parent) {
            VU("lqc2 vf4, 0x70(%1)", "r" (parent));
            VU("lqc2 vf1, 0x40(%1)", "r" (parent));
            VU("lqc2 vf2, 0x50(%1)", "r" (parent));
            VU("lqc2 vf3, 0x60(%1)", "r" (parent));
        } else {
            const char *identity = RO_002A2D30;
            VU("lqc2 vf4, 0x30(%1)", "r" (identity));
            VU("lqc2 vf1, 0x0(%1)", "r" (identity));
            VU("lqc2 vf2, 0x10(%1)", "r" (identity));
            VU("lqc2 vf3, 0x20(%1)", "r" (identity));
        }
        VU("lqc2 vf5, 0x0(%1)", "r" (xf));
        VU("lqc2 vf6, 0x10(%1)", "r" (xf));
        VU("lqc2 vf7, 0x20(%1)", "r" (xf));
        VU("lqc2 vf8, 0x30(%1)", "r" (xf));
        if (!(last < xf)) {
            int done;
            do {
                asm volatile("vcallms 0x60" : "+r" (tok));
                if (xf < last) {
                    XF *nextParent = xf[1].parent;
                    t1 = *(QW *)((char *)xf + 0x100);
                    if (nextParent != xf) {
                        asm("lq %0, 0x70(%2)" : "=r" (t5), "+r" (ltok) : "r" (nextParent));
                        asm("lq %0, 0x40(%2)" : "=r" (t4), "+r" (ltok) : "r" (nextParent));
                        asm("lq %0, 0x50(%2)" : "=r" (t3), "+r" (ltok) : "r" (nextParent));
                        asm("lq %0, 0x60(%2)" : "=r" (t2), "+r" (ltok) : "r" (nextParent));
                    }
                    t0 = *(QW *)((char *)xf + 0x110);
                    a3 = *(QW *)((char *)xf + 0x120);
                    a2 = *(QW *)((char *)xf + 0x130);
                }
                XF *p = xf->parent;
                if (p) {
                    int g = p->generation;
                    if (xf->generation < g) xf->generation = g;
                }
                int status;
                asm("cfc2.i %0, $vi0" : "=r" (status), "+r" (tok));
                VU("sqc2 vf5, 0x40(%1)", "r" (xf));
                VU("sqc2 vf6, 0x50(%1)", "r" (xf));
                VU("sqc2 vf7, 0x60(%1)", "r" (xf));
                VU("sqc2 vf8, 0x70(%1)", "r" (xf));
                if (xf[1].parent != xf) {
                    VU("qmtc2.ni %1, vf1", "r" (t4));
                    VU("qmtc2.ni %1, vf2", "r" (t3));
                    VU("qmtc2.ni %1, vf3", "r" (t2));
                    VU("qmtc2.ni %1, vf4", "r" (t5));
                } else {
                    VU("vmove.xyzw vf1, vf5\n\tvmove.xyzw vf2, vf6\n\tvmove.xyzw vf3, vf7\n\tvmove.xyzw vf4, vf8", "i" (0));
                }
                asm("" : "+r" (tok), "+r" (xf));
                xf++;
                VU("qmtc2.ni %1, vf5", "r" (t1), "r" (xf));
                VU("qmtc2.ni %1, vf6", "r" (t0));
                asm("" : "+r" (tok), "+r" (xf));
                done = last < xf;
                VU("qmtc2.ni %1, vf7", "r" (a3), "r" (done));
                VU("qmtc2.ni %1, vf8", "r" (a2));
            } while (!done);
        }
    }
    asm volatile("" : : "r" (tok), "r" (ltok));
    func_0022FA20(alo);
}
