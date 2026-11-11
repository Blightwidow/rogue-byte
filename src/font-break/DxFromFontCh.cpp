#include "types.h"
extern "C" {
typedef struct GLYPH {
    char pad0[0x40];
} GLYPH;

typedef struct FONT {
    char pad0[0x14];
    GLYPH *field_0x14;
    char pad1[4];
    f32 *field_0x1C;
} FONT;

s32 IglyphFromFontCh(FONT *, s32);

f32 DxFromFontCh(FONT *arg0, s32 arg1) {
    f32 result;
    s32 temp_v0;

    temp_v0 = IglyphFromFontCh(arg0, arg1 & 0xFF);
    if (temp_v0 != 0) {
        result = arg0->field_0x1C[temp_v0 - 1];
    } else {
        result = 0.0f;
    }
    return result;
}

}
