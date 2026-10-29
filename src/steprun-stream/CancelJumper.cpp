extern "C" int FJumperDone(void *);
extern "C" void SetJumperState(void *, int);
extern "C" void ApplyAsegToHandle(int, int, int, void *, float, float);

void CancelJumper(char *arg0) {
    if (FJumperDone(arg0) == 0) {
        SetJumperState(arg0, 4);
        ApplyAsegToHandle(0, 0, 0, arg0 + 0x38, 0.0f, 1.0f);
    }
}
