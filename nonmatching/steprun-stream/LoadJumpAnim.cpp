typedef int s32;
extern "C" {
struct VT_20BD88 { char pad[0x18]; short delta; short unused; void (*fn)(char *, char *, int, char *, float, float); };
struct OBJ_20BD88 { VT_20BD88 *vt; };
char *PchnFindAseg(int, int, int, int);
float *PeaFindAsegLabel(int, int);
int PloFindSwObject_thunk(void *, int, int, int);
extern char B_003DD490;
void LoadJumpAnim(char *arg0, int arg1) {
    char sp[0x30] __attribute__((aligned(16)));
    if ((*(int *)(arg0 + 0x30) == 0) && ((*(int *)(arg0 + 4) != 0) || (*(int *)(arg0 + 4) = PloFindSwObject_thunk(&B_003DD490, 4, *(int *)arg0, arg1), (*(int *)(arg0 + 4) != 0)))) {
        float *label_a = PeaFindAsegLabel(*(int *)(arg0 + 4), 0x22);
        if (label_a != 0) {
            float *label_b = PeaFindAsegLabel(*(int *)(arg0 + 4), 0x23);
            if (label_b != 0) {
                float *label_c = PeaFindAsegLabel(*(int *)(arg0 + 4), 0x24);
                if (label_c != 0) {
                    float value_a = *label_a;
                    *(float *)(arg0 + 8) = value_a;
                    float value_b = *label_b;
                    *(float *)(arg0 + 0xC) = value_b;
                    float value_c = *label_c;
                    *(float *)(arg0 + 0x10) = value_c;
                    *(float *)(arg0 + 0x18) = value_c - value_b;
                    *(float *)(arg0 + 0x14) = value_c - value_a;
                    char *aseg = PchnFindAseg(*(int *)(arg0 + 4), arg1, 1, 1);
                    if (aseg != 0) {
                        OBJ_20BD88 *obj = *(OBJ_20BD88 **)(aseg + 4);
                        obj->vt->fn((char *)obj + obj->vt->delta, sp, 0, (char *)obj, *(float *)(arg0 + 8), 1.0f);
                        OBJ_20BD88 *obj2 = *(OBJ_20BD88 **)(aseg + 4);
                        obj2->vt->fn((char *)obj2 + obj2->vt->delta, sp + 0x10, 0, (char *)obj2, *(float *)(arg0 + 0x10), 1.0f);
                        asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                        asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(sp));
                        asm volatile("vsub.xyzw vf1, vf1, vf2");
                        float start = *(float *)(arg0 + 8);
                        asm volatile("vmul.xy vf1, vf1, vf1");
                        asm volatile("vaddy.x vf1, vf1, vf1y");
                        asm volatile("vsqrt Q, vf1x");
                        asm volatile("vwaitq");
                        asm volatile("vaddq.x vf1, vf0, Q");
                        s32 vu_1;
                        asm volatile("qmfc2.ni %0, vf1" : "=r"(vu_1));
                        OBJ_20BD88 *obj3 = *(OBJ_20BD88 **)(aseg + 4);
                        *(s32 *)(arg0 + 0x1C) = vu_1;
                        float half = (*(float *)(arg0 + 0x10) - start) * 0.5f;
                        obj3->vt->fn((char *)obj3 + obj3->vt->delta, sp + 0x20, 0, (char *)obj3, start + half, 1.0f);
                        char *tail = arg0 + 0x20;
                        *(int *)(arg0 + 0x20) = 0;
                        *(int *)(tail + 4) = 0;
                        *(float *)(tail + 8) = (*(float *)(sp + 8) - *(float *)(sp + 0x28)) / (half * half * 0.5f);
                    }
                    *(int *)(arg0 + 0x30) = 1;
                }
            }
        }
    }
}
}
