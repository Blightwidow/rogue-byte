#include "sly2.h"
struct RefRaw_201110 { int tagk; union { int n; float g; void *p; }; };
struct Ref_201110 : RefRaw_201110 { Ref_201110() { tagk = -1; } };
struct Bytes8 { char bytes[8]; };
struct Bytes12 { char bytes[8]; int tail; };
struct Blob48 { QW row[3]; };
extern "C" {
void SetTag__4CRef4TAGK(Ref_201110 *, int);
void CRef_RefCoerceF32(RefRaw_201110 *, Ref_201110 *);
void CRef_RefCoerceS32(RefRaw_201110 *, Ref_201110 *);
void CRef_Destruct(RefRaw_201110 *);
void __as__4CRefRC4CRef(void *dst, void *src);
}
extern "C" Ref_201110 *RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(Ref_201110 *ret, int count, Ref_201110 *src, unsigned *types, void **dsts)
{
    Ref_201110 q;
    for (int i = 0; i < count; i++) {
        __as__4CRefRC4CRef(&q, &src[i]);
        unsigned type = types[i];
        void *dst = dsts[i];
        switch (type) {
        case 5: case 6: case 7: case 8:
        case 14: case 15: case 16: case 17:
        case 19: case 20: case 21:
            if (q.tagk == 0x15)
                goto store;
            {
                Ref_201110 a;
                RefRaw_201110 b;
                CRef_RefCoerceS32(&b, &q);
                __as__4CRefRC4CRef(&a, &b);
                CRef_Destruct(&b);
                *(int *)dst = a.n;
                CRef_Destruct(&a);
            }
            break;
        case 1:
            if (q.tagk == 0x16) {
                *(float *)dst = q.g;
            } else {
                Ref_201110 a;
                RefRaw_201110 c;
                CRef_RefCoerceF32(&c, &q);
                __as__4CRefRC4CRef(&a, &c);
                CRef_Destruct(&c);
                *(float *)dst = a.g;
                CRef_Destruct(&a);
            }
            break;
        case 4:
            *(Blob48 *)dst = *(Blob48 *)q.p;
            break;
        case 2:
        case 9:
            *(QW *)dst = *(QW *)q.p;
            break;
        case 10:
            *(Bytes8 *)dst = *(Bytes8 *)q.p;
            break;
        case 11:
            *(Bytes12 *)dst = *(Bytes12 *)q.p;
            break;
        default:
            if (type & 0x8000) {
                __as__4CRefRC4CRef((Ref_201110 *)dst, &q);
            } else if (type & 0x1000) {
                goto store;
            } else if (type & 0x2000) {
                goto store;
            }
            break;
        case 13:
        case 22:
            break;
        case 0:
        store:
            *(int *)dst = q.n;
            break;
        }
    }
    SetTag__4CRef4TAGK(ret, 0x24);
    CRef_Destruct(&q);
    return ret;
}
