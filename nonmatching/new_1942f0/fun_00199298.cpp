extern "C" void FreeSwMqList__FP2SWP2MQ(void *, void *);
extern "C" char B_003DD490[];

void func_00199298(char *arg0)
{
    char *temp_a0;
    char *temp_s4;
    char *temp_v1;
    char *temp_v1_2;
    char *temp_a1;
    char *var_s0;
    char *var_s5;
    char **var_s1;
    char **var_s2;
    int temp_s6;
    int var_v0;
    int constOne = 1;
    int kindMain = 0x11;
    int kindBlock = 0xB;

    int kindCurrent = *(int *)(arg0 + 0x1C);
    if (kindCurrent != kindMain)
        return;
    temp_a0 = *(char **)(*(char **)(*(char **)(arg0 + 0xC8) + 4) + 0xEC);
    var_s5 = 0;
    if (temp_a0 != 0) {
        temp_s4 = *(char **)(temp_a0 + 0x60);
        temp_v1 = *(char **)(temp_s4 + 0xC);
        temp_s6 = ((int (*)(void *))(*(void **)(temp_v1 + 0x1F4)))(temp_s4 + *(short *)(temp_v1 + 0x1F0));
        var_s1 = *(char ***)(*(char **)(*(char **)arg0 + 0xEC) + 0x64);
        if (var_s1 != 0) {
            do {
                var_s0 = (char *)var_s1[0];
                var_s2 = var_s1;
                if (var_s0 != 0) {
                    var_v0 = *(int *)(var_s0 + 0x9C);
loop_5:
                    if (var_v0 == kindBlock) {
                        var_s2 = (char **)(var_s0 + 0xAC);
                    } else {
                        temp_a1 = *(char **)(var_s0 + ((constOne - (*(char **)arg0 != *(char **)(var_s0 + 8))) << 6) + 8);
                        if (temp_s6 != 0) {
                            temp_v1_2 = *(char **)(temp_a1 + 0xC);
                            if (((int (*)(void *, void *))(*(void **)(temp_v1_2 + 0x1F4)))(temp_a1 + *(short *)(temp_v1_2 + 0x1F0), temp_a1) == 0) {
                                var_s2 = (char **)(var_s0 + 0xAC);
                            } else {
                                goto block_14;
                            }
                        } else if (temp_a1 != temp_s4) {
                            var_s2 = (char **)(var_s0 + 0xAC);
                        } else {
block_14:
                            *var_s2 = *(char **)(var_s0 + 0xAC);
                            *(char **)(var_s0 + 0xAC) = var_s5;
                            var_s5 = var_s0;
                        }
                    }
                    var_s0 = (char *)*var_s2;
                    if (var_s0 != 0) {
                        var_v0 = *(int *)(var_s0 + 0x9C);
                        goto loop_5;
                    }
                }
                ((void **)var_s1)[2] = var_s1[0];
                var_s1 = (char **)var_s1[1];
            } while (var_s1 != 0);
        }
        FreeSwMqList__FP2SWP2MQ(B_003DD490, var_s5);
    }
}
