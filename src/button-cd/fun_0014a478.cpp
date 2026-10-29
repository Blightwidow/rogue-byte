typedef int QW __attribute__((mode(TI)));  /* a quadword in one 128-bit register */

extern "C" QW PosLoWorld(void *);
extern "C" int FFindSurfaceAlongUp(QW *, int, int, float, float);

int func_0014A478(char *arg0) {
    char *temp_a0;
    QW pos;

    temp_a0 = *(char **)(arg0 + 0x10);
    if (*(int *)(temp_a0 + 0x208) != 0) {
        return 0;
    }
    pos = PosLoWorld(temp_a0);
    return FFindSurfaceAlongUp(&pos, 1, 0, 100.0f, -250.0f) == 0;
}
