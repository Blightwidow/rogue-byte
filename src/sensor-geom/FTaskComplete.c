typedef struct { int tagk; int n; int pad[2]; } CRef_164030;
extern void CRef_Destruct(CRef_164030 *);
extern void RefGetGameSaveValue(CRef_164030 *, void *, void *);
extern char B_003D4A60;

int FTaskComplete(char *self) {
    CRef_164030 ref;
    if (*(int *)(self + 0x54) == -1) {
        if (*(int *)(self + 0xD8) != 0) {
            int value;
            RefGetGameSaveValue(&ref, self + 0xD8, &B_003D4A60);
            value = ref.n;
            CRef_Destruct(&ref);
            return value;
        }
    }
    return *(int *)(self + 0x54) >= 2;
}
