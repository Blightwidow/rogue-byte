extern "C" void UpdateRopeSimChain(char *, char *);
extern "C" void UpdateRopeSimFree(char *, char *);
extern "C" void func_001A5E80(char *, char *);
extern "C" void func_001E6340(char *self)
{
    char *rope = *(char **)(self + 0x17C);
    if (rope != 0) {
        int mode = *(int *)(rope + 0x4C);
        switch (mode) {
        case 0: case 3: UpdateRopeSimFree(*(char **)(self + 0x17C), self); break;
        case 1: case 2: UpdateRopeSimChain(rope, self); break;
        }
    } else {
        func_001A5E80(self, self);
    }
}
