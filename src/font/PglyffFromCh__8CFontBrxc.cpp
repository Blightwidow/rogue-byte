struct Glyph_15F8A8 { unsigned short code; unsigned short pad[3]; };
struct FontBrx_15F8A8 { char pad[0x138]; int count; Glyph_15F8A8 *glyphs; };
extern "C" {
extern unsigned short D_002BE338[];
Glyph_15F8A8 *PglyffFromCh__8CFontBrxc(FontBrx_15F8A8 *self, int ch) {
    int code = D_002BE338[ch & 0xFF];
    int low = 0;
    int high = self->count - 1;
    while (low <= high) {
        int mid = (high + low) / 2;
        Glyph_15F8A8 *glyph = (Glyph_15F8A8 *)(mid * 8 + (long)self->glyphs);
        int diff = code - glyph->code;
        if (diff == 0) return glyph;
        if (diff > 0) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}
}
