extern "C" {
struct Mpeg_24C360 {
    char pad0[4]; int field4; int field8;
    char padC[0xC0 - 0xC]; int fieldC0;
    char padC4[0x128 - 0xC4]; int field128;
    char pad12C[0x130 - 0x12C]; int field130;
    char pad134[0x184 - 0x134]; int field184;
    char pad188[0x1CC - 0x188]; int field1CC;
    char pad1D0[0x1DC - 0x1D0]; int field1DC;
    char pad1E0[0x1EC - 0x1E0]; int field1EC;
};
struct MpegOwner_24C360 {
    char pad0[8]; int field8;
    char padC[0x40 - 0xC]; Mpeg_24C360 *mpeg;
};
void func_0024BC80(Mpeg_24C360 *, int, int);
void func_0024BF40(Mpeg_24C360 *, int, int, int);
void func_0024FA38(Mpeg_24C360 *, const char *, int);
int func_0024C360(MpegOwner_24C360 *owner) {
    Mpeg_24C360 *mpeg = owner->mpeg;
    int result = 0;
    if (mpeg->field4 != 0) {
        if (mpeg->field8 != 0) {
            int count = mpeg->field128;
            if (mpeg->field130 != 0) {
                func_0024FA38(mpeg, "the second field is missing", count);
            } else {
                if (mpeg->field184 == 3) {
                    func_0024BC80(mpeg, mpeg->field1CC, count - 1);
                } else {
                    func_0024BF40(mpeg, mpeg->field1DC, mpeg->field1EC, count - 1);
                }
            }
            result = 1;
            mpeg->field130 = 0;
            owner->field8 = mpeg->field128 - mpeg->fieldC0;
            mpeg->field4 = 0;
        }
    }
    return result;
}
}
