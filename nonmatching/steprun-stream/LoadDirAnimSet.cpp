typedef signed char s8; typedef int s32; typedef unsigned int u32;
extern "C" {
struct VT_20C7E0 { char pad[0x18]; short delta; short unused; void (*fn)(char *, char *, int, char *, float, float); };
struct OBJ_20C7E0 { VT_20C7E0 *vt; };
char *PchnFindAseg(char *, int, int, int);
char *PloFindSwObject_thunk(void *, int, char *, int);
extern char B_003DD490;
void LoadDirAnimSet(char *arg0, int arg1) {
    char sp[0x30] __attribute__((aligned(16)));
    if (*(int *)(arg0 + 0xC0) == 0) {
        char *entry = arg0;
        do {
            char *found = PloFindSwObject_thunk(&B_003DD490, 4, *(char **)entry, arg1);
            *(char **)entry = found;
            if (found != 0) {
                char *aseg = PchnFindAseg(found, arg1, 1, 1);
                OBJ_20C7E0 *obj = *(OBJ_20C7E0 **)(aseg + 4);
                OBJ_20C7E0 *obj2 = *(OBJ_20C7E0 **)(aseg + 4);
                obj->vt->fn((char *)obj + obj->vt->delta, sp, 0, (char *)obj, 0.0f, 1.0f);
                obj2->vt->fn((char *)obj2 + obj2->vt->delta, sp + 0x10, 0, (char *)obj2, *(float *)(found + 0x74), 1.0f);
                asm volatile("qmtc2.ni %0, vf1" : : "r"(*(int *)(found + 0x74)));
                asm volatile("lqc2 vf2, (%0)" : : "r"(sp));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("sqc2 vf1, 0x20(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf3, vf3, vf2");
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf3, Q");
                asm volatile("vmul.xyz vf2, vf1, vf1");
                asm volatile("vaddw.x vf4, vf0, vf0w");
                asm volatile("vadday.x ACC, vf2, vf2y");
                asm volatile("vmaddz.x vf2, vf4, vf2z");
                asm volatile("sqc2 vf1, 0x10(%0)" : : "r"(entry));
                asm volatile("vsqrt Q, vf2x");
                asm volatile("vwaitq");
                asm volatile("vaddq.x vf2, vf0, Q");
                s32 vu_1;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
                *(s32 *)(entry + 0x20) = vu_1;
            }
            entry += 0x30;
        } while ((u32)entry < (u32)(arg0 + 0xC0));
        *(int *)(arg0 + 0xC0) = 1;
    }
}
}
