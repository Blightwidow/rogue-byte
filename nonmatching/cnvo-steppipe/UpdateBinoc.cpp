typedef int QW __attribute__((mode(TI)));

extern "C" int FAsegaGone(int);
extern "C" void SetBinocState(char *, int);
extern "C" void SetStepRadTarget(char *, float);
extern "C" void UpdateBinocHud(char *);
extern "C" char B_002DDF40[];
extern "C" QW g_2a2dd0;

void UpdateBinoc(char *arg0)
{
    float var_f0;
    int temp_s1;
    int temp_a0;
    QW *pIdentity = &g_2a2dd0;
    char *pTable = B_002DDF40;
    int constOne = 1;
    int constTwo = 2;

    do {
        temp_s1 = *(int *)(arg0 + 4);
        if (temp_s1 == constOne) {
            *(QW *)(*(char **)arg0 + 0x190) = *pIdentity;
            if (*(int *)(arg0 + 0x20) == 0) {
                SetStepRadTarget(*(char **)arg0, *(float *)(pTable + 0x460));
                var_f0 = *(float *)(pTable + 0x470);
                *(float *)(arg0 + 0x3C) = var_f0;
                UpdateBinocHud(arg0 + 0x24);
            } else if (*(int *)(arg0 + 0x20) == temp_s1) {
                SetStepRadTarget(*(char **)arg0, *(float *)(pTable + 0x5C4));
                var_f0 = *(float *)(pTable + 0x5CC);
                *(float *)(arg0 + 0x3C) = var_f0;
                UpdateBinocHud(arg0 + 0x24);
            }
        } else if (temp_s1 < 2) {
            if (temp_s1 == 0) {
                *(QW *)(*(char **)arg0 + 0x190) = *pIdentity;
                temp_a0 = *(int *)(arg0 + 0x14);
                if (temp_a0 == 0 || FAsegaGone(temp_a0) != 0)
                    SetBinocState(arg0, 1);
            }
        } else if (temp_s1 == constTwo) {
            *(QW *)(*(char **)arg0 + 0x190) = *pIdentity;
            temp_a0 = *(int *)(arg0 + 0x14);
            if (temp_a0 == 0 || FAsegaGone(temp_a0) != 0)
                SetBinocState(arg0, -1);
        }
    } while (temp_s1 != *(int *)(arg0 + 4));
    if (*(int *)(arg0 + 0x20) != 0)
        return;
    {
        char *temp_v0_2 = *(char **)(*(char **)arg0 + 0x150);
        if (*(int *)(temp_v0_2 + 0x80) == 1) {
            *(float *)(temp_v0_2 + 0x20) = 0.0f;
            *(float *)(temp_v0_2 + 0x1C) = 0.0f;
            *(float *)(temp_v0_2 + 0x18) = 0.0f;
            *(float *)(temp_v0_2 + 0x14) = 0.0f;
            *(float *)(temp_v0_2 + 0x10) = 0.0f;
            *(float *)(temp_v0_2 + 0x2C) = 0.0f;
            *(float *)(temp_v0_2 + 0x28) = 0.0f;
            *(float *)(temp_v0_2 + 0x24) = 0.0f;
        }
    }
}
