#include "sly2.h"
struct Word { char b[4]; };
struct CRichText {
    int start; int cur; int base; int baseFont;
    char pad[0x150 - 0x10];
    int flag; Word rgbaCur; Word rgbaMarkup; Word rgbaBase;
};
extern "C" void Reset__9CRichText(CRichText *self)
{
    self->cur = self->start;
    self->base = self->baseFont;
    self->rgbaMarkup = self->rgbaBase;
    self->rgbaCur = self->rgbaMarkup;
    self->flag = 0;
}
