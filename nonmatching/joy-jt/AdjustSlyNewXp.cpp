extern "C" void AdjustStepNewXp(char *, char *, int);
extern "C" void AdjustJtZapNewXp(char *, char *, int);
extern "C" void func_001374E0(char *, char *, int);
extern "C" void func_0019E9C8(char *, char *, int);
extern "C" float g_2dded0;
extern "C" float D_002BF298;
extern "C" float D_002BF29C;

void AdjustSlyNewXp(char *arg0, char *arg1, int arg2)
{
    float var_f0;
    AdjustStepNewXp(arg0, arg1, arg2);
    int temp_v0 = *(int *)(arg0 + 0x18C8);
    switch (temp_v0) {
    case 8:
        func_0019E9C8(arg0 + 0xF50, arg1, arg2);
        return;
    case 7:
        if (*(int *)(arg1 + 0x9C) == 0xE && *(int *)(arg0 + 0x4C8) == 3
                && *(int *)(*(char **)(arg0 + 0x4D4) + 0x1BC) != 0) {
            *(int *)(arg1 + 0x98) = 0;
            if (*(int *)(arg0 + 0x4CC) != 0) {
                asm volatile(
                    ".set noat\n\t"
                    "lqc2 $vf1, 0x80(%0)\n\t"
                    "vmul.xy $vf1, $vf1, $vf1\n\t"
                    "vaddy.x $vf1, $vf1, $vf1y\n\t"
                    "lwc1 $f1, 0x88(%0)\n\t"
                    ".word 0x4A0103BD\n\t"
                    "vwaitq\n\t"
                    ".word 0x4B000060\n\t"
                    "lui $1, 0x3F00\n\t"
                    "mtc1 $1, $f2\n\t"
                    ".word 0x48220800\n\t"
                    "lui $1, 0x3FC0\n\t"
                    "mtc1 $1, $f3\n\t"
                    "mtc1 $2, $f0\n\t"
                    "nop\n\t"
                    "div.s $f0, $f0, $f1\n\t"
                    "add.s $f0, $f0, $f2\n\t"
                    "c.lt.s $f0, $f2\n\t"
                    "nop\n\t"
                    "bc1f 1f\n\t"
                    "nop\n\t"
                    "b 2f\n\t"
                    "mov.s $f0, $f2\n\t"
                    "1:\n\t"
                    "c.lt.s $f3, $f0\n\t"
                    "nop\n\t"
                    "bc1tl 2f\n\t"
                    "mov.s $f0, $f3\n\t"
                    "2:\n\t"
                    "b 3f\n\t"
                    "swc1 $f0, 0x94(%0)\n\t"
                    "3:\n\t"
                    ".set at\n\t"
                    : : "r"(arg1)
                    : "$f0", "$f1", "$f2", "$f3", "$2", "$1", "memory");
            } else {
                *(float *)(arg1 + 0x94) = 0.0f;
                return;
            }
        } else {
            return;
        }
        break;
    case 4:
        AdjustJtZapNewXp(arg0 + 0xDF0, arg1, arg2);
        return;
    case 6:
        func_001374E0(arg0 + 0x1FF0, arg1, arg2);
        return;
    case 24:
        *(int *)(arg1 + 0x98) = 0;
        *(float *)(arg1 + 0x94) = 0.0f;
        return;
    case 5:
        if (((unsigned int)(*(int *)(arg0 + 0x18D0) - 8) < 2U)
                && (g_2dded0 - *(float *)(arg0 + 0x18D4) < D_002BF298)) {
            var_f0 = D_002BF29C;
            *(float *)(arg1 + 0x94) = var_f0;
        }
        break;
    }
}
