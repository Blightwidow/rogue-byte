#include "sly2.h"
struct VT1F0 { char pad[0x1F0]; short delta; short index; int (*fn)(char *); };
struct VT108 { char pad[0x108]; short delta; short index; QW (*fn)(char *); };
struct XPSIDE { char pad[0xC]; void *plo; char pad1[0x40 - 0x10]; };
struct XP { XPSIDE side[2]; char pad[0x80 - 0x80]; QW normal; float nz; };
struct LOBJ { char pad[0xC]; VT1F0 *vt; };
struct MUR { char pad[0xC]; VT108 *vt; };
extern "C" {
extern float D_002C0A38;
extern float D_002C3C60[];
extern char B_003DD490[];
void AdjustStepNewXp(void *, void *, int);
void AdjustJtZapNewXp(void *, void *, int);
void func_0019E9C8(void *, void *, int);
void *CloneMqList(void *, void *);
void PrependMqList(void *, void *, void *);
QW GCosAngle(QW, QW);
}
#define F(type, base, off) (*(type *)((char *)(base) + (off)))
static inline float AsFloat(QW w) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (w)); return f; }

void AdjustMurrayNewXp(MUR *m, XP *pxp, int iside)
{
    AdjustStepNewXp(m, pxp, iside);
    switch (F(int, m, 0x13D0)) {
    case 0xE:
        AdjustJtZapNewXp((char *)m + 0xDF0, pxp, iside);
        break;
    case 0xC: {
        int charges = F(int, m, 0x1840);
        if (charges != 1) break;
        LOBJ *pother = (LOBJ *)pxp->side[1 - iside].plo;
        if (pother->vt->fn((char *)pother + pother->vt->delta) != 0) {
            float v = F(float, pxp, 0x88);
            float k;
            asm volatile("lui $1,0x3F33\n\tori $1,$1,0x3333\n\tmtc1 $1,%0\n\tnop" : "=f"(k) : : "$1");
            if (v < k) {
                QW velocity = m->vt->fn((char *)m + m->vt->delta);
                QW cosine = GCosAngle(velocity, pxp->normal);
                int hit = AsFloat(cosine) < D_002C0A38;
                if (hit)
                    F(int, m, 0x1908) = charges;
            }
        }
        break;
    }
    case 3:
        if (F(int, m, 0x13D8) == 1) {
            if (0.7f < D_002C3C60[iside] * F(float, pxp, 0x88)) {
                void *pmq = CloneMqList(B_003DD490, pxp);
                PrependMqList(B_003DD490, pmq, (char *)m + 0x13E4);
            }
        }
        break;
    case 0x14:
        func_0019E9C8((char *)m + 0xF50, pxp, iside);
        break;
    }
}
