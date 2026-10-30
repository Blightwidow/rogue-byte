extern "C" {
extern int D_002BF670;
struct Tunnel_194118 { char pad0[0xFC]; int f_fc, f_100, pad104, f_108, f_10c, f_110; void *f_114; char pad118[8]; int f_120, f_124, f_128, pad12c, f_130; char pad134[12]; int f_140; char pad144[0x20]; int f_164, f_168, f_16c; };
struct JT_194118 { char pad[0x68]; Tunnel_194118 *tunnel; };
void ResetJtDynamicTunnel__FP2JT(JT_194118 *self) {
    Tunnel_194118 *t = self->tunnel;
    t->f_140 = 0;
    t->f_100 = 0;
    t->f_fc = 0;
    t->f_164 = 5;
    t->f_108 = 0;
    t->f_114 = &D_002BF670;
    t->f_10c = 0;
    t->f_128 = 3;
    t->f_110 = 1;
    t->f_120 = 0;
    t->f_124 = 0;
    t->f_16c = 0;
    t->f_130 = 0;
    t->f_168 = 1;
}
}
