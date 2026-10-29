struct Packed8 { char bytes[8]; };
extern "C" {
void CloneXfm(char *);
void func_0021D498(char *arg0) {
    Packed8 saved = *(Packed8 *)(arg0 + 0xE0);
    CloneXfm(arg0);
    *(Packed8 *)(arg0 + 0xE0) = saved;
}
}
