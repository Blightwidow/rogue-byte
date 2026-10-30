extern "C" {
char *PjsgeAllocJsg(void *, int);
void func_001E0E78(void *self, int first, int unused, int third, float amountA, float amountB) {
    char *record = PjsgeAllocJsg(self, 0x2B);
    *(int *)(record + 0x10) = first;
    *(float *)(record + 0x14) = amountA;
    *(float *)(record + 0x18) = amountB;
    *(int *)(record + 0x1C) = third;
}
}
