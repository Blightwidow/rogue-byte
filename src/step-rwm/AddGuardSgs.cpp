#include "sly2.h"
struct ENTRY { int sgs; int activity; };
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int **, int); };
struct OBJ { char pad[0xC]; VT *vt; };
struct GUARD : OBJ { char pad2[0x2C0 - 0x10]; unsigned long grf; };
extern "C" {
void SetGuardGrfsgs(GUARD *, unsigned long);
int FIsSgsInGrfsgs(unsigned long, int);
unsigned long GrfsgsFromSgs(int);
void bevy_camera_follow_activity(void *, int, GUARD *);
extern char B_002DEB30[];
extern ENTRY D_002C3D98[];
}
extern "C" void AddGuardSgs(GUARD *pguard, int sgs)
{
    unsigned long grfNew = GrfsgsFromSgs(sgs);
    SetGuardGrfsgs(pguard, pguard->grf | grfNew);
    int sgsNone = -1;
    int *argv[2];
    argv[0] = &sgs;
    argv[1] = &sgsNone;
    VT *vt = pguard->vt;
    vt->fn((char *)pguard + vt->delta, 7, 0, 2, argv, 0);
    for (unsigned index = 0; index < 2; index++) {
        if (FIsSgsInGrfsgs(grfNew, D_002C3D98[index].sgs))
            bevy_camera_follow_activity(B_002DEB30, D_002C3D98[index].activity, pguard);
    }
}
