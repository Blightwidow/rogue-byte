extern "C" {
struct Mpeg_24C420 {
    char pad0[0x108]; int field108;
    char pad10C[0x160 - 0x10C]; int field160;
    char pad164[0x184 - 0x164]; int field184;
    char pad188[0x1C8 - 0x188]; int field1C8;
    char pad1CC[0x1D4 - 0x1CC]; int field1D4; int field1D8;
    char pad1DC[0x1E4 - 0x1DC]; int field1E4; int field1E8;
    char pad1EC[0x1F4 - 0x1EC]; int field1F4;
};
void func_0024BC80(Mpeg_24C420 *, int, int);
void func_0024BF40(Mpeg_24C420 *, int, int, int);
void func_0024C420(Mpeg_24C420 *mpeg, int count, int decode) {
    if (decode != 0) {
        int source;
        int other;
        if (mpeg->field184 == 3) {
            if (mpeg->field160 == 3) {
                source = mpeg->field1D4;
            } else {
                source = mpeg->field1C8;
            }
            func_0024BC80(mpeg, source, count - 1);
        } else {
            if (mpeg->field160 == 3) {
                source = mpeg->field1E4;
                other = mpeg->field1F4;
            } else {
                source = mpeg->field1D8;
                other = mpeg->field1E8;
            }
            func_0024BF40(mpeg, source, other, count - 1);
        }
    }
    if (mpeg->field108 == 1) {
        mpeg->field108 = 2;
    }
}
}
