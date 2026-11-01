extern "C" {
int FIsPoSwFocusBase(int);
int ZapFInvulnerable(char *, int);
extern int B_003D4A54;
int FInvulnerableJt(char *jt, int arg1) {
    if (*(int *)(jt + 0xF20) == 1) return 1;
    if (*(int *)(jt + 0x2DC) == 0x15) return 1;
    if (B_003D4A54 != 0 && FIsPoSwFocusBase(B_003D4A54)) return 1;
    return ZapFInvulnerable(jt + 0xDF0, arg1);
}
}
