#include "sly2.h"
extern "C" {
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
int *PvAllocStackImpl__Fi(int *);
void SetJmpBodyState(char *, int, int);
void SolveInequalities(int, int *, int *, int *, float);
extern char g_2a2dc0[];
extern float g_2a63b0;
void LimitJmpAccelByContacts(char *self, QW *velocity) {
    struct Locals {
        QW contacts[0x40];
        int request[4];
        char frame[0x10];
        QW accumulated;
        QW original;
    } locals;
    unsigned count = 0;
    char *list = *(char **)(*(char **)(*(char **)self + 0xEC) + 0x64);
    for (;;) {
        char *contact;
        if (list == 0) {
            contact = *(char **)(*(char **)(*(char **)self + 0xEC) + 0x68);
        } else {
            contact = *(char **)list;
        }
        if (contact != 0) {
            do {
                if (count >= 0x40) {
                    goto done;
                }
                asm volatile("lqc2 vf4, 0x80(%0)" : : "r"(contact));
                if (*(char **)self != *(char **)(contact + 8)) {
                    asm volatile("qmtc2.ni %1, vf1\n\tsqc2 vf1, %0\n\tvmulx.xyzw vf4, vf4, vf1x" : "=m"(*(QW *)locals.request) : "r"(0xBF800000));
                }
                int bits;
                int upper;
                asm volatile("qmfc2.ni %0, vf4" : "=r"(bits));
                asm("pextuw %0, $0, %1" : "=r"(upper) : "r"(bits));
                if (!(*(float *)&upper > 0.7f)) {
                    asm volatile("lqc2 vf1, (%0)" : : "r"(g_2a2dc0));
                    asm volatile("vmul.xyz vf2, vf4, vf1");
                    asm volatile("vaddw.x vf3, vf0, vf0w");
                    asm volatile("vadday.x ACC, vf2, vf2y");
                    asm volatile("vmaddz.x vf2, vf3, vf2z");
                    asm volatile("vmulx.xyzw vf2, vf1, vf2x");
                    asm volatile("vsub.xyzw vf4, vf4, vf2");
                    asm volatile("sqc2 vf4, %0" : "=m"(locals.contacts[count]));
                    count += 1;
                }
                contact = *(char **)(contact + 0xAC);
            } while (contact != 0);
        }
        if (list == 0) {
            break;
        }
        list = *(char **)(list + 4);
    }
done:
    if (count != 0) {
        int bytes = count * 4;
        CStackFrame_Construct(locals.frame);
        locals.request[0] = bytes;
        locals.request[0] = count * count * 4;
        int *matrix = PvAllocStackImpl__Fi(locals.request);
        locals.request[1] = 0x10;
        locals.request[1] = 0x10;
        int *offsets = PvAllocStackImpl__Fi(locals.request);
        locals.request[0] = bytes;
        locals.request[1] = 0x10;
        int *solution = PvAllocStackImpl__Fi(locals.request);
        int *out = matrix;
        for (int row = 0; row < (int)count; row++) {
            for (int column = 0; column < (int)count; column++) {
                asm volatile("lqc2 vf1, %0" : : "m"(locals.contacts[column]));
                asm volatile("lqc2 vf2, %0" : : "m"(locals.contacts[row]));
                asm volatile("vmul.xyz vf2, vf2, vf1");
                asm volatile("vaddw.x vf3, vf0, vf0w");
                asm volatile("vadday.x ACC, vf2, vf2y");
                asm volatile("vmaddz.x vf2, vf3, vf2z");
                int value;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(value));
                *out = value;
                out += 1;
            }
        }
        QW start = *velocity;
        locals.accumulated = start;
        locals.original = start;
        out = offsets;
        if ((int)count > 0) {
            asm volatile("qmtc2.ni %0, vf3" : : "r"(start));
            for (int index = 0; index < (int)count; index++) {
                asm volatile("lqc2 vf1, %0" : : "m"(locals.contacts[index]));
                asm volatile("vmul.xyz vf1, vf3, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                int value;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(value));
                *out = value;
                out += 1;
            }
        }
        SolveInequalities(count, matrix, offsets, solution, g_2a63b0);
        for (int index = 0; index < (int)count; index++) {
            asm volatile("qmtc2.ni %0, vf2" : : "r"(solution[index]));
            asm volatile("lqc2 vf3, %0" : : "m"(locals.accumulated));
            asm volatile("sqc2 vf2, %0" : "=m"(*(QW *)locals.request));
            asm volatile("lqc2 vf1, %0" : : "m"(locals.contacts[index]));
            asm volatile("vadda.xyzw ACC, vf0, vf3");
            asm volatile("vmaddx.xyzw vf3, vf1, vf2x");
            asm volatile("sqc2 vf3, %0" : "=m"(locals.accumulated));
        }
        asm volatile("lqc2 vf2, %0" : : "m"(locals.original));
        asm volatile("lqc2 vf3, %0" : : "m"(locals.accumulated));
        asm volatile("vsub.xyzw vf1, vf2, vf3");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        int lengthBits;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(lengthBits));
        if (*(float *)&lengthBits > 1.0f) {
            unsigned state = *(unsigned *)(self + 0x1C);
            if (state == 0) {
                SetJmpBodyState(self, 1, 0);
            } else if (state == 2) {
                SetJmpBodyState(self, 3, 0);
            }
        }
        *velocity = locals.accumulated;
        CStackFrame_Destructor(locals.frame, 2);
    }
}
}
