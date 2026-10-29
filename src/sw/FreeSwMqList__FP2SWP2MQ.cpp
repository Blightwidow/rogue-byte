// SPDX-License-Identifier: GPL-3.0-or-later
typedef signed char s8; typedef int s32; typedef unsigned short u16;
extern "C" {
void FreeSlotheapPv(s32, s8 *);

void FreeSwMqList__FP2SWP2MQ(s32 arg0, s8 *arg1) {
    s8 *cursor = arg1;

    if (cursor != 0) {
        do {
            s8 *next = *(s8 **)(cursor + 0xAC);
            FreeSlotheapPv(arg0 + 0x3D40, cursor);
            cursor = next;
        } while (cursor != 0);
    }
}

}
