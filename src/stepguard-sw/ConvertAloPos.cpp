typedef int QW __attribute__((mode(TI)));
struct M4 { QW row[4]; };
struct VT { char pad[0xF8]; short delta; short index; M4 *(*fn)(void *); };
struct ALO { char pad[0xC]; VT *vptr; };
extern "C" void InvertMatrix4Affine(M4 *, M4 *);

QW ConvertAloPos(ALO *from, ALO *to, QW pos)
{
    struct F { M4 inv; QW pos; } f;
    f.pos = pos;
    if (from != 0) {
        VT *vt = from->vptr;
        M4 *mat = vt->fn((char *)from + vt->delta);
        asm("lqc2 vf4, %0" : : "m" (mat->row[3]));
        asm("lqc2 vf3, %0" : : "m" (mat->row[0]));
        asm("lqc2 vf2, %0" : : "m" (mat->row[1]));
        asm("lqc2 vf1, %0" : : "m" (mat->row[2]));
        asm("lqc2 vf5, %0" : : "m" (f.pos));
        asm("vmulax.xyz ACC, vf3, vf5x\n\tvmadday.xyz ACC, vf2, vf5y\n\tvmaddaz.xyz ACC, vf1, vf5z\n\tvmaddw.xyz vf5, vf4, vf0w");
        asm("sqc2 vf5, %0" : "=m" (f.pos));
    }
    if (to != 0) {
        VT *vt = to->vptr;
        M4 *mat = vt->fn((char *)to + vt->delta);
        InvertMatrix4Affine(&f.inv, mat);
        asm("lqc2 vf5, %0" : : "m" (f.pos));
        asm("lqc2 vf4, %0" : : "m" (f.inv.row[0]));
        asm("lqc2 vf3, %0" : : "m" (f.inv.row[1]));
        asm("lqc2 vf2, %0" : : "m" (f.inv.row[2]));
        asm("lqc2 vf1, %0" : : "m" (f.inv.row[3]));
        asm("vmulax.xyz ACC, vf4, vf5x\n\tvmadday.xyz ACC, vf3, vf5y\n\tvmaddaz.xyz ACC, vf2, vf5z\n\tvmaddw.xyz vf5, vf1, vf0w");
        asm("sqc2 vf5, %0" : "=m" (f.pos));
    }
    return f.pos;
}
