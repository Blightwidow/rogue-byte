// SPDX-License-Identifier: GPL-3.0-or-later
struct GIFS;
struct GlyphBrx {
    char pad0[2];
    unsigned short u;
    unsigned short v;
    unsigned short width;
};
struct CFontBrx {
    char pad0[8];
    int dxSpace;
    int lineHeight;
    float scaleX;
    float scaleY;
    char pad18[0x48 - 0x18];
    int depth;
    char pad4C[4];
    unsigned long tex0;
};
extern "C" {
void ListRGBAQ__4GIFSUif(GIFS *, unsigned int, float);
void ListUV__4GIFSii(GIFS *, int, int);
void ListXYZF__4GIFSiiii(GIFS *, int, int, int, int);
GlyphBrx *PglyffFromCh__8CFontBrxc(CFontBrx *, int);
float DxDrawCh__8CFontBrxcffUiP4GIFS(CFontBrx *font, int character, unsigned int color, GIFS *gifs, float x, float y)
{
    GlyphBrx *glyph = PglyffFromCh__8CFontBrxc(font, character & 0xFF);
    if (glyph != 0) {
        int textureHeight = 1 << (int)((font->tex0 >> 0x1E) & 0xF);
        float right = x + (float)glyph->width * font->scaleX;
        float bottom = y + (float)font->lineHeight * font->scaleY;
        if ((right >= 0.0f) && (x <= 640.0f) && (bottom >= 0.0f) && (y <= 492.80002f)) {
            ListRGBAQ__4GIFSUif(gifs, (color & 0xFFFFFF) | ((((color >> 0x18) + 1) & 0x1FE) << 0x17), 0.0f);
            ListUV__4GIFSii(gifs, glyph->u * 0x10, (textureHeight - glyph->v) * 0x10);
            ListXYZF__4GIFSiiii(gifs, (int)(((x * 0.8f) + 1792.0f) * 16.0f), (int)(((y * 0.45454547f) + 1936.0f) * 16.0f), font->depth, 0);
            ListUV__4GIFSii(gifs, (glyph->u + glyph->width) * 0x10, (textureHeight - (glyph->v + font->lineHeight)) * 0x10);
            ListXYZF__4GIFSiiii(gifs, (int)(((right * 0.8f) + 1792.0f) * 16.0f), (int)(((bottom * 0.45454547f) + 1936.0f) * 16.0f), font->depth, 0);
        }
        return (float)(glyph->width + 1) * font->scaleX;
    }
    return (float)font->dxSpace * font->scaleX;
}
}
