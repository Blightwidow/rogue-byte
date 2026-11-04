// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct RGBA_15FFD0 { unsigned char r, g, b, a; };
struct CFontBrx_15FFD0 { char pad0[0xC]; int dyUnscaled; char pad1[0x14 - 0x10]; float ryScale; };
struct CTextBox_15FFD0 { float x; float y; float dx; float dy; RGBA_15FFD0 rgba; int jh; int jv; };
struct GIFS_15FFD0;
struct CRichText_15FFD0 { int unk0; int unk4; CFontBrx_15FFD0 *pfont; CFontBrx_15FFD0 *pfontBase; char pad[0x150 - 0x10]; int fSwitchTex; unsigned rgbaCur; };
extern "C" {
void Reset__9CRichText(CRichText_15FFD0 *);
char ChNext__9CRichText(CRichText_15FFD0 *);
float DxFromCh__8CFontBrxc(CFontBrx_15FFD0 *, char);
void SetBaseColor__9CRichTextP4RGBA(CRichText_15FFD0 *, RGBA_15FFD0 *);
void SetupDraw__8CFontBrxP8CTextBoxP4GIFS(CFontBrx_15FFD0 *, CTextBox_15FFD0 *, GIFS_15FFD0 *);
void SwitchTex0__8CFontBrxP4GIFS(CFontBrx_15FFD0 *, GIFS_15FFD0 *);
float DxDrawCh__8CFontBrxcffUiP4GIFS(CFontBrx_15FFD0 *, char, float, float, unsigned, GIFS_15FFD0 *);
void CleanupDraw__5CFontP8CTextBoxP4GIFS(CFontBrx_15FFD0 *, CTextBox_15FFD0 *, GIFS_15FFD0 *);

void Draw__9CRichTextP8CTextBoxT1P4GIFS(CRichText_15FFD0 *self, CTextBox_15FFD0 *ptb, CTextBox_15FFD0 *ptbClip, GIFS_15FFD0 *pgifs)
{
    float adx[64];
    int fNewLine = 1;
    int iline = 0;
    char ch;
    memset(adx, 0, sizeof(adx));
    Reset__9CRichText(self);
    while ((ch = ChNext__9CRichText(self)) != 0) {
        if (ch == '\n')
            iline++;
        else
            adx[iline] += DxFromCh__8CFontBrxc(self->pfont, ch);
    }
    float y;
    if (ptb->jv == 0) {
        y = ptb->y;
    } else {
        float dyText = (float)(iline + 1) * ((float)self->pfontBase->dyUnscaled * self->pfontBase->ryScale);
        if (ptb->jv == 2)
            y = ptb->y + ptb->dy - dyText;
        else
            y = ptb->y + (ptb->dy - dyText) * 0.5f;
    }
    RGBA_15FFD0 rgba = ptb->rgba;
    SetBaseColor__9CRichTextP4RGBA(self, &rgba);
    CFontBrx_15FFD0 *pfontSetup = 0;
    float x;
    Reset__9CRichText(self);
    float *pdx = adx;
    while ((ch = ChNext__9CRichText(self)) != 0) {
        if (ch == '\n') {
            fNewLine = 1;
            pdx++;
            y += (float)self->pfontBase->dyUnscaled * self->pfontBase->ryScale;
            continue;
        }
        if (fNewLine) {
            if (ptb->jh == 0)
                x = ptb->x;
            else {
                float dxLine = *pdx;
                if (ptb->jh == 2)
                    x = ptb->x + ptb->dx - dxLine;
                else
                    x = ptb->x + (ptb->dx - dxLine) * 0.5f;
            }
            fNewLine = 0;
        }
        if (pfontSetup == 0) {
            SetupDraw__8CFontBrxP8CTextBoxP4GIFS(self->pfont, ptbClip, pgifs);
            pfontSetup = self->pfont;
        } else if (self->fSwitchTex) {
            SwitchTex0__8CFontBrxP4GIFS(self->pfont, pgifs);
            self->fSwitchTex = 0;
        }
        x += DxDrawCh__8CFontBrxcffUiP4GIFS(self->pfont, ch, x, y, self->rgbaCur, pgifs);
    }
    CleanupDraw__5CFontP8CTextBoxP4GIFS(self->pfont, ptbClip, pgifs);
}
}
