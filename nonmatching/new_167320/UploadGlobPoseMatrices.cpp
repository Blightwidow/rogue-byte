#include "sly2.h"
struct XF { char pad[0x40]; QW m0, m1, m2, m3; };
struct POSE { char pad0[0xC]; XF *xf; QW bind0, bind1, bind2, bind3; };
struct GLOB { char pad[1]; signed char cpose; char pad1[0xA]; unsigned ivu; };
struct GLOBI { char pad[0x18]; POSE *poses; };
struct DMAS2 { char pad[0xC]; unsigned *cursor; };
extern "C" DMAS2 g_2dea28;
extern "C" void UploadGlobPoseMatrices(void *set, GLOB *glob, GLOBI *globi)
{
    unsigned *cur = g_2dea28.cursor;
    while (((unsigned)cur & 0xF) != 0xC) {
        *cur = 0;
        g_2dea28.cursor++;
        cur = g_2dea28.cursor;
    }
    unsigned word = glob->cpose << 18;
    word |= 0x6000C000;
    word |= 0x0C000000;
    word |= glob->ivu;
    *g_2dea28.cursor = word;
    g_2dea28.cursor++;
    QW *out = (QW *)g_2dea28.cursor;
    POSE *pose = globi->poses;
    POSE *last = pose + glob->cpose - 1;
    XF *xf = pose->xf;
    register QW t1 asm("$9");
    register QW t2 asm("$10");
    register QW t3 asm("$11");
    register QW t4 asm("$12");
    register QW t5 asm("$13");
    register QW t6 asm("$14");
    register QW t7 asm("$15");
    register QW t8 asm("$24");
    asm("lqc2 vf5, %0" : : "m" (pose->bind0));
    asm("lqc2 vf4, %0" : : "m" (xf->m3));
    asm("lqc2 vf6, %0" : : "m" (pose->bind1));
    asm("lqc2 vf7, %0" : : "m" (pose->bind2));
    asm("lqc2 vf8, %0" : : "m" (pose->bind3));
    asm("lqc2 vf1, %0" : : "m" (xf->m0));
    asm("lqc2 vf2, %0" : : "m" (xf->m1));
    asm("lqc2 vf3, %0" : : "m" (xf->m2));
    goto entry;
top:
    asm("qmtc2.ni %0, vf1" : : "r" (t6));
    pose++;
    asm("qmtc2.ni %0, vf2" : : "r" (t5));
    asm("qmtc2.ni %0, vf3" : : "r" (t4));
    asm("qmtc2.ni %0, vf4" : : "r" (t7));
    asm("qmtc2.ni %0, vf5" : : "r" (t8));
    asm("qmtc2.ni %0, vf6" : : "r" (t3));
    asm("qmtc2.ni %0, vf7" : : "r" (t2));
    asm("qmtc2.ni %0, vf8" : : "r" (t1));
entry:
    asm("vcallms 0x60");
    if (pose < last) {
        XF *nextxf = pose[1].xf;
        t8 = pose[1].bind0;
        t7 = nextxf->m3;
        t6 = nextxf->m0;
        t5 = nextxf->m1;
        t4 = nextxf->m2;
        t3 = pose[1].bind1;
        t2 = pose[1].bind2;
        t1 = pose[1].bind3;
    }
    asm volatile("cfc2.i $2, $vi0" : : : "$2");
    asm("sqc2 vf5, 0(%0)" : : "r" (out) : "memory");
    out++;
    asm("sqc2 vf6, 0(%0)" : : "r" (out) : "memory");
    out++;
    asm("sqc2 vf7, 0(%0)" : : "r" (out) : "memory");
    out++;
    asm("sqc2 vf8, 0(%0)" : : "r" (out) : "memory");
    out++;
    if (pose != last)
        goto top;
    g_2dea28.cursor = (unsigned *)out;
}
