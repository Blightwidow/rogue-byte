#include "sly2.h"
struct M4 { QW row[4]; };
struct OBJM { M4 m; char pad[0x64]; int stamp; };
struct BASIC {
    char pad0[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17();
};
struct S : BASIC {
    char pad1[0x44]; OBJM *mat;
};
struct G { char pad[0x3D58]; int counter; };
extern G B_003DD490;
extern "C" {
M4 __ml__FRC7MATRIX4T0(const M4 &, const M4 &);
void RefreshAloIkLimbLengths(S *);
}

void func_001F4010(S *s, const M4 &other)
{
    OBJM *mat = s->mat;
    mat->m = __ml__FRC7MATRIX4T0(other, mat->m);
    int stamp = ++B_003DD490.counter;
    s->mat->stamp = stamp;
    s->v17();
    RefreshAloIkLimbLengths(s);
}
