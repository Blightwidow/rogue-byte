#include "sly2.h"
struct CONSTR { QW normal; int ct; int pad[3]; } __attribute__((aligned(16)));
extern "C" void CreateSlotheapSwAlign(void *, int, int, int);
extern CONSTR B_003DD020;
extern CONSTR g_2a2dc0;
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];
extern "C" void StaticInitSlotheaps_1f8c40(int init, int prio)
{
    if (prio == 0xFFFF) {
        if (init) {
            CONSTR *pdefault = &B_003DD020;
            CONSTR local;
            memset(&local, 0, sizeof(CONSTR));
            local.normal = g_2a2dc0.normal;
            local.ct = 1;
            *pdefault = local;
            if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
            if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
            if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
            if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
            if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
            if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
        }
    }
}
