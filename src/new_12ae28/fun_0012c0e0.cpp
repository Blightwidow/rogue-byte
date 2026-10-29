extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
typedef float f32;

s32 func_0012C0E0(char *arg0, f32 fparg0) {
    f32 *elements;
    s32 count;
    s32 index;

    index = 1;
    count = *(s32 *)(arg0 + 4) - 1;
    if (index < count) {
        elements = *(f32 **)(arg0 + 8);
        while (index < count) {
            if (fparg0 < elements[index]) {
                break;
            }
            index += 1;
        }
    }
    return index;
}

}
