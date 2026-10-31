typedef int s32;
extern "C" {
struct Q_1F6788;
struct P_1F6788 { char pad0[0x14]; Q_1F6788 *owner; s32 key; char pad1[8]; P_1F6788 *next; };
struct Q_1F6788 { char pad[0x18]; s32 key; };
extern P_1F6788 *B_003E1218;
P_1F6788 *PasegaFindAlo(s32 arg0, s32 arg1) {
    P_1F6788 *p;
    s32 dead[2]; /* retail frame: 0x10 bytes, no stores */
    (void)dead;
    for (p = B_003E1218; p != 0; p = p->next) {
        if (p->key == arg0 && (arg1 == -1 || p->owner->key == arg1))
            return p;
    }
    return 0;
}
}
