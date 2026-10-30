typedef long s64;
extern "C" {
struct PMF_1FEA60 { short delta; short index; union { int fn; short vtoffset; } u; };
float GLimitLm__FP2LMf(void *, float);
void *memset(void *, int, unsigned);
void snd_SetMasterVolume(int, int);
extern PMF_1FEA60 RO_002A8298;
extern PMF_1FEA60 RO_002A82A0;
extern char g_2bbb60;
static void CallPmf_1FEA60(char *object, PMF_1FEA60 pmf) {
    s64 entry;
    int target;
    short delta;
    if (pmf.index >= 0) {
        entry = *(s64 *)(*(int *)(object + pmf.u.vtoffset) + pmf.index * 8 - 8);
        target = (int)(entry >> 32);
        delta = (short)entry + pmf.delta;
    } else {
        target = pmf.u.fn;
        delta = pmf.delta;
    }
    ((void (*)(char *))target)(object + delta);
}
void SetSndbankVolumeFactor(char *arg0, int arg1, unsigned int arg2, float fparg0) {
    PMF_1FEA60 pmf;
    if ((arg2 < 8U) && (arg1 >= 0) && (arg1 < 4)) {
        float limit = GLimitLm__FP2LMf(&g_2bbb60, fparg0);
        float *table = (float *)(arg0 + 0x13C);
        int column = arg1 * 4;
        int row = arg2 * 0x10;
        if (*(float *)((char *)table + column + row) != limit) {
            if (arg2 == 2) {
                memset(&pmf, 0, 8);
                if (limit == 0.0f) {
                    pmf = RO_002A8298;
                } else if (*(float *)((char *)table + column + 0x20) == 0.0f) {
                    pmf = RO_002A82A0;
                }
                if (pmf.index != 0) {
                    switch (arg1) {
                    case 0:
                        if (*(char **)(arg0 + 0x228) != 0) {
                            CallPmf_1FEA60(*(char **)(arg0 + 0x228), pmf);
                        }
                        break;
                    case 1: {
                        int i = 0;
                        if (*(int *)(arg0 + 0x204) > 0) {
                            char **cursor = (char **)(arg0 + 0x208);
                            do {
                                if (*cursor != 0) {
                                    CallPmf_1FEA60(*cursor, pmf);
                                }
                                i += 1;
                                cursor += 1;
                            } while (i < *(int *)(arg0 + 0x204));
                        }
                        break;
                    }
                    case 2:
                        if (*(char **)(arg0 + 0x200) != 0) {
                            CallPmf_1FEA60(*(char **)(arg0 + 0x200), pmf);
                        }
                        break;
                    }
                }
            }
            int remaining = 7;
            float *cursor = (float *)((char *)table + column);
            *(float *)((char *)table + column + row) = limit;
            float product = 1.0f;
            do {
                float factor = *cursor;
                remaining -= 1;
                cursor += 4;
                product *= factor;
            } while (remaining >= 0);
            float *slot = (float *)(arg0 + 0x1C0 + column);
            int scaled = (int)(product * 1024.0f);
            if ((int)(*slot * 1024.0f) != scaled) {
                *slot = product;
                snd_SetMasterVolume(arg1, scaled);
            }
        }
    }
}
}
