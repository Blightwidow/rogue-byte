struct Obj_1FEA60 { virtual void method(); };
typedef void (Obj_1FEA60::*Pmf_1FEA60)();
extern "C" {
float GLimitLm__FP2LMf(void *, float);
void *memset(void *, int, unsigned);
void snd_SetMasterVolume(int, int);
extern const Pmf_1FEA60 RO_002A8298;
extern const Pmf_1FEA60 RO_002A82A0;
extern char g_2bbb60;
void SetSndbankVolumeFactor(char *arg0, int arg1, unsigned int arg2, float fparg0) {
    Pmf_1FEA60 pmf;
    if ((arg2 < 8U) && (arg1 >= 0) && (arg1 < 4)) {
        fparg0 = GLimitLm__FP2LMf(&g_2bbb60, fparg0);
        float *table = (float *)(arg0 + 0x13C);
        int column = arg1 * 4;
        int row = arg2 * 0x10;
        if (*(float *)((char *)table + (column + row)) != fparg0) {
            if (arg2 == 2) {
                memset(&pmf, 0, 8);
                if (fparg0 == 0.0f) {
                    pmf = RO_002A8298;
                } else if (*(float *)((char *)table + column + 0x20) == 0.0f) {
                    pmf = RO_002A82A0;
                }
                if (pmf) {
                    switch (arg1) {
                    case 0:
                        if (*(Obj_1FEA60 **)(arg0 + 0x228) != 0) {
                            (*(Obj_1FEA60 **)(arg0 + 0x228)->*pmf)();
                        }
                        break;
                    case 1: {
                        int i = 0;
                        if (*(int *)(arg0 + 0x204) > 0) {
                            Obj_1FEA60 **cursor = (Obj_1FEA60 **)(arg0 + 0x208);
                            do {
                                if (*cursor != 0) {
                                    ((*cursor)->*pmf)();
                                }
                                i += 1;
                                cursor += 1;
                            } while (i < *(int *)(arg0 + 0x204));
                        }
                        break;
                    }
                    case 2:
                        if (*(Obj_1FEA60 **)(arg0 + 0x200) != 0) {
                            (*(Obj_1FEA60 **)(arg0 + 0x200)->*pmf)();
                        }
                        break;
                    }
                }
            }
            int remaining = 7;
            float *cursor = table + arg1;
            *(float *)((char *)table + (column + row)) = fparg0;
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
