// SPDX-License-Identifier: GPL-3.0-or-later
typedef int s32;
extern "C" {
void ResetSlotheap(void *arg0);
extern s32 B_002DD280;
extern s32 B_002DD284;
extern s32 B_002DD288;
extern s32 B_002DD28C;
extern char B_004520A8;

void ResetPairHeap(void) {
    B_002DD280 = 0;
    B_002DD288 = 0;
    B_002DD28C = 0;
    B_002DD284 = 0;
    ResetSlotheap(&B_004520A8);
}

}
