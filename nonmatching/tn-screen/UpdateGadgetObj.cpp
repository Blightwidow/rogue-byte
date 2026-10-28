#include "sly2.h"
struct VT { char pad[0x258]; short delta; short index; void (*fn)(void *, int); };
struct GadgetObj {
    char pad0[0xC];
    VT *vt;
    char pad1[0x150 - 0x10];
    int state;
    char pad2[4];
    int slot;
    char pad3[0x16C - 0x15C];
    GadgetObj *other;
    float range;
    char pad4[0x1A0 - 0x174];
    int stick;
};
static inline int Less(float a, float b) { return a < b; }
static inline float Length(QW &saved, float range)
{
    int bits;
    asm("lqc2 vf1, %1\n\tvsub.xyzw vf1, vf1, vf2\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "m" (saved), "f" (range));
    return *(float *)&bits;
}
extern "C" void UpdateSo(void *);
extern "C" QW PosLoWorld(void *);
extern "C" void StickGadgetObj(GadgetObj *, int);
extern "C" void UpdateGadgetObj(GadgetObj *pgadget)
{
    UpdateSo(pgadget);
    if (pgadget->state == 1 && pgadget->slot != -1)
        StickGadgetObj(pgadget, pgadget->stick);
    if (pgadget->other) {
        QW saved;
        QW a = PosLoWorld(pgadget);
        asm("qmtc2.ni %0, vf1" : : "r" (a));
        asm("sqc2 vf1, %0" : "=m" (saved));
        QW b = PosLoWorld(pgadget->other);
        asm("qmtc2.ni %0, vf2" : : "r" (b));
        float range = pgadget->range;
        if (Less(range, Length(saved, range))) {
            VT *vt = pgadget->vt;
            vt->fn((char *)pgadget + vt->delta, 0);
        }
    }
}
