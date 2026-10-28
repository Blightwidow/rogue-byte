extern "C" void func_002046F0(char *, int);
int FFaceSlyAimTarget(char *self)
{
    int target = *(int *)(self + 0x18C0);
    if (target) {
        func_002046F0(self, target);
        return 1;
    }
    return 0;
}
