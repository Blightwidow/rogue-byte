// 0x1441A0 GetJtPower
extern "C" int GetJtPower(void *a0) {
    int *v0 = *(int **)((char *)a0 + 0x12FC);
    if (v0 == 0) {
        return *(int *)((char *)a0 + 0x1300);
    }
    return *v0;
}