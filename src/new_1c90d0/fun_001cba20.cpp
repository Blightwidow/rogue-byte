struct Bytes8 { char bytes[8]; };
extern "C" {
void CloneCrv(char *);
void func_001CBA20(char *self) {
    Bytes8 saved = *(Bytes8 *)(self + 0x1b4);
    CloneCrv(self);
    *(Bytes8 *)(self + 0x1b4) = saved;
}
}
