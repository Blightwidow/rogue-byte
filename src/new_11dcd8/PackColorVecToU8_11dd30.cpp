// SPDX-License-Identifier: GPL-3.0-or-later
typedef unsigned char u8;
extern "C" {
struct Color { float red; float green; float blue; };
void PackColorVecToU8_11dd30(Color *color, int alpha, u8 *out) {
    out[0] = (int)(color->red * 255.0f + 0.5f);
    out[1] = (int)(color->green * 255.0f + 0.5f);
    out[2] = (int)(color->blue * 255.0f + 0.5f);
    out[3] = alpha;
}
}
