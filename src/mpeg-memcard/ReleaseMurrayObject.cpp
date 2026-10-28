#include "sly2.h"
struct VT18 { char pad[0x18]; short delta; short index; void (*fn)(char *, int, int, int, int, int); };
struct VT118 { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
struct SLOT { short delta; short index; void (*fn)(char *, QW); };
struct LO { char pad0[0xC]; VT118 *vt; };
struct OBJ { char pad0[0xC]; VT18 *vt; };
struct MURRAY { char pad[0x13D0]; int state; char pad1[0x1F0 - 0xD0 + 0x1200 - 0x1200]; };
extern const QW D_002C09E0;
extern const QW g_2a2dd0;
extern "C" {
void DetachMurrayObject(void *);
int FIsBasicDerivedFrom(void *, int);
void func_00209EE0(void *);
void func_001F7A68(void *, int);
void SetSmaGoal__FP3SMA3OID(void *, int);
QW bevy_camera_follow_track_heading_weight(void *, int, QW);
}
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

void ReleaseMurrayObject(void *m)
{
    if (F(int, m, 0x13D0) == 6) {
        if (F(void *, m, 0x1530) != 0)
            SetSmaGoal__FP3SMA3OID(F(void *, m, 0x1530), 0x1CA);
        return;
    }
    OBJ *pobj = F(OBJ *, m, 0x13F0);
    if (pobj == 0) return;
    if (F(int, m, 0x13D0) == 4 && F(int, m, 0x1450) == 0) {
        pobj->vt->fn((char *)pobj + pobj->vt->delta, 6, 0, 0, 0, 0);
        F(int, m, 0x13F0) = 0;
        return;
    }
    DetachMurrayObject(m);
    LO *plo = F(LO *, F(void *, m, 0x13F0), 0x180);
    if (FIsBasicDerivedFrom(plo, 0x38) != 0)
        func_00209EE0(plo);
    else
        func_001F7A68(plo, 1);
    switch (F(int, m, 0x13D0)) {
    case 5: {
        SLOT *slot = (SLOT *)((char *)plo->vt + 0x118);
        char *self = (char *)plo + slot->delta;
        QW v = bevy_camera_follow_track_heading_weight(m, 0, D_002C09E0);
        slot->fn(self, v);
        break;
    }
    case 2:
    case 4:
    case 7:
    case 8:
        plo->vt->fn((char *)plo + plo->vt->delta, g_2a2dd0);
        break;
    }
    F(int, m, 0x13F0) = 0;
}
