#include "jt.h"
extern "C" {
int FIsPoSwFocusBase(int);
int ZapFInvulnerable(char *, int);
extern int B_003D4A54;
int FInvulnerableJt(JT *jt, int arg1) {
    if (jt->binocPhase == 1) return 1;
    if (jt->jmpState == 0x15) return 1;
    if (B_003D4A54 != 0 && FIsPoSwFocusBase(B_003D4A54)) return 1;
    return ZapFInvulnerable((char *)jt + 0xDF0, arg1);
}
}
