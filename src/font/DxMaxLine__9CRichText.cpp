#include "sly2.h"
static inline float fmax2(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline void fmaxassign(float &dst, float other) { asm("max.s %0, %1, %0" : "+f"(dst) : "f"(other)); }
struct CRichText { int unk0; int unk4; void *pfont; };
extern "C" void Reset__9CRichText(CRichText *);
extern "C" char ChNext__9CRichText(CRichText *);
extern "C" float DxFromCh__8CFontBrxc(void *, char);

float DxMaxLine__9CRichText(CRichText *prich)
{
    float dxMax = 0.0f;
    register float dxLine asm("$f21") = dxMax;
    Reset__9CRichText(prich);
    char ch;
    while ((ch = ChNext__9CRichText(prich)) != 0) {
        if (ch == '\n') {
            dxMax = dxMax > dxLine ? dxMax : dxLine;
            dxLine = 0.0f;
        } else {
            dxLine += DxFromCh__8CFontBrxc(prich->pfont, ch);
        }
    }
    dxMax = dxMax > dxLine ? dxMax : dxLine;
    return dxMax;
}
