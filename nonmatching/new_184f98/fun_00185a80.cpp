typedef int s32;
typedef char s8;
extern const float RO_002A568C;
extern "C" void SolveInequalities(s32, s32 *, float *, s32 *, float);
s32 func_00185A80(s32 arg0, s32 *arg1, s32 arg2) {
    char sp[0xF0] __attribute__((aligned(16)));
    s32 fence;
    s32 count = *arg1;
    asm volatile("qmtc2.ni %1, vf4" : "=r"(fence) : "r"(arg2));
    if (count != 0) {
        s32 *out = (s32 *)sp;
        s32 row = 0;
        if (count > 0) {
            s32 column = 0;
            do {
                if (*arg1 > 0) {
                    s8 *rowPointer = (s8 *)(arg1 + 4) + row * 0x10;
                    s8 *columnPointer = (s8 *)(arg1 + 4);
                    do {
                        asm volatile("lqc2 vf2, (%0)" : : "r"(columnPointer), "r"(fence) : "memory");
                        column += 1;
                        asm volatile("lqc2 vf1, (%0)" : : "r"(rowPointer + 0x10) : "memory");
                        columnPointer += 0x10;
                        asm volatile("vmul.xyz vf1, vf1, vf2");
                        asm volatile("vaddw.x vf3, vf0, vf0w");
                        asm volatile("vadday.x ACC, vf1, vf1y");
                        asm volatile("vmaddz.x vf1, vf3, vf1z");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        *out = vu_1;
                        out += 1;
                    } while (column < *arg1);
                }
                row += 1;
                column = 0;
            } while (row < *arg1);
        }
        float *offsets = (float *)(sp + 0x90);
        s32 index = 0;
        if (*arg1 > 0) {
            asm volatile("vmove.xyzw vf3, vf4");
            s8 *planePointer = (s8 *)(arg1 + 4);
            do {
                asm volatile("lqc2 vf1, (%0)" : : "r"(planePointer));
                index += 1;
                asm volatile("vmul.xyz vf1, vf3, vf1");
                asm volatile("vaddw.x vf2, vf0, vf0w");
                asm volatile("vadday.x ACC, vf1, vf1y");
                asm volatile("vmaddz.x vf1, vf2, vf1z");
                float temp = *(float *)(planePointer + 0xC);
                planePointer += 0x10;
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_2));
                *offsets = *(float *)&vu_2 + temp;
                offsets += 1;
            } while (index < *arg1);
        }
        asm volatile("sqc2 vf4, 0xe0(%0)" : : "r"(sp));
        SolveInequalities(*arg1, (s32 *)sp, (float *)(sp + 0x90), (s32 *)(sp + 0xB0), RO_002A568C);
        s32 remaining = *arg1;
        asm volatile("lqc2 vf4, 0xe0(%0)" : : "r"(sp));
        if (remaining > 0) {
            s8 *normalPointer = (s8 *)(arg1 + 4);
            s32 *solution = (s32 *)(sp + 0xB0);
            do {
                remaining -= 1;
                asm volatile("qmtc2.ni %0, vf2" : : "r"(*solution));
                asm volatile("lqc2 vf1, (%0)" : : "r"(normalPointer));
                asm volatile("vadda.xyzw ACC, vf0, vf4");
                asm volatile("vmaddx.xyzw vf4, vf1, vf2x");
                normalPointer += 0x10;
                solution += 1;
            } while (remaining != 0);
            asm volatile("sqc2 vf2, 0xd0(%0)" : : "r"(sp));
        }
    }
    s32 vu_3;
    asm volatile("qmfc2.ni %0, vf4" : "=r"(vu_3));
    return vu_3;
}
