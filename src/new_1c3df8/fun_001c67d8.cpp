#include "sly2.h"
struct DP { char pad0[0x1A0]; float f1A0; char pad1[0x1D0-0x1A4]; float f1D0, f1D4, f1D8, f1DC, f1E0, f1E4; char pad2[0x230-0x1E8]; float f230, f234; int pad238; int i23C, i240; };
extern "C" void InitDprize(DP *);

void func_001C67D8(DP *dp)
{
    InitDprize(dp);
    dp->f1D8 = 45.0f;
    dp->f1DC = 75.0f;
    dp->f1DC = 75.0f;
    dp->f1D0 = 250.0f;
    dp->f1D4 = 50.0f;
    dp->f1E4 = 0.2f;
    dp->f1E0 = 0.65f;
    dp->f1A0 = 0.25f;
    dp->i23C = 10;
    dp->i240 = 20;
    dp->f230 = 4.0f;
    dp->f234 = 5.0f;
}
