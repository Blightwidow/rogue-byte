typedef int s32; typedef unsigned long u64;
extern "C" {
struct Q_2022D8 { char pad[0x28]; u64 flags; };
struct P_2022D8 { char pad[0x28]; u64 flags; char pad1[0xD0]; Q_2022D8 *other; };
struct O_2022D8 { char pad[0x30]; s32 count; P_2022D8 *items[1]; };
s32 bevy_ui_binoc_recon_2022d8(O_2022D8 *arg0) {
    if (*(s32 *)((char *)arg0 + 0xB8) != 0)
        return 1;
    for (s32 i = 0; i < arg0->count; i++) {
        P_2022D8 *p = arg0->items[i];
        if ((s32)(p->flags >> 60) & 1) {
            Q_2022D8 *q = p->other;
            if (q == 0)
                return 1;
            if ((s32)(q->flags >> 60) & 1) {
            } else {
                return 1;
            }
        }
    }
    return 0;
}
}
