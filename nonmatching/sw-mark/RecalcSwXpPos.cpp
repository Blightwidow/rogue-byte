#include "sly2.h"
struct Ref1A7E60 { char pad[8]; float value; };
struct Xf1A7E60 { char pad[0x70]; QW pos; };
struct Entry1A7E60 { Ref1A7E60 *pref; Xf1A7E60 *pxf; char pad8[8]; QW out; QW local; char pad30[0x10]; };
struct Sw1A7E60 { Entry1A7E60 entry[2]; QW axis; float result; char pad94[8]; int kind; };
extern "C" QW ConvertXfPos(void *, void *, QW);
extern "C" void RecalcSwXpPos(void *unused, int count, Sw1A7E60 **apsw)
{
    QW spill;
    int index;
    for (index = 0; index < count; index++) {
        Sw1A7E60 *psw = apsw[index];
        Entry1A7E60 *pentry = &psw->entry[0];
        for (int side = 0; side < 2; side++, pentry++) {
            Xf1A7E60 *pxf = pentry->pxf;
            int valueBits;
            if (pxf == 0)
                continue;
            if (side == 0) {
                int kind = psw->kind;
                if (kind < 7) {
                    if (kind < 4)
                        goto convert;
                } else {
                    goto convert;
                }
                float negated = -pentry->pref->value;
                asm volatile("mfc1 %0, %1\n qmtc2.ni %0, vf2" : "=r" (valueBits) : "f" (negated));
            } else {
                int kind = psw->kind;
                if (kind != 7 && kind != 9)
                    goto convert;
                valueBits = *(int *)&pentry->pref->value;
                asm volatile("qmtc2.ni %0, vf2" : : "r" (valueBits));
            }
            asm volatile("lqc2 vf3, %0" : : "m" (pxf->pos));
            asm volatile("sqc2 vf2, %0" : "=m" (spill));
            asm volatile("lqc2 vf1, %0" : : "m" (psw->axis));
            asm volatile("vadda.xyzw ACC, vf3, vf0");
            asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
            asm volatile("sqc2 vf3, %0" : "=m" (pentry->out));
            continue;
        convert:
            pentry->out = ConvertXfPos(pxf, 0, pentry->local);
        }
        int bits;
        asm volatile("lqc2 vf3, %0" : : "m" (psw->entry[1].out));
        asm volatile("lqc2 vf2, %0" : : "m" (psw->entry[0].out));
        asm volatile("vsub.xyzw vf2, vf2, vf3");
        asm volatile("lqc2 vf1, %0" : : "m" (psw->axis));
        asm volatile("vmul.xyz vf1, vf1, vf2");
        asm volatile("vaddw.x vf3, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf3, vf1z");
        asm volatile("qmfc2.ni %0, vf1" : "=r" (bits));
        *(int *)&psw->result = bits;
    }
}
