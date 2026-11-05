// SPDX-License-Identifier: GPL-3.0-or-later
// new() factory: a 0x460-byte object with a vptr at +0xC; its constructor zeroes two words and runs an empty
// per-element loop over 32 members.
struct CPrimary1110D8 {
    int unk0x0;
    int unk0x4;
    int unk0x8;
    CPrimary1110D8()
    {
        unk0x0 = 0;
        unk0x4 = 0;
    }
    virtual void Virtual0();
};
struct CObject1110D8 : CPrimary1110D8 {
    char pad[0x450];
    CObject1110D8()
    {
        for (int index = 31; index != -1; index--) {
        }
    }
};
void *func_001110D8(void)
{
    return new CObject1110D8;
}
