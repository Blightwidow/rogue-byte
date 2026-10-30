extern "C" {
struct VT_20B868 { char pad[0x18]; short delta; short unused; void (*fn)(char *, char *, int, char *, float, float); };
struct OBJ_20B868 { VT_20B868 *vt; };
struct Out_20B868 { int first; char *second; char pad[8]; };
void BindAsegChn(char *, int, char *, Out_20B868 *);
void EnsureAsegBlendDynamic(int, int, int, char *);
extern int D_002C3DC0[2];
extern int D_002C3DC8[2];
void FillBlAmrsg__FiiPviiP3OID(int, int, char *, int, int, int *);
char *PchnFindAseg(char *, int, int, int);
void ReblendAsegbl(char *);
void PostStepLoadRun__FP4STEPP5BLRUNPP6ASEGBL(char *arg0) {
    char sp[0x30] __attribute__((aligned(16)));
    Out_20B868 bound __attribute__((aligned(16)));
    char dead[0x10] __attribute__((aligned(16)));
    char *temp_s0 = arg0 + 0x10;
    if (*(int *)(arg0 + 0x14) != 0) {
        unsigned int index = 0;
        FillBlAmrsg__FiiPviiP3OID(0x40, 2, temp_s0, 0x20, 2, D_002C3DC0);
        FillBlAmrsg__FiiPviiP3OID(0x40, 2, temp_s0, 0x30, 2, D_002C3DC8);
        char *entry = temp_s0;
        do {
            char *seg = *(char **)(entry + 4);
            if (seg != 0) {
                char *aseg = PchnFindAseg(seg, *(int *)arg0, 1, 1);
                OBJ_20B868 *obj = *(OBJ_20B868 **)(aseg + 4);
                obj->vt->fn((char *)obj + obj->vt->delta, sp, 0, (char *)obj, 0.0f, 1.0f);
                OBJ_20B868 *obj2 = *(OBJ_20B868 **)(aseg + 4);
                obj2->vt->fn((char *)obj2 + obj2->vt->delta, sp + 0x10, 0, (char *)obj2, *(float *)(seg + 0x74), 1.0f);
                asm volatile("qmtc2.ni %0, vf2" : : "r"(*(int *)(seg + 0x74)));
                asm volatile("lqc2 vf3, 0x10(%0)" : : "r"(sp));
                asm volatile("lqc2 vf1, (%0)" : : "r"(sp));
                asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf3, vf3, vf1");
                asm volatile("vdiv Q, vf0w, vf2x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf2, vf3, Q");
                asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(entry));
            }
            index += 1;
            entry += 0x40;
        } while (index < 2U);
        EnsureAsegBlendDynamic(*(int *)arg0, 0x40, 2, temp_s0);
        int channel = 0;
        if (*(int *)(*(char **)(arg0 + 4) + 0x5C) > 0) {
            do {
                char *record = *(char **)(*(char **)(arg0 + 4) + 0x60) + channel * 8;
                char *first;
                char *second;
                if (*(int *)record >= 0) {
                    first = *(char **)(record + 4);
                    second = 0;
                } else {
                    first = 0;
                    second = *(char **)(record + 4);
                }
                BindAsegChn(*(char **)(arg0 + 4), *(int *)arg0, record, &bound);
                switch (*(int *)(bound.second + 0x9C)) {
                case 16:
                case 18:
                case 20:
                    if (first != 0) {
                        *(int *)(first + 8) = *(int *)(*(char **)(arg0 + 4) + 0xD0) + 0xC;
                    }
                    if (second != 0) {
                        *(int *)(second + 8) = *(int *)(*(char **)(arg0 + 4) + 0xD0) + 0xC;
                    }
                    break;
                case 17:
                case 19:
                case 21:
                    break;
                default:
                    if (first != 0) {
                        *(int *)(first + 8) = 0;
                    }
                    if (second != 0) {
                        *(int *)(second + 8) = 0;
                    }
                    break;
                }
                channel += 1;
            } while (channel < *(int *)(*(char **)(arg0 + 4) + 0x5C));
        }
        ReblendAsegbl(*(char **)(arg0 + 4));
    }
}
}
