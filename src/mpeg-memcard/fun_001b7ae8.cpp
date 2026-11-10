#include "sly2.h"
#include "murray.h"
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
    LO *lo = *(LO **)((char *)murray->ploCarried + 0x180);
    murray->ploCarried = 0;
    unsigned long inWorld = (lo->grfo >> 60) & 1; if (inWorld) {
        if (FIsBasicDerivedFrom(lo, 0x38))
            func_00209FB8(lo);
        QW velocity = bevy_camera_follow_track_heading_weight(murray, 0, D_002C09D0);
        lo->Slot35(velocity);
        lo->Slot36(g_2a2dd0);
        func_001F7A68(lo, 3);
    }
}
