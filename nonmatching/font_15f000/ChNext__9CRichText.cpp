struct Word { unsigned char b[4]; };
struct CFont { char pad0[0xC]; int height; float sx; float sy; char pad[0x140 - 0x18]; } __attribute__((aligned(16)));
struct CRichText {
    int start; unsigned char *cur; CFont *base; CFont *baseFont;
    CFont font;
    int flag; Word rgbaCur; Word rgbaMarkup; Word rgbaBase; Word rgbaSaved;
};
extern "C" {
CFont *PfontFromCh(int);
void PushScaling__5CFontff(CFont *, float, float);
void PopScaling__5CFont(CFont *);
}
extern "C" int ChNext__9CRichText(CRichText *self)
{
    int done = 0;
    do {
        unsigned char *pch = self->cur;
        switch (*pch) {
        case '~':
            if (pch[1] == *pch) {
                self->cur = pch + 1;
                done = 1;
            } else if (pch[1] == '.') {
                self->rgbaMarkup = self->rgbaBase;
                self->rgbaCur = self->rgbaMarkup;
                self->cur += 2;
            } else {
                unsigned char *pdigit = pch + 1;
                unsigned int value = 0;
                if (pch[1] != 0 && pdigit - pch < 7) {
                    do {
                        unsigned int digit;
                        if ((unsigned int)(*pdigit - '0') < 10)
                            digit = *pdigit - '0';
                        else if ((unsigned int)(*pdigit - 'A') < 6)
                            digit = *pdigit - 'A' + 10;
                        else if ((unsigned int)(*pdigit - 'a') < 6)
                            digit = *pdigit - 'a' + 10;
                        else
                            break;
                        pdigit++;
                        value = value * 16 + digit;
                    } while (*pdigit != 0 && pdigit - pch < 7);
                }
                if (pdigit - self->cur >= 7) {
                    self->rgbaMarkup.b[0] = (((value >> 16) & 0xFF) + 1) >> 1;
                    self->rgbaMarkup.b[1] = (((value & 0xFF00) >> 8) + 1) >> 1;
                    self->rgbaMarkup.b[2] = ((value & 0xFF) + 1) >> 1;
                    self->rgbaCur = self->rgbaMarkup;
                    self->cur += 7;
                } else {
                    self->base = self->baseFont;
                    self->rgbaCur = self->rgbaBase;
                    done = 1;
                }
            }
            break;
        case '&':
            if (pch[1] == *pch) {
                self->cur = pch + 1;
                done = 1;
            } else if (pch[1] == '.') {
                self->base = self->baseFont;
                self->rgbaCur = self->rgbaMarkup;
                self->flag = 1;
                self->cur += 2;
            } else {
                CFont *pfont = PfontFromCh(pch[1]);
                if (pfont != 0) {
                    self->font = *pfont;
                    self->cur += 2;
                    self->base = &self->font;
                    float ratio = ((float)self->baseFont->height * self->baseFont->sy) / ((float)self->font.height * self->font.sy);
                    self->font.sy *= ratio;
                    self->font.sx *= ratio;
                    Word saved = self->rgbaSaved;
                    saved.b[3] = self->rgbaCur.b[3];
                    self->rgbaCur = saved;
                    self->flag = 1;
                } else {
                    self->base = self->baseFont;
                    self->rgbaCur = self->rgbaBase;
                    self->flag = 1;
                    done = 1;
                }
            }
            break;
        case '^':
            if (pch[1] == *pch) {
                self->cur = pch + 1;
                done = 1;
            } else if (pch[1] == '.') {
                PopScaling__5CFont(self->base);
                self->cur += 2;
            } else {
                float scale = (float)(pch[1] - '0') + (float)(pch[2] - '0') * 0.1f;
                PushScaling__5CFontff(self->base, scale * self->base->sx, scale * self->base->sy);
                self->cur += 3;
            }
            break;
        default:
            done = 1;
            break;
        }
    } while (!done);
    unsigned char *pend = self->cur;
    self->cur = pend + 1;
    return *pend;
}
