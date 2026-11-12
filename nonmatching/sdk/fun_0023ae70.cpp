extern "C" {
void func_0023B170(int, int);
int isceSifSetDma(int *, int);
int sceSifSetDma(int *);
extern int B_0044EDE0;
int func_0023AE70(int argument0, int argument1, unsigned char *argument2, int argument3, int argument4, int argument5, int argument6) {
    int dma[8];
    int entryCount = 0;
    if ((unsigned int)(argument3 - 0x10) >= 0x61) {
        return 0;
    }
    if (argument6 > 0) {
        int header = argument2[0];
        *(int *)(argument2 + 4) = argument5;
        *(int *)argument2 = header | (argument6 << 8);
        dma[0] = argument4;
        dma[1] = argument5;
        dma[2] = argument6;
        dma[3] = 0;
        entryCount = 1;
        if (argument1 & 4) {
            func_0023B170(argument4, argument6);
        }
    } else {
        *(int *)(argument2 + 4) = 0;
        *(int *)argument2 = argument2[0];
    }
    dma[entryCount * 4 + 0] = (int)argument2;
    dma[entryCount * 4 + 1] = B_0044EDE0;
    dma[entryCount * 4 + 2] = argument3;
    dma[entryCount * 4 + 3] = 0x44;
    *(int *)(argument2 + 8) = argument0;
    argument2[0] = (unsigned char)argument3;
    entryCount++;
    func_0023B170((int)argument2, argument3);
    if (argument1 & 1) {
        return isceSifSetDma(dma, entryCount);
    }
    return sceSifSetDma(dma);
}
}
