struct Bytes8 { char bytes[8]; };
extern "C" {
void CSo_Clone(char *);
void CloneHbsk__FP4HBSKT0(char *self) {
    Bytes8 saved = *(Bytes8 *)(self + 0x174);
    CSo_Clone(self);
    *(Bytes8 *)(self + 0x174) = saved;
}
}
