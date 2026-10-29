// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
typedef float f32;
typedef int QW __attribute__((mode(TI)));

extern "C" {
void func_001A58D0(void *arg0, s32 arg1, s32 arg2, f32 fparg3);
QW PosLoWorld(void *arg0);
void ExplodeGadgetBurst(void *arg0, s32 arg1, s32 arg2, QW arg3, f32 fparg0);

void DetonateGadgetObj(void *arg0, f32 fparg0) {
    QW position;

    func_001A58D0(arg0, 0, 1, fparg0);
    position = PosLoWorld(arg0);
    ExplodeGadgetBurst(arg0, *(s32 *)((char *)arg0 + 0x174), *(s32 *)((char *)arg0 + 0x178), position, fparg0);
}
}
