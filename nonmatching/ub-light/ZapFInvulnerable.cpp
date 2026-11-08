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
// Retail: the jmps test is gcc's balanced decision tree for a switch with case -1 and the GNU case range 8 ... 17
// (== -1, < -1, < 0x12, < 8), so the source writes that switch. Every return 0 / return 1 goes through one shared
// label: plain returns let jump.c turn the branches into xori/sltu/movz (score 25). NEAR 6: in the 8 ... 17 case retail
// loads 0x4000 into $v1 and fills the beq delay slot with $v0 = 1 from the target; ours takes $v0 for the constant
// and fills the slot from the fall-through (v0 = 0), so the tail differs by two instructions.
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
            case -1:
                switch (pzap->pjt->jmps) {
                case -1:
                    goto zero;
                case 8 ... 17:
                    if (grftak == 0x4000)
                        goto one;
                    goto zero;
                default:
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
