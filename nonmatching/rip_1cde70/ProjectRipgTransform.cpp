typedef int QW __attribute__((mode(TI)));
struct Node_1CDF88 { char pad[0x14]; float radius; };
struct Iter_1CDF88 { Node_1CDF88 **start; Node_1CDF88 **cursor; int stride; void *saved; };
extern "C" void func_001F4B58(void *);
extern void *g_2dd2fc;
extern float g_2dded0;
extern const float RO_002A77D0;
extern const float RO_002A77D4;
struct Obj_1CDF88 { char pad[0x154]; float margin; };
extern "C" void ProjectRipgTransform(char *self) {
    char sp[0x40] __attribute__((aligned(16)));
    Iter_1CDF88 iter;
    iter.start = (Node_1CDF88 **)(self + 0x15C);
    iter.cursor = iter.start;
    iter.stride = *(int *)(self + 0x164);
    iter.saved = g_2dd2fc;
    float *low = (float *)(sp + 0x10);
    float *high = (float *)(sp + 0x20);
    low[1] = RO_002A77D0;
    low[2] = RO_002A77D0;
    low[0] = RO_002A77D0;
    high[1] = RO_002A77D4;
    high[2] = RO_002A77D4;
    high[0] = RO_002A77D4;
    g_2dd2fc = sp;
    char *node = *(char **)iter.cursor;
    iter.cursor = (Node_1CDF88 **)(node + iter.stride);
    if (node != 0) {
        do {
            if (*(float *)(node + 0x14) <= g_2dded0) {
                char *vt = *(char **)(node + 0xEC);
                ((void (*)(void *))*(void **)(vt + 0x24))(node + *(short *)(vt + 0x20));
            }
            asm volatile("lqc2 vf1, 0x80(%0)" : : "r"(node));
            asm volatile("lqc2 vf3, 0x70(%0)" : : "r"(node));
            asm volatile("vmini.xyz vf3, vf3, vf1");
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
            asm volatile("vmini.xyz vf2, vf2, vf3");
            asm volatile("lqc2 vf4, 0x20(%0)" : : "r"(sp));
            asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(sp));
            asm volatile("lqc2 vf2, 0x80(%0)" : : "r"(node));
            asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(node));
            asm volatile("vmax.xyz vf1, vf1, vf2");
            asm volatile("vmax.xyz vf4, vf4, vf1");
            asm volatile("sqc2 vf4, 0x20(%0)" : : "r"(sp));
            node = *(char **)iter.cursor;
            iter.cursor = (Node_1CDF88 **)(node + iter.stride);
        } while (node != 0);
    }
    float margin = ((Obj_1CDF88 *)self)->margin;
    if (margin != 0.0f) {
        float *pad = (float *)(sp + 0x30);
        pad[0] = margin;
        pad[2] = margin;
        pad[1] = margin;
        asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(sp));
        asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf1, vf3");
        asm volatile("vsub.xyzw vf2, vf2, vf3");
        asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(sp));
        asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
    }
    if (*(int *)(self + 0xEC) != 0) {
        asm volatile("lqc2 vf3, 0x20(%0)" : : "r"(sp));
        asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(sp));
        asm volatile("qmtc2.ni %0, vf2" : : "r"(0x3F000000));
        asm volatile("vmulax.xyzw ACC, vf5, vf2x");
        asm volatile("vmaddx.xyzw vf4, vf3, vf2x");
        asm volatile("sqc2 vf2, 0x40(%0)" : : "r"(sp));
        asm volatile("vsub.xyzw vf1, vf4, vf3");
        asm volatile("vmul.xyz vf1, vf1, vf1");
        asm volatile("vaddw.x vf2, vf0, vf0w");
        asm volatile("vadday.x ACC, vf1, vf1y");
        asm volatile("vmaddz.x vf1, vf2, vf1z");
        asm volatile("sqc2 vf5, 0x170(%0)" : : "r"(self));
        asm volatile("vsqrt Q, vf1x");
        asm volatile("vwaitq");
        asm volatile("vaddq.x vf1, vf0, Q");
        asm volatile("sqc2 vf4, 0x30(%0)" : : "r"(sp));
        asm volatile("sqc2 vf3, 0x180(%0)" : : "r"(self));
        int vu_1;
        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
        *(int *)(self + 0x1A0) = vu_1;
        asm volatile("sqc2 vf4, 0x190(%0)" : : "r"(self));
        func_001F4B58(self);
    }
    g_2dd2fc = iter.saved;
}
