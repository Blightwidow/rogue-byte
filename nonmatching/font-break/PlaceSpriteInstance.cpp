#include "sly2.h"
struct B4 { char b[4]; };
struct LABEL { char pad[0x14]; int id; };
struct SPRITE { unsigned short clabel; char pad2[2]; LABEL *labels; char pad8[8]; unsigned long stamp; float tStopped; int ilabelStopped; int ilabelPending; };
extern unsigned long g_2ddf18;
void StartSpriteInstance(float, SPRITE *, int, int, void *, B4 *, B4 *);

void PlaceSpriteInstance(SPRITE *s, int id, int iinst, void *xf, B4 *add, B4 *mul)
{
    float start = 0.0f;
    int ilabel;
    if (id == 0x314) {
        ilabel = s->ilabelPending;
        if (ilabel != -1) {
            s->ilabelPending = -1;
        } else {
            if (s->stamp == g_2ddf18) {
                start = s->tStopped;
                ilabel = s->ilabelStopped;
            } else {
                s->tStopped = 0.0f;
                ilabel = 0;
                s->ilabelStopped = 0;
            }
        }
    } else {
        int count = s->clabel;
        if (count == 0) return;
        for (ilabel = 0; ilabel < count; ilabel++) {
            if (s->labels[ilabel].id == id) break;
        }
        if (ilabel >= count) return;
    }
    B4 a = *add;
    B4 m = *mul;
    StartSpriteInstance(start, s, ilabel, iinst, xf, &a, &m);
}
