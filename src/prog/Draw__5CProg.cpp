#include "sly2.h"
struct GIFS { char pad[0x30]; };
struct RGBA { char c[4]; };
struct CPROG { int f0; int max; int total; int remaining; char pad10[0x40]; int mode; RGBA c54; RGBA c58; RGBA c5c; RGBA c60; };
extern "C" {
void __4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddDmaCnt__4DMAS(GIFS *);
void FillScreenRect__FiiiiffffP4GIFS(RGBA *, GIFS *, float, float, float, float);
float GTrunc__Ff(float);
void AddPrimEnd__4GIFS(GIFS *);
void AddDmaEnd__4DMAS(GIFS *);
void EndDmaCnt__4DMAS(GIFS *);
void Detach__4DMASPiPP2QW(GIFS *, int *, QW **);
void BlastAqwGifsBothFrames__FP2QW(QW *);
void Draw__5CProg(CPROG *self) {
    QW aqw[0x400];
    GIFS gifs;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 0x400, aqw);
    AddDmaCnt__4DMAS(&gifs);
    int fullWidth = (int)((float)self->total * 620.0f / (float)self->max);
    int width = (int)((float)fullWidth * ((float)(self->total - self->remaining) / (float)self->total));
    {
        RGBA back = self->c54;
        FillScreenRect__FiiiiffffP4GIFS(&back, &gifs, 10.0f, GTrunc__Ff(412.90909f) * 1.1f, (float)(width + 10), GTrunc__Ff(412.90909f) * 1.1f + 6.6000004f);
    }
    RGBA fill;
    if (self->mode <= 0) fill = self->c58;
    else if (self->mode == 1) fill = self->c5c;
    else fill = self->c60;
    RGBA copy = fill;
    FillScreenRect__FiiiiffffP4GIFS(&copy, &gifs, (float)(width + 10), GTrunc__Ff(412.90909f) * 1.1f, (float)(fullWidth + 10), GTrunc__Ff(412.90909f) * 1.1f + 6.6000004f);
    AddPrimEnd__4GIFS(&gifs);
    AddDmaEnd__4DMAS(&gifs);
    EndDmaCnt__4DMAS(&gifs);
    Detach__4DMASPiPP2QW(&gifs, 0, 0);
    BlastAqwGifsBothFrames__FP2QW(aqw);
}
}
