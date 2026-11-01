typedef int s32;
extern "C" {
struct Q_1F67E0;
struct P_1F67E0 { char pad0[0x1C - 0]; P_1F67E0 *next; char pad1[4]; Q_1F67E0 *owner; s32 key; };
struct Q_1F67E0 { char pad[0x18]; s32 key; };
extern P_1F67E0 *B_003E126C;
P_1F67E0 *PsmaFindAlo(s32 arg0, s32 arg1) {
    P_1F67E0 *p;
    s32 dead[2]; /* retail frame: 0x10 bytes, no stores */
    (void)dead;
    for (p = B_003E126C; p != 0; p = p->next) {
        if (p->key == arg0 && (arg1 == -1 || p->owner->key == arg1))
            return p;
    }
    return 0;
}
}
