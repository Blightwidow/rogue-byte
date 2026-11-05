// SPDX-License-Identifier: GPL-3.0-or-later
struct SO2 {
    char pad0[0x40];
    unsigned p40;
    char pad1[0x104];
    unsigned long grfso;
    char pad2[0x154 - 0x150];
    int cid;
    float s158, s15c;
    char pad3[0x178 - 0x160];
    int f178;
    char pad4[0x184 - 0x17C];
    int f184;
};
extern "C" void InitSo(SO2 *);
extern "C" void func_00229EF0(SO2 *so)
{
    InitSo(so);
    so->cid = 0x32;
    so->s158 = 300.0f;
    so->s15c = 500.0f;
    so->f178 = -1;
    so->f184 = -1;
    unsigned p = so->p40;
    if ((p ^ 1) & 1)
        *(unsigned *)p |= 0xA;
    else
        so->p40 = p | 0xA;
    so->grfso &= (~0UL ^ (1UL << 35));
}
