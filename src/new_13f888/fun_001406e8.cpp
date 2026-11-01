extern "C" {
void GoalStack_Clear(char *);
void SetPoPlayable(char *, int);
void func_001F82B8(char *, int, int);
void func_001406E8(char *self, int mode) {
    SetPoPlayable(self, mode);
    func_001F82B8(self, mode == 1 ? 0 : -1, 0);
    if (mode == 1) {
        GoalStack_Clear(self + 0x26C);
    }
}
}
