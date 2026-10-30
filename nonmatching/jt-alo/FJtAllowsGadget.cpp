extern "C" {
int FActiveCplcy(void *);
int FAttachAllowsGadget(char *, int);
int FCanLease(int);
int FGadgetObjActive(int);
int FJmpAllowsGadget(char *, int);
int PleaseFindBest(int, int);
int bevy_player_p15_binoc_active();
int *func_0018D6F8(char *, int);
int func_0019EEF0(char *, int);
extern char B_002DE2E0[];
extern float B_FLT_002DDEEC;
extern const float D_FLT_002BF3EC;
extern const float D_FLT_002BF3F0;
extern int g_2dfbc0;
int FJtAllowsGadget(char *jt, int gadget) {
    int allowed;
    if (bevy_player_p15_binoc_active() != 0) {
        return 0;
    }
    if (gadget == 0x1D || gadget == 0x2A) {
        if (*(unsigned *)(jt + 0x18C8) != 4) {
            float current = B_FLT_002DDEEC;
            if (current == 1.0f) {
                return 1;
            }
            float threshold;
            int equal = 1;
            if (gadget == 0x1D) {
                threshold = D_FLT_002BF3EC;
            } else {
                threshold = D_FLT_002BF3F0;
            }
            if (current != threshold) {
                equal = 0;
            }
            return equal;
        }
        return 0;
    }
    switch (*(unsigned *)(jt + 0x18C8)) {
    case 2:
        allowed = FJmpAllowsGadget(jt + 0x2C0, gadget);
        goto check;
    case 7:
        allowed = FAttachAllowsGadget(jt + 0x4C0, gadget);
        goto check;
    case 8:
        allowed = func_0019EEF0(jt + 0xF50, gadget);
        goto check;
    case 3:
        if (gadget != 3) {
            return 0;
        }
        goto dispatch;
    case 0:
    case 1:
    case 5:
    case 10:
    case 12:
        goto dispatch;
    case 23:
        if ((unsigned)(*(int *)(jt + 0x11B4) - 4) < 3U) {
            if (gadget < 0x27) {
                if (gadget < 0x25 && gadget != 0x1A) {
                    return 0;
                }
            } else if (gadget != 0x29) {
                return 0;
            }
            if (*(int *)(*(char **)(jt + 0x11C0) + 0x15C) != gadget) {
                return 0;
            }
            return 1;
        }
        return 0;
    default:
        return 0;
    }
check:
    if (allowed == 0) {
        return 0;
    }
dispatch:
    switch (gadget - 1) {
    case 22: {
        int lease = *(int *)(jt + 0x2010);
        if (lease == 0) {
            return 0;
        }
        return FCanLease(lease) != 0;
    }
    case 23:
        return *(unsigned *)(jt + 0x18C8) == 5;
    case 26:
        return *(unsigned *)(jt + 0x18C8) == 2;
    case 25:
    case 36:
    case 37:
    case 40: {
        int *entry = func_0018D6F8(jt, gadget);
        if (entry[2] != 0) {
            if (FGadgetObjActive(entry[2]) != 0) {
                return 1;
            }
            return 0;
        }
        if (entry[1] == 0) {
            return 0;
        }
        if (PleaseFindBest(entry[1], 2) != 0) {
            return 1;
        }
        return 0;
    }
    case 2: {
        int result = 0;
        if (*(int *)(jt + 0x12F0) != 0) {
            if ((g_2dfbc0 & 2) == 0) {
                return 0;
            }
            result = FActiveCplcy(B_002DE2E0) == 0;
        }
        return result;
    }
    case 39: {
        if (*(int *)(jt + 0x1D30) != 0) {
            return 0;
        }
        if (*(int *)(jt + 0x10EC) == 4) {
            return 0;
        }
        if (*(int *)(jt + 0x18D8) != -1) {
            return 0;
        }
        int state = *(int *)(jt + 0x18C8);
        if (state == 10) {
            return 1;
        }
        if (state < 11) {
            if (state < 2) {
                if (state >= 0) {
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        if (state == 12) {
            return 1;
        }
        return 0;
    }
    case 0:
    case 1:
    case 24:
    case 29:
    case 30:
    case 32:
    case 33:
    case 34:
    case 38:
        return 1;
    default:
        return 0;
    }
}
}
