int func_00252148(void *, int);
void func_002542B8(void *);
void func_00253C80(char *self) {
    *(int *)(self + 0xFC) = 0;
    *(int *)(self + 0x864) = 1;
    *(int *)(self + 0x85C) = *(int *)(self + 0x860) + 1;
    func_00252148(self, 1);
    func_00252148(self, 5);
    func_00252148(self, 6);
    func_00252148(self, 1);
    func_00252148(self, 6);
    func_00252148(self, 6);
    *(int *)(self + 0x1B4) = func_00252148(self, 1);
    *(int *)(self + 0x1B8) = func_00252148(self, 1);
    func_002542B8(self);
}
