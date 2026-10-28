struct MURRAY { char pad0[0x4CC]; int unk4CC; char pad4D0[0xBB0]; float unk1080; char pad1084[0x60]; int unk10E4; char pad10E8[0x2E8]; int state; };
extern "C" const float g_2dded0;
extern "C" void GetJtCpdefi(MURRAY *, unsigned *);
extern "C" void func_00220388(void *, unsigned *);
extern "C" void func_0019EA00(void *, unsigned *);

void GetMurrayCpdefi(MURRAY *murray, unsigned *flags)
{
    if (murray->state != 0) {
        if (murray->state != 0x10) {
            if (murray->unk4CC != 0)
                murray->unk1080 = g_2dded0;
        }
    }
    GetJtCpdefi(murray, flags);
    switch (murray->state) {
    case 11:
        if (murray->unk10E4 != 4) break;
    case 3:
    case 9:
    case 12:
        *flags |= 1;
        break;
    case 15:
        func_00220388((char *)murray + 0x1910, flags);
        break;
    case 20:
        func_0019EA00((char *)murray + 0xF50, flags);
        break;
    }
}
