#include "sly2.h"
struct B8 { char b[6]; };
struct Text { char data[0xA0]; };
struct Icon { int grfbtn; unsigned char chGlyph; char pad[3]; float xIcons; float yIcons; };
struct Beat { float tBeat; int grfbtnKind; char pad8[8]; float x; float y; float z; float w; int fHit; char pad24[0x10]; };
struct Frame {
    Text unknown;
    Text cursor;
    float boxX;
    float boxY;
    char boxPad[0x18];
    char glyph[16];
    Text bright;
    Text dim;
    float dyCursor;
};
extern "C" {
extern const B8 RO_STR_002A5018;
extern float D_FLT_002BDB50;
extern float D_FLT_002BDB54;
extern float D_FLT_002BDB58;
extern float D_FLT_002BDB5C;
extern char D_STR_002BDB60[];
extern char D_STR_002BDB68[];
extern Icon D_002BDB70[4];
extern float D_FLT_002BDBB0;
extern QW D_002BDBC0;
extern QW D_002BDBD0;
extern float g_2dded4;
extern char B_003DD040;
void func_001A5ED8(void *);
float MarkClockTickRealOnly__FP5CLOCK(void *);
void func_00215AC0(float, Text *, const char *);
float CMovieText_Dx(Text *);
void CMovieText_Draw(Text *, void *, int);
void CTextBox_SetPos(void *, float, float);
void CTextBox_SetSize(void *, float, float);
void CTextBox_SetTextColor(void *, unsigned *);
void CTextBox_SetHorizontalJust(void *, int);
void CTextBox_SetVerticalJust(void *, int);
void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, int);
void DrawRhythmHud(char *prhythm)
{
    Frame f;
    func_001A5ED8(prhythm);
    float tMusic = MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
    int state = *(int *)(prhythm + 0x50);
    if (state < 3) {
        if (state > 0) {
            if (*(int *)(prhythm + 0x60) != 0) {
                func_00215AC0(D_FLT_002BDB58, &f.unknown, D_STR_002BDB60);
                func_00215AC0(D_FLT_002BDB5C, &f.cursor, D_STR_002BDB68);
                CTextBox_SetPos(&f.boxX, 0.0f, 0.0f);
                CTextBox_SetSize(&f.boxX, 640.0f, 492.80002f);
                unsigned *prgba = (unsigned *)f.glyph;
                *prgba = 0xFF808080;
                CTextBox_SetTextColor(&f.boxX, prgba);
                CTextBox_SetHorizontalJust(&f.boxX, 0);
                CTextBox_SetVerticalJust(&f.boxX, 0);
                *(B8 *)f.glyph = RO_STR_002A5018;
                func_00215AC0(D_FLT_002BDB50, &f.bright, f.glyph);
                float dxBright = CMovieText_Dx(&f.bright);
                float dyBright = *(float *)(f.bright.data + 0x84);
                func_00215AC0(D_FLT_002BDB54, &f.dim, f.glyph);
                float dxDim = CMovieText_Dx(&f.dim);
                float dyDim = *(float *)(f.dim.data + 0x84);
                float dxUnknown = CMovieText_Dx(&f.unknown);
                float dyUnknown = *(float *)(f.unknown.data + 0x84);
                float half = 0.5f;
                float dxCursor = CMovieText_Dx(&f.cursor);
                f.dyCursor = *(float *)(f.cursor.data + 0x84);
                for (int ibeat = 0; ibeat < *(int *)(prhythm + 0x60); ibeat++) {
                    Beat *pbeat = (Beat *)(prhythm + 0x70 + ibeat * 0x30);
                    if (*(int *)(prhythm + 0x50) == 1 || pbeat->fHit != 0 || pbeat->tBeat + *(float *)(prhythm + 0x5C) < tMusic) {
                        for (unsigned iicon = 0; iicon < 4; iicon++) {
                            Icon *picon = &D_002BDB70[iicon];
                            float x = pbeat->x + picon->xIcons * dxDim;
                            float y = pbeat->y + picon->yIcons * dyDim;
                            unsigned char chGlyph = 'o';
                            float gScale = D_FLT_002BDB54;
                            if (picon->grfbtn == pbeat->grfbtnKind) {
                                chGlyph = picon->chGlyph;
                                x = x - (dxBright - dxDim) * 0.5f;
                                y = y - (dyBright - dyDim) * 0.5f;
                                gScale = D_FLT_002BDB50;
                            }
                            f.glyph[0] = '&';
                            f.glyph[1] = '2';
                            f.glyph[2] = chGlyph;
                            f.glyph[3] = '&';
                            f.glyph[4] = '.';
                            f.glyph[5] = 0;
                            func_00215AC0(gScale, &f.bright, f.glyph);
                            f.boxX = x;
                            f.boxY = y;
                            CMovieText_Draw(&f.bright, &f.boxX, 0xC);
                        }
                    } else {
                        f.boxX = pbeat->x - dxUnknown * half;
                        f.boxY = pbeat->y - dyUnknown;
                        CMovieText_Draw(&f.unknown, &f.boxX, 0xC);
                    }
                }
                int ibeatCursor = *(int *)(prhythm + 0x194);
                if (ibeatCursor < *(int *)(prhythm + 0x60)) {
                    Beat *pbeatCursor = (Beat *)(prhythm + 0x70 + ibeatCursor * 0x30);
                    if (*(int *)(prhythm + 0x190) == 0) {
                        if (pbeatCursor->tBeat - tMusic < D_FLT_002BDBB0) {
                            *(int *)(prhythm + 0x190) = 1;
                            *(QW *)(prhythm + 0x1B0) = D_002BDBC0;
                        }
                    } else if (*(int *)(prhythm + 0x190) == 1) {
                        if (pbeatCursor->tBeat < tMusic) {
                            *(int *)(prhythm + 0x190) = 0;
                            *(int *)(prhythm + 0x194) = ibeatCursor + 1;
                        }
                    }
                    if (*(int *)(prhythm + 0x190) == 1) {
                        float tRemaining = pbeatCursor->tBeat - tMusic;
                        float tDuration = tRemaining > g_2dded4 ? tRemaining : g_2dded4;
                        EvaluateBezierPos__FfffP6VECTORN63(tDuration, g_2dded4, 1.0f, *(QW *)(prhythm + 0x1A0), *(QW *)(prhythm + 0x1B0), *(QW *)&pbeatCursor->x, D_002BDBD0, (QW *)(prhythm + 0x1A0), (QW *)(prhythm + 0x1B0), 0);
                    }
                }
                f.boxX = *(float *)(prhythm + 0x1A0) - dxCursor * 0.5f;
                f.boxY = ((*(float *)(prhythm + 0x1A4) - dyDim * 3.0f) - f.dyCursor) - 7.0f;
                CMovieText_Draw(&f.cursor, &f.boxX, 0xC);
            }
        }
    }
}
}
