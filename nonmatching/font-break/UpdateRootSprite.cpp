#include "sly2.h"
struct AFF { float a, b, c, d, e, f, u6, u7; } __attribute__((aligned(16)));
struct CM;
struct BLOT { char pad0[0xF4]; void *plo; AFF *pxf; };
struct SPRITE { char pad0[0x24]; BLOT *pmovie; int fRoot; };
extern "C" const AFF RO_002A3A10;
extern CM B_002DDF40;
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertCmWorldToScreen(CM *, QW);
extern "C" void UpdateSpriteInstance(float, SPRITE *, int, AFF *, unsigned *, unsigned *);
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline AFF Mult(const AFF &child, const AFF &parent)
{
    AFF product;
    float ca = child.a, cb = child.b, cc = child.c, cd = child.d, ce = child.e, cf = child.f;
    product.a = ca * parent.a + cb * parent.c;
    product.b = ca * parent.b + cb * parent.d;
    product.c = cc * parent.a + cd * parent.c;
    product.d = cc * parent.b + cd * parent.d;
    product.e = ce * parent.a + cf * parent.c + parent.e;
    product.f = ce * parent.b + cf * parent.d + parent.f;
    return product;
}
extern "C" void UpdateRootSprite(float dt, SPRITE *sprite)
{
    if (sprite->fRoot == 0) return;
    AFF xf = RO_002A3A10;
    if (sprite->pmovie->plo != 0) {
        QW pos = PosLoWorld(sprite->pmovie->plo);
        QW screen = ConvertCmWorldToScreen(&B_002DDF40, pos);
        QW rot = __builtin_prot3w(screen);
        asm volatile("");
        xf.e = Lane(screen) * 320.0f + 320.0f;
        xf.f = Lane(rot) * -246.40001f + 246.40001f;
    }
    if (sprite->pmovie->pxf != 0) {
        xf = Mult(xf, *sprite->pmovie->pxf);
    }
    unsigned add[4];
    unsigned mul[4];
    add[0] = 0x7F7F7F7F;
    mul[0] = 0xFFFFFFFF;
    asm volatile("");
    UpdateSpriteInstance(dt, sprite, 0, &xf, add, mul);
}
