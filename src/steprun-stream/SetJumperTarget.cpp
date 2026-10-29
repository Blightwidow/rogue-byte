typedef int s128 __attribute__((mode(TI)));
extern "C" {
s128 ConvertXfPos(int, int, s128);
void SetJumperTarget(char *arg0, s128 arg1) {
    int state = *(int *)(arg0 + 0x10);
    if (state == 0) {
        *(s128 *)(arg0 + 0x40) = arg1;
    } else if (state >= 0) {
        if (state < 3) {
            if (*(int *)(arg0 + 0x60) != 0) {
                char *target = *(char **)(arg0 + 0x68);
                *(s128 *)(target + 0x20) = ConvertXfPos(0, *(int *)(*(char **)(*(char **)(arg0 + 0x34) + 0x58) + 0xA0), arg1);
            }
        }
    }
}
}
