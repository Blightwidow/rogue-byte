typedef int s128 __attribute__((mode(TI)));
struct VT_144E68 { char pad[0x40]; short d40; short i40; void (*f44)(void *); };
struct Dst_144E68 { char p0[0xC]; VT_144E68 *vt; char p1[0x30]; int i40; char p2[0x20]; float f64; char p3[0x64]; int iCC; float fD0; };
struct Src_144E68 { char p0[0x10]; int h10; char p1[0x1C]; int i30; float f34; int i38; float f3C; s128 v40; };
extern "C" {
void GoalGotoPos_SetPos(Src_144E68 *, s128);
void func_001EEF70();
Dst_144E68 *func_00205438(int, int);
void func_00144E68(Src_144E68 *src) {
    func_001EEF70();
    Dst_144E68 *dst = func_00205438(src->h10, 0xA8);
    dst->i40 = src->i30;
    dst->f64 = src->f34;
    dst->iCC = src->i38;
    dst->fD0 = src->f3C;
    GoalGotoPos_SetPos(src, src->v40);
    dst->vt->f44((char *)dst + dst->vt->d40);
}
}
