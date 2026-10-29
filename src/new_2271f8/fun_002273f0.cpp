extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
typedef int QW __attribute__((mode(TI)));
QW ConvertAloPos(void *, void *, QW);
int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int, QW);
void func_00227440(void *, int);

void func_002273F0(void *arg0, QW arg1) {
    QW point = ConvertAloPos(0, arg0, arg1);
    int inside = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(*(void **)((char *)arg0 + 0xF4), 0x7FFFFFFF, point);

    func_00227440(arg0, inside != 0);
}
}
