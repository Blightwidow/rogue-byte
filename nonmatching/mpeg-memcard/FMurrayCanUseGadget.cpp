struct MURRAY { char pad[0x13D0]; int state; };
extern "C" int bevy_player_p15_binoc_active(MURRAY *m);
extern "C" int FJmpAllowsGadget(void *p, int gadget);
extern "C" int FAttachAllowsGadget(void *p, int gadget);
extern "C" int func_0019EEF0(void *p, int gadget);
extern "C" int FIsBasicDerivedFrom(void *p, int cls);
extern "C" int FActiveCplcy(void *);
extern "C" char B_002DE2E0[];
extern int g_2dfbc0;

extern "C" int FMurrayCanUseGadget(MURRAY *pmurray, int gadget)
{
    if (bevy_player_p15_binoc_active(pmurray) != 0)
        return 0;
    char *base = (char *)pmurray;
    int allowed;
    switch (pmurray->state) {
    case 0: case 1: case 9: case 10:
        goto second;
    case 2:
        allowed = FJmpAllowsGadget(base + 0x2c0, gadget);
        break;
    case 5:
        goto five;
    case 0xd:
        allowed = FAttachAllowsGadget(base + 0x4c0, gadget);
        break;
    case 0x14:
        allowed = func_0019EEF0(base + 0xf50, gadget);
        break;
    default:
        return 0;
    }
    if (allowed != 0)
        goto second;
    return 0;
five:
    if (gadget == 3)
        goto one;
    if (gadget != 0x13)
        return 0;
    {
        int derived = FIsBasicDerivedFrom(*(void **)(*(char **)(base + 0x13f0) + 0x180), 0x38);
        if (derived != 0)
            goto one;
        return 0;
    }
second:
    switch (gadget) {
    case 1: case 2: case 0xf: case 0x10: case 0x14: case 0x15:
        goto one;
    case 3: {
        int result = 0;
        if (*(int *)(base + 0x12f0) != 0) {
            if ((g_2dfbc0 & 2) != 0)
                result = FActiveCplcy(B_002DE2E0) == 0;
        }
        return result;
    }
    case 0x16: {
        int jmps = *(int *)(base + 0x2c4);
        int result = 0;
        if (jmps != 0) {
            if (jmps != 0xb)
                result = jmps != -1;
        }
        return result;
    }
    default:
        return 0;
    }
one:
    return 1;
}
