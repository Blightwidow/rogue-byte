extern "C" {
extern char B_003DD490;
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
void func_001F1900(int);
void UpdateAllGuardLightStates(void) {
    int found[0x20] __attribute__((aligned(16)));
    int count = CploFindSwObjectsByClass(&B_003DD490, 0x505, 0x38, 0, 0x20, found);
    for (int index = 0; index < count; index++) {
        func_001F1900(found[index]);
    }
}
}
