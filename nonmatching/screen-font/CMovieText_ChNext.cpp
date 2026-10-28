#include "sly2.h"
struct B4 { char b[4]; };
struct MT { char pad0[4]; unsigned char *p; int cur; int base; int other; B4 rgbaCur; B4 rgbaBase; B4 rgbaOther; char pad20[0x40]; int changed; };
extern "C" void CMovieText_UpdateFont(MT *);

unsigned char CMovieText_ChNext(MT *t)
{
    int done = 0;
    t->changed = 0;
    do {
        unsigned char *p = t->p;
        unsigned c = p[0];
        if (c == 0x26) {
            unsigned d = p[1];
            if (d == c) {
                done = 1;
                t->p = p + 1;
            } else {
                if (d == 0x2E) {
                    t->p = p + 2;
                    t->cur = t->base;
                    t->rgbaCur = t->rgbaBase;
                } else {
                    t->p = p + 2;
                    t->cur = t->other;
                    t->rgbaCur = t->rgbaOther;
                }
                t->changed = 1;
                CMovieText_UpdateFont(t);
            }
        } else {
            done = 1;
        }
    } while (done == 0);
    unsigned char *q = t->p;
    unsigned char r = *q;
    t->p = q + 1;
    return r;
}
