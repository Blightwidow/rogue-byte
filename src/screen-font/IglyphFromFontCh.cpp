typedef int s32; typedef unsigned char u8;
extern "C" {
struct F_215A50 { char pad[0x20]; s32 count; s32 *table; };
s32 IglyphFromFontCh(F_215A50 *font, u8 ch) {
    s32 hi = font->count - 1;
    s32 lo = 0;
    while (lo <= hi) {
        s32 mid = (hi + lo) / 2;
        s32 diff = ch - font->table[mid];
        if (diff == 0)
            return mid + 1;
        if (diff > 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return 0;
}
}
