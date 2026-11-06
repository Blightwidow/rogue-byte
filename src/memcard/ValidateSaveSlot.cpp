extern "C" {
extern int B_003E0EA8;
int ValidateSaveData(int *);
int ValidateSaveSlot(void *save, void *slot) {
    ValidateSaveData(&B_003E0EA8);
    return 0;
}
}
