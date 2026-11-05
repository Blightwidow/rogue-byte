// SPDX-License-Identifier: GPL-3.0-or-later
struct JT {
    char pad1[0x298]; int inv;
    char pad2[0x2DC - 0x29C]; int jmps;
    char pad3[0x4C8 - 0x2E0]; int attachKind;
    char pad4[0xDF4 - 0x4CC]; int zapState;
};
struct ZAP { JT *pjt; int jzs; char pad[0x88]; int flash; };
struct SW;
extern SW B_003DD490;
extern int g_2e1e00;
extern "C" int FSwHandsOff(SW *);
int ZapFInvulnerable(ZAP *pzap, int grftak)
{
    if (pzap->pjt->inv != 0)
        goto one;
    if (grftak == 0x2000 || grftak == 0x4000) {
        switch (pzap->pjt->zapState) {
        case 3:
        case 5:
        case 10:
        case 0xb:
            goto one;
        case -1:
            switch (pzap->pjt->attachKind) {
            case 1:
            case 2:
            case 5:
            case 6:
            case 9:
                goto zero;
            case -1: {
                int jmps = pzap->pjt->jmps;
                if (jmps == -1)
                    goto zero;
                if (jmps < -1)
                    goto zero;
                if (jmps < 0x12) {
                    if (jmps < 8)
                        goto zero;
                    if (grftak == 0x4000) {
                        goto one;
                    }
                    goto zero;
                }
                goto zero;
            }
            default:
                goto one;
            }
        default:
            goto zero;
        }
    }
    if (pzap->jzs != -1)
        goto one;
    if (pzap->flash == 1)
        goto one;
    if ((g_2e1e00 & 1) != 0)
        goto one;
    if (FSwHandsOff(&B_003DD490)) {
        goto one;
    }
    goto zero;
one:
    return 1;
zero:
    return 0;
}
