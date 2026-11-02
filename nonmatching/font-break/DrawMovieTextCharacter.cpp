// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Ctx_216BC8 { QW row[3]; };
struct Matrix_216BC8 { float scale; int pad4[3]; float x; };
struct Char_216BC8 {
    char pad0[8]; int field8; char padC[8]; int kind; int id; char pad1C[4];
    float lineHeight; float width; float height;
};
struct MT_216BC8 { char *str; char pad4[0x9C]; };
struct Hud_216BC8 { char pad0[0x10]; int state; float start; char pad18[4]; float limit; };
struct Rgba_216BC8 { char c[4]; };
struct Text8_216BC8 { long v; };
struct Game_216BC8 { char pad0[0x3BE8]; void *font; };
struct Formatter_216BC8 { int id; void (*fn)(char *, int, int); int arg; };
extern "C" {
extern Game_216BC8 B_003DD490;
extern Formatter_216BC8 B_003E1C88[];
extern const Text8_216BC8 RO_002A8B80;
extern char RO_002A8B88[];
extern Hud_216BC8 B_003DA0C0;
extern char B_004435F0[];
extern Rgba_216BC8 B_004435F4;
extern float g_2dded0;
extern float D_002C40B8;
char *PchzStringFromId(void *, int);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
void func_00215BA8(MT_216BC8 *, char *, Char_216BC8 *, Ctx_216BC8);
int CMovieText_ClineWrap(MT_216BC8 *);
void func_00227820(char *, MT_216BC8 *);
void CMovieText_Reset(MT_216BC8 *, char *);
int CMovieText_ChNext(MT_216BC8 *);
void CMovieText_SetBaseColor(MT_216BC8 *, Rgba_216BC8 *);
float CMovieText_Dx(MT_216BC8 *);
void CMovieText_DrawAffine(MT_216BC8 *, Matrix_216BC8 *, Ctx_216BC8 *);
float GModPositive__Fff(float, float);
void SetHudLabelState(Hud_216BC8 *, int);
}
static inline float GMax(float a, float b) { return a > b ? a : b; }
extern "C" void DrawMovieTextCharacter(Char_216BC8 *ch, Matrix_216BC8 *mat, Ctx_216BC8 *ctx)
{
    char str[0x400];
    MT_216BC8 text;
    if (B_003DD490.font == 0) return;
    str[0] = 0;
    if (ch->kind == 1) {
        unsigned index;
        for (index = 0; index < 0x6C; index++) {
            if (B_003E1C88[index].id == ch->id) break;
        }
        if (index >= 0x6C)
            *(Text8_216BC8 *)str = RO_002A8B80;
        else
            B_003E1C88[index].fn(str, B_003E1C88[index].arg, ch->field8);
    } else if (ch->kind == 0) {
        strcpy(str, PchzStringFromId(&B_003DD490, ch->id));
    }
    if (ch->kind == 1) {
        if (ch->id == 0x2EF) {
            func_00215BA8(&text, str, ch, *ctx);
            CMovieText_ClineWrap(&text);
            func_00227820(B_004435F0, &text);
            CMovieText_Reset(&text, 0);
            int lines = 1;
            int c;
            while ((c = CMovieText_ChNext(&text)) != 0) {
                if (c == '\n') lines++;
            }
            int maxLines = (int)(ch->height / ch->lineHeight);
            unsigned char *p = (unsigned char *)text.str;
            while (maxLines < lines && *p) {
                while (*p && *p != '\n') p++;
                lines--;
                if (*p) p++;
            }
            CMovieText_Reset(&text, (char *)p);
            Rgba_216BC8 color = B_004435F4;
            CMovieText_SetBaseColor(&text, &color);
            CMovieText_DrawAffine(&text, mat, ctx);
            return;
        }
        if (ch->id == 0x2F1 && B_003DA0C0.state == 2) {
            char marquee[0x810];
            func_00215BA8(&text, str, ch, *ctx);
            strcpy(marquee, RO_002A8B88);
            CMovieText_Reset(&text, marquee);
            float scale = mat->scale;
            float gap = CMovieText_Dx(&text) * scale;
            strcat(marquee, str);
            CMovieText_Reset(&text, marquee);
            float span = CMovieText_Dx(&text) * scale;
            strcat(marquee, RO_002A8B88);
            strcat(marquee, str);
            strcat(marquee, RO_002A8B88);
            float elapsed = g_2dded0 - B_003DA0C0.start;
            if (elapsed < D_002C40B8) {
                ((float *)ctx)[0xB] *= elapsed / D_002C40B8;
            } else {
                elapsed -= D_002C40B8;
                float period = span * 0.01f;
                float phase = GModPositive__Fff(elapsed, period);
                if (0.0f <= B_003DA0C0.limit) {
                    float over = span - ch->width * scale;
                    float end = (span + GMax(over, 0.0f) + gap) * 0.01f;
                    end = GMax(end, B_003DA0C0.limit);
                    if (end <= elapsed) SetHudLabelState(&B_003DA0C0, 3);
                }
                mat->x -= phase / period * span;
            }
            CMovieText_DrawAffine(&text, mat, ctx);
            return;
        }
    }
    func_00215BA8(&text, str, ch, *ctx);
    CMovieText_ClineWrap(&text);
    CMovieText_DrawAffine(&text, mat, ctx);
}
