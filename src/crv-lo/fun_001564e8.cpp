// SPDX-License-Identifier: GPL-3.0-or-later
struct Bytes8 {
    char bytes[8];
};
struct CLoSub1564E8 {
    char pad0[0x40];
    int flags;
    char pad44[0x54 - 0x44];
    float unk0x54;
    Bytes8 unk0x58;
    float unk0x60;
};
extern "C" {
void InitLo(void *);
extern float D_002BDCD0;
extern Bytes8 D_002BDCD8;
void func_001564E8(CLoSub1564E8 *self)
{
    InitLo(self);
    self->unk0x54 = D_002BDCD0;
    self->unk0x58 = D_002BDCD8;
    self->unk0x60 = 0.25f;
    self->flags |= 0x40;
}
}
