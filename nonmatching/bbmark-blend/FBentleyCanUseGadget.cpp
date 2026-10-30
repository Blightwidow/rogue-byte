struct SLOT_136870 { int pad0; int object; int active; };
struct TARGET_136870 { char pad0[0x15C]; int gadget; };
struct BENTLEY_136870 {
    char pad0[0x12F0];
    int hasBinoc;
    char pad12f4[0x13D0 - 0x12F4 - 0];
};
extern "C" {
int FActiveCplcy(void *);
int FAttachAllowsGadget(void *, int);
int FGadgetObjActive(int);
int FJmpAllowsGadget(void *, int);
int PleaseFindBest(int, int);
SLOT_136870 *PslotBentleyGadget(void *, int);
int bevy_player_p15_binoc_active();
int func_0019EEF0(void *, int);
extern char B_002DE2E0;
extern int g_2dfbc0;
int FBentleyCanUseGadget(char *self, int gadget) {
    int result;
    int allowed;
    unsigned state;
    SLOT_136870 *slot;
    if (*(long *)(self + 0x1818) != 0) {
        return 0;
    }
    if (bevy_player_p15_binoc_active() != 0) {
        return 0;
    }
    state = *(unsigned *)(self + 0x13D0);
    switch (state) {
    case 2:
        if (FJmpAllowsGadget(self + 0x2C0, gadget) == 0) {
            return 0;
        }
        break;
    case 3:
        if (FAttachAllowsGadget(self + 0x4C0, gadget) == 0) {
            return 0;
        }
        break;
    case 13:
        if (func_0019EEF0(self + 0xF50, gadget) == 0) {
            return 0;
        }
        break;
    case 12:
        if ((unsigned)(*(int *)(self + 0x11B4) - 4) < 3U) {
            switch (gadget) {
            case 4:
            case 7:
            case 9:
            case 11:
            case 13:
                if (((TARGET_136870 *)*(char **)(self + 0x11C0))->gadget != gadget) {
                    return 0;
                }
                { result = 1; goto done; }
            }
        }
        { result = 0; goto done; }
    case 0:
    case 1:
    case 5:
    case 7:
        break;
    default:
        return 0;
    }
    switch (gadget - 1) {
    case 3:
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
        slot = PslotBentleyGadget(self, gadget);
        if (slot->active == 0) {
            if (slot->object == 0) {
                { result = 0; goto done; }
            }
            if (PleaseFindBest(slot->object, 2) == 0) {
                return 0;
            }
            return 1;
        }
        if (FGadgetObjActive(slot->active) != 0) {
            return 1;
        }
        return 0;
    case 2:
        allowed = 0;
        if (*(int *)(self + 0x12F0) != 0) {
            if (!(g_2dfbc0 & 2)) {
                { result = 0; goto done; }
            }
            allowed = FActiveCplcy(&B_002DE2E0) == 0;
        }
        { result = allowed; goto done; }
    case 0:
    case 1:
    case 7:
    case 9:
    case 11:
    case 13:
        return 1;
    }
    { result = 0; goto done; }
done:
    return result;
}
}
