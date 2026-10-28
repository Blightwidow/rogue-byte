#include "sly2.h"
struct VT118 { char pad[0x118]; short delta; short index; void (*fn)(char *, QW); };
struct VT120 { char pad[0x120]; short delta; short index; void (*fn)(char *, QW); };
struct LO { char pad0[0xC]; VT118 *vt; char pad1[0x18]; unsigned long flags; };
struct LO2 { char pad0[0xC]; VT120 *vt; };
struct MURRAY { char pad[0x13F0]; LO *carried; };
extern const QW D_002C09D0;
extern const QW g_2a2dd0;
extern "C" void DetachMurrayObject(MURRAY *);
extern "C" int FIsBasicDerivedFrom(LO *, int);
extern "C" void func_00209FB8(LO *);
extern "C" QW bevy_camera_follow_track_heading_weight(MURRAY *, int, QW);
extern "C" void func_001F7A68(LO *, int);

extern "C" void func_001B7AE8(MURRAY *murray)
{
    DetachMurrayObject(murray);
    LO *lo = *(LO **)((char *)murray->carried + 0x180);
    murray->carried = 0;
    unsigned long inWorld = (lo->flags >> 60) & 1; if (inWorld) {
        if (FIsBasicDerivedFrom(lo, 0x38))
            func_00209FB8(lo);
        QW velocity = bevy_camera_follow_track_heading_weight(murray, 0, D_002C09D0);
        lo->vt->fn((char *)lo + lo->vt->delta, velocity);
        VT120 *vt = ((LO2 *)lo)->vt;
        vt->fn((char *)lo + vt->delta, g_2a2dd0);
        func_001F7A68(lo, 3);
    }
}
