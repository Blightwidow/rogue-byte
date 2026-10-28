typedef int QW __attribute__((mode(TI)));
struct PIVOT { char pad[0x134]; int radius; };
struct XF { char pad[0x70]; QW pos; };
struct JT { char pad0[0x18C4]; PIVOT *pivot; char pad18C8[0x19CC - 0x18C8]; XF *xf; };
extern QW g_2a2dc0;
QW PosLoWorld(PIVOT *);

QW PosJtHangGrip(JT *jt)
{
    QW pos = PosLoWorld(jt->pivot);
    XF *xf = jt->xf;
    int lenbits;
    QW junk;
    asm("qmtc2.ni %0, vf4" : : "r" (pos));
    QW up = g_2a2dc0;
    float eps = 0.0001f;
    asm("lqc2 vf1, %0" : : "m" (xf->pos));
    asm("vsub.xyzw vf3, vf4, vf1\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (lenbits));
    float len = *(float *)&lenbits;
    asm volatile("qmtc2.ni %0, vf2" : : "r" (up) : "memory");
    if (len < eps) {} else
        asm("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q");
    int radius = jt->pivot->radius;
    QW result;
    asm("qmtc2.ni %0, vf1" : : "r" (radius));
    asm("vadda.xyzw ACC, vf0, vf4\n\tvmaddx.xyzw vf3, vf2, vf1x");
    asm("sqc2 vf1, %0" : "=m" (junk));
    asm("qmfc2.ni %0, vf3" : "=r" (result));
    return result;
}
