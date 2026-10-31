#include "sly2.h"
struct BOMB;
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
extern "C" void UpdateSo(BOMB *);
extern "C" void DetonateBomb(BOMB *);
extern "C" void UpdateBombCustomXps(BOMB *);
extern float g_2dded0;
struct BOMB {
    char pad0[0xC]; VT *vt;
    char pad1[0x154 - 0x10]; float tDetonate; float svDetonate;
    char pad2[0x1F4 - 0x15C]; int fCustomXps;
};
static inline int VelocityBelowLimit(BOMB *pbomb)
{
    VT *vt = pbomb->vt;
    QW velocity = vt->fn((char *)pbomb + vt->delta);
    float length;
    asm("qmtc2.ni %0, vf3" : : "r" (velocity));
    float limit = pbomb->svDetonate;
    asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    asm("qmfc2.ni %0, vf1" : "=r" (length));
    return length < limit;
}
void UpdateBomb__FP4BOMBf(BOMB *pbomb)
{
    UpdateSo(pbomb);
    float timer = pbomb->tDetonate;
    if (timer <= g_2dded0 || VelocityBelowLimit(pbomb)) DetonateBomb(pbomb);
    else if (pbomb->fCustomXps != 0) UpdateBombCustomXps(pbomb);
}
