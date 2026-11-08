typedef unsigned long u64;
extern "C" void func_001A6178(char *);
extern "C" void AddAloToRenderTree(char *);
extern "C" int FFindDlEntry(void *, void *);
extern "C" void AppendDlEntry(void *, void *);
extern "C" char B_003E11AC;
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));

void func_001F3EA8(char *self)
{
    VECTOR vector;
    func_001A6178(self);
    if ((*(u64 *)(self + 0x148) & (1UL << 35)) != 0) {
        int holderValue = *(int *)(self + 0x40);
        int isUntagged = !(holderValue & 1);
        if (isUntagged)
            holderValue = *(int *)holderValue;
        if ((holderValue & 8) != 0)
            AddAloToRenderTree(self);
    }
    char *node = *(char **)(self + 0x64);
    while (node != *(char **)(self + 0x70)) {
        char *typeInfo = *(char **)(node + 0xC);
        ((void (*)(char *))*(void **)(typeInfo + 0xBC))(node + *(short *)(typeInfo + 0xB8));
        node = *(char **)(node + 0x24);
    }
    char *entry = *(char **)(self + 0xEC);
    if (entry != 0 && *(char **)(entry + 0x60) == self) {
        char *list = &B_003E11AC;
        if (FFindDlEntry(list, entry) == 0)
            AppendDlEntry(list, *(char **)(self + 0xEC));
        char *typeInfo = *(char **)(self + 0xC);
        ((void (*)(char *))*(void **)(typeInfo + 0x18C))(self + *(short *)(typeInfo + 0x188));
    }
}
