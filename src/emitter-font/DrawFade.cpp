#include "types.h"
struct Rgba { u8 r, g, b, a; };
struct Fade {
    char pad0[0x50]; Rgba c0; Rgba c1; Rgba c2; f32 d1; f32 d2; f32 d3; f32 start; s32 kind;
};
struct Dmas { char pad[0xC]; s32 mark; };
struct Dli { s32 word0; f32 value; s32 mark; };
extern "C" {
void AddDmaCnt__4DMAS(void *);
void AddDmaRet__4DMAS(void *);
void AddVifDirect__4VIFSiP2QWi(void *, s32, void *, s32);
void BuildClearGifs__FP2QWG4RGBAi(void *, Rgba *, s32);
void EndDmaCnt__4DMAS(void *);
Dli *OnGameLoad__FP4GAME();
extern f32 g_2dded0;
extern Dmas g_2dea28;
}
static inline u8 Lerp(s32 from, s32 to, f32 t) {
    if (from == to) return to;
    if (from < to) return from + (s32)(t * (((f32)to + 0.999f) - (f32)from));
    return to + (s32)((1.0f - t) * (((f32)from + 0.999f) - (f32)to));
}
extern "C" void DrawFade(Fade *self) {
    Rgba copy, from, to, pass, x, y, out;
    f32 elapsed = g_2dded0 - self->start;
    f32 denom;
    if (elapsed < self->d1) {
        from = self->c0; to = self->c1; denom = self->d1;
    } else {
        elapsed -= self->d1;
        if (elapsed < self->d2) {
            from = self->c1; to = self->c1; denom = self->d2;
        } else {
            elapsed -= self->d2;
            if (elapsed < self->d3) {
                from = self->c1; to = self->c2; denom = self->d3;
            }
        }
    }
    f32 t = elapsed / denom;
    x = from;
    y = to;
    out.r = Lerp(x.r, y.r, t);
    out.g = Lerp(x.g, y.g, t);
    out.b = Lerp(x.b, y.b, t);
    out.a = Lerp(x.a, y.a, t);
    pass = out;
    copy = pass;
    pass = copy;
    char buffer[0x250];
    BuildClearGifs__FP2QWG4RGBAi(buffer, &pass, 3);
    s32 mark = g_2dea28.mark;
    AddDmaCnt__4DMAS(&g_2dea28);
    AddVifDirect__4VIFSiP2QWi(&g_2dea28, 0x25, buffer, 0);
    EndDmaCnt__4DMAS(&g_2dea28);
    AddDmaRet__4DMAS(&g_2dea28);
    Dli *dli = OnGameLoad__FP4GAME();
    dli->mark = mark;
    dli->value = -1.0f;
    switch (self->kind) {
    case 0:
        dli->word0 = 1;
        break;
    case 1:
        dli->word0 = 0xE;
        break;
    }
}
