// 0x120990 RefOpIsNull
extern "C" void* func_00120990(void* a0, int unused_a1, void* a2) {
    unsigned int v1 = *(unsigned int*)a2;
    *(unsigned int*)a0 = 0x17;
    *(unsigned int*)((unsigned char*)a0 + 4) = (v1 < 1u);
    return a0;
}
