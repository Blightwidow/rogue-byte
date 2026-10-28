#include "sly2.h"
struct B8 { char b[8]; };
struct TN {
    char pad0[0x13C]; int unk13C;
    char pad1[0x24]; int unk164;
    char pad2[8];
    float f170, f174, f178, f17C; int unk180;
    char pad4[0x1C]; QW q1A0; B8 b1B0;
};
struct TN40 { char pad[0x40]; unsigned flags; };
extern "C" {
extern const QW D_002C41C0;
extern const B8 D_002C41D0;
void InitXfm(void *);
void func_001A6CA8(void *, int);
void InitTn__FP2TN(TN *ptn)
{
    InitXfm(ptn);
    const QW *pq = &D_002C41C0;
    ptn->f178 = 2.0f;
    ptn->f170 = 2.0f;
    ptn->f17C = 1.0f;
    ptn->f174 = 1.0f;
    ptn->unk180 = -1;
    ptn->q1A0 = *pq;
    ptn->b1B0 = D_002C41D0;
    ptn->unk13C = -1;
    ptn->unk164 = 7;
    func_001A6CA8(ptn, 1);
    unsigned flags = ((TN40 *)ptn)->flags;
    if (((flags ^ 1) & 1) != 0)
        *(unsigned *)flags |= 2;
    else
        ((TN40 *)ptn)->flags = flags | 2;
}
}
