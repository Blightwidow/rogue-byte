#include "sly2.h"
struct M3 { QW row[3]; };
struct Mount { char pad0[0x1C0]; int state; char pad1[0x218 - 0x1C4]; float radHeading; char pad2[4]; QW vecHeading; };
extern "C" QW g_2a2dc0;
extern "C" QW g_2a2dd0;
extern "C" char D_002BE800[];
extern "C" char D_002BE810[];
extern "C" void LoadRotateMatrixRad(M3 *, float, QW);
extern "C" void AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(Mount *, M3 *, void *);
extern "C" void AccelSoTowardPosSpring(Mount *, QW, int, QW, void *);
void Mount_AccelToward(Mount *mount)
{
    if (mount->state != 3) {
        M3 copy;
        M3 mat;
        LoadRotateMatrixRad(&mat, mount->radHeading, g_2a2dc0);
        copy = mat;
        AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(mount, &copy, D_002BE800);
        AccelSoTowardPosSpring(mount, g_2a2dd0, 0, mount->vecHeading, D_002BE810);
    }
}
