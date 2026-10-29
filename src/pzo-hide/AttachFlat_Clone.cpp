struct Packed8 { char bytes[8]; };
extern "C" {
void CloneXfm(char *);
void AttachFlat_Clone(char *arg0) {
    Packed8 saved = *(Packed8 *)(arg0 + 0x104);
    CloneXfm(arg0);
    *(Packed8 *)(arg0 + 0x104) = saved;
}
}
