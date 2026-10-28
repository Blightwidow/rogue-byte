struct JT { char pad[0x12F0]; int flag; };
struct JMP { JT *pjt; int jtbs; char pad[0x1C - 8]; int jmps; char pad2[0x2C - 0x20]; int pending; };
extern "C" int FActiveCplcy(void *);
extern "C" char B_002DE2E0[];
extern int g_2dfbc0;
extern "C" int FJmpAllowsGadget(JMP *pjmp, int gadget)
{
    int ok;
    int value;
    switch (gadget) {
    case 22:
        if (pjmp->jtbs >= 0x11)
            goto kindcheck;
        ok = pjmp->jtbs < 0xF;
        goto test;
    case 12:
        ok = pjmp->pending;
    test:
        if (ok)
            goto kindcheck;
        return 0;
    case 3: {
        value = 0;
        if (pjmp->jmps == 0x11) {
            if (pjmp->pjt->flag != 0) {
                if ((g_2dfbc0 & 2) != 0)
                    value = FActiveCplcy(B_002DE2E0) == 0;
            }
        }
        return value;
    }
    case 2:
    case 5:
    case 27:
    kindcheck:
        break;
    default:
        return 0;
    }
    value = pjmp->jmps;
    if (value == 6)
        return 0;
    if (value <= 5)
        return 1;
    if (value < 0x17) {
        if (!(value < 9))
            return 0;
    }
    value = 1;
    return value;
}
