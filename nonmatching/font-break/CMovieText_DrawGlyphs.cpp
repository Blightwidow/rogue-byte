typedef int QW __attribute__((mode(TI)));
struct Text_216750 {
    char pad0[8]; void *font; char pad0C[0x14]; QW row20; QW row30; char pad40[0x20]; int hasOutline; char pad64[0x10];
    float roomX; float roomY; float scaleX; float scaleA; float scaleB; float dxScale; int centerY; int centerX; int endPadding;
};
struct Dest_216750 { int pad0; float pad4; float depth; char pad0C[4]; QW row10; QW row20; };
struct Ctx_216750 { char pad0[0x20]; float x; float y; };
struct Glyph_216750 { char pad0[4]; int dma; };
struct Slot_216750 { int tag; float value; int address; int zero; };
extern "C" {
int CMovieText_ChNext(Text_216750 *);
void CMovieText_Reset(Text_216750 *, int);
float DxFromFontCh(void *, int);
void EmitGlyphDma(Glyph_216750 *, Ctx_216750 *, Dest_216750 *, int);
Slot_216750 *OnGameLoad__FP4GAME();
Glyph_216750 *PglyphFromFontCh(void *, int);
void *memset(void *, int, unsigned);
extern float g_2c40a8, g_2c40ac, g_2c40b0, g_2c40b4;
extern char g_2dea28[];
void CMovieText_DrawGlyphs(Text_216750 *text, Ctx_216750 *ctx, Dest_216750 *dest) {
    float lineWidth[32];
    int cursorAtStart = *(int *)(g_2dea28 + 0xC);
    int line = 0;
    float startX = ctx->x;
    *(int *)dest = 0;
    float lineHeight = text->scaleB * text->scaleA * 0.45454547f;
    memset(lineWidth, 0, 0x80);
    CMovieText_Reset(text, 0);
    int first;
    while ((first = CMovieText_ChNext(text)) != 0) {
        if (first == 10) {
            line += 1;
        } else {
            lineWidth[line] += DxFromFontCh(text->font, first) * text->dxScale;
        }
    }
    if (text->centerY != 0) {
        float room = (text->roomY * text->scaleA * 0.45454547f) - ((float)(line + 1) * lineHeight);
        if (text->centerY == 2) {
            ctx->y = ctx->y + room;
        } else {
            ctx->y = ctx->y + room * 0.5f;
        }
    }
    CMovieText_Reset(text, 0);
    int flags = 3;
    int firstOfLine = 1;
    int emitted = 0;
    int limit = 2;
    float *widthPointer = lineWidth;
    int ch;
    while ((ch = CMovieText_ChNext(text)) != 0) {
        if (text->hasOutline != 0) {
            limit = emitted + 3;
            flags |= 2;
        }
        if (ch == 10) {
            firstOfLine = 1;
            widthPointer += 1;
            ctx->y = ctx->y + lineHeight;
        } else {
            if (firstOfLine != 0) {
                if (text->centerX != 0) {
                    float scale = text->scaleX;
                    float width = *widthPointer * scale * 0.8f;
                    float room = text->roomX * scale * 0.8f;
                    float shift;
                    if (text->centerX == 2) {
                        shift = room - width;
                    } else {
                        shift = (room - width) * 0.5f;
                    }
                    ctx->x = startX + shift;
                } else {
                    ctx->x = startX;
                }
                firstOfLine = 0;
            }
            Glyph_216750 *glyph = PglyphFromFontCh(text->font, ch);
            if (glyph != 0) {
                float x = ctx->x;
                int visible = 0;
                if (g_2c40a8 <= x && x <= g_2c40ac) {
                    float y = ctx->y;
                    if (g_2c40b0 <= y && y <= g_2c40b4) {
                        visible = 1;
                    }
                }
                if (glyph->dma != 0 && visible != 0) {
                    if (flags & 2) {
                        dest->row10 = text->row20;
                        dest->row20 = text->row30;
                    }
                    emitted += 1;
                    EmitGlyphDma(glyph, ctx, dest, flags);
                    flags = emitted >= limit ? 0 : flags;
                }
                ctx->x = ctx->x + (DxFromFontCh(text->font, ch) * text->dxScale * text->scaleX * 0.8f);
            }
        }
    }
    int cursor = *(int *)(g_2dea28 + 0xC);
    if (cursor & 0xF) {
        do {
            *(int *)(g_2dea28 + 0xC) = cursor;
            cursor = *(int *)(g_2dea28 + 0xC) + 4;
            *(int *)cursor = 0;
        } while (cursor & 0xF);
    }
    **(int **)(g_2dea28 + 0xC) = 0x60000000;
    *(int *)(g_2dea28 + 0xC) = *(int *)(g_2dea28 + 0xC) + 0x10;
    Slot_216750 *slot = OnGameLoad__FP4GAME();
    slot->tag = 0x15;
    slot->value = dest->depth + (float)(text->endPadding << 18);
    slot->zero = 0;
    slot->address = cursorAtStart & 0x0FFFFFFF;
}
}
