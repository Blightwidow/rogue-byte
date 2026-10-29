extern "C" int FGoalAnimDone(void *);
extern "C" int func_001C1FA0(void *, float, void *);

int func_0017EAE8(char *arg0) {
    if ((*(int *)(*(char **)(arg0 + 0x10) + 0xFE8) & 1) != 0) {
        if (FGoalAnimDone(*(void **)(arg0 + 0x18)) == 0) {
            return 0;
        }
    }
    return func_001C1FA0(arg0 + 0x30, 25.0f, *(void **)(arg0 + 0x10));
}
