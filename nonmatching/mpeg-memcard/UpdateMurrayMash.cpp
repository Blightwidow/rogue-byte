extern "C" char B_003DD490[];
extern "C" char D_002C0908[];
extern "C" char D_002C0948[];
extern "C" const float RO_002C0900;
extern "C" float g_2dded4;

extern "C" int PpoSwFocusBase(void *);
extern "C" int FSwHandsOff(void *);
extern "C" int GetSmaCur(int);
extern "C" int GetSmaGoal(int);
extern "C" int FButtonPressedWithin(int, int, float);
extern "C" void SetSmaGoal__FP3SMA3OID(int, int);

void UpdateMurrayMash(char *arg0)
{
    float temp_f2;
    int temp_a0;
    int temp_a0_2;
    int var_a0;
    int var_s1;
    int var_v0;
    char *var_v1;

    if (PpoSwFocusBase(B_003DD490) == (int)arg0 && FSwHandsOff(B_003DD490) == 0) {
        var_s1 = GetSmaCur(*(int *)(arg0 + 0x1034));
        if (var_s1 == GetSmaGoal(*(int *)(arg0 + 0x1034)) && var_s1 < 0x1D0 && var_s1 >= 0x1CB) {
            *(float *)(arg0 + 0x1524) = *(float *)(arg0 + 0x1524) - g_2dded4;
            if (FButtonPressedWithin(*(int *)(arg0 + 0x150), 0xF0, 0.0f) != 0) {
                *(int *)(arg0 + 0x152C) = *(int *)(arg0 + 0x152C) - 1;
                *(float *)(arg0 + 0x1528) = *(float *)(arg0 + 0x1524);
            }
            temp_f2 = *(float *)(arg0 + 0x1524);
            if (temp_f2 <= 0.0f) {
                temp_a0 = *(int *)(arg0 + 0x1534);
                if (*(int *)(arg0 + 0x152C) <= 0) {
                    var_a0 = temp_a0 * 0x14;
                    var_v0 = (var_s1 - 0x1CB) * 4;
                    var_v1 = D_002C0908;
                } else {
                    var_a0 = temp_a0 * 0x14;
                    var_v0 = (var_s1 - 0x1CB) * 4;
                    var_v1 = D_002C0948;
                }
                var_s1 = *(int *)((char *)(var_v0 + var_a0) + (int)var_v1);
            } else if (RO_002C0900 < *(float *)(arg0 + 0x1528) - temp_f2) {
                var_s1 = 0x1CA;
            }
            temp_a0_2 = *(int *)(arg0 + 0x1530);
            if (temp_a0_2 != 0)
                SetSmaGoal__FP3SMA3OID(temp_a0_2, var_s1);
            SetSmaGoal__FP3SMA3OID(*(int *)(arg0 + 0x1034), var_s1);
        }
    }
}
