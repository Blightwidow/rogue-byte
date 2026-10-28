struct JT { char pad[0x12F0]; int flag; };
struct ATTACH { JT *pjt; int pad; int kind; };
extern "C" int FActiveCplcy(void *);
extern "C" char B_002DE2E0[];
extern int g_2dfbc0;
extern "C" int FAttachAllowsGadget(ATTACH *pattach, int gadget)
{
    if (gadget == 3) {
        switch (pattach->kind) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 0xd:
            {
                int allowed = 0;
                if (pattach->pjt->flag != 0) {
                    if ((g_2dfbc0 & 2) != 0)
                        allowed = FActiveCplcy(B_002DE2E0) == 0;
                }
                return allowed;
            }
        default:
            return 0;
        }
    }
    switch (pattach->kind) {
    case 1:
    case 8:
    case 0xb:
    case 0xc:
        return 0;
    case 3:
    case 4:
        {
            int allowed = 0;
            if ((unsigned)(gadget - 1) < 2 || gadget == 0x1f)
                allowed = 1;
            return allowed;
        }
    default:
        return 1;
    }
}
