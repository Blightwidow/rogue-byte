#include "sly2.h"
struct Phys { char p0[0x208]; int unk208; char p1[0x4A0 - 0x20C]; int unk4A0; char p2[0xF80 - 0x4A4]; int unkF80; };
struct Guard { Phys *pphys; };
extern "C" {
int FIsGuardInSgs(Phys *, int);
QW ConvertAloPos(Phys *, int, QW);
int FFindSurfaceAlongUp(float, float, QW *, long, void *);
void func_0020CFC0();
extern QW D_002C3E00[5];
extern float g_2c3e50;
extern float g_2c3e54;
}
int FGuardOffGround(Guard *pguard)
{
    Phys *pphys = pguard->pphys;
    if (pphys->unk208 == 0) {
        if (pphys->unkF80 == -1) {
            if (pphys->unk4A0 != 0) {
                if (!FIsGuardInSgs(pphys, 0x13)) {
                    unsigned i = 0;
                    QW *ppos = D_002C3E00;
                    do {
                        QW pos = ConvertAloPos(pguard->pphys, 0, *ppos);
                        if (FFindSurfaceAlongUp(g_2c3e50, g_2c3e54, &pos, 1, (void *)func_0020CFC0))
                            break;
                        i++;
                        ppos++;
                    } while (i < 5);
                    return (i < 5) ^ 1;
                }
            }
        }
    }
    return 0;
}
