#include "sly2.h"
struct OBSTACLE { char pad0[0xE8]; int cpos; float *au; int unkF0; VECTOR *apos; char pad1[0x190 - 0xF8]; int convk; };
extern "C" void PostLoLoad(OBSTACLE *);
extern "C" int func_001BC2F8(OBSTACLE *);
extern "C" float UMaxCrv(OBSTACLE *);
extern "C" void MeasureCrv(OBSTACLE *);
extern "C" void Obstacle_PostLoad(OBSTACLE *pobstacle)
{
    PostLoLoad(pobstacle);
    int convk = func_001BC2F8(pobstacle);
    pobstacle->convk = convk;
    if (convk != 3) {
      if (convk == 4) {
        int cswap = pobstacle->cpos / 2;
        float uMax = UMaxCrv(pobstacle);
        for (int iswap = 0; iswap < cswap; iswap++) {
            VECTOR *apos = pobstacle->apos;
            int iposOther = pobstacle->cpos - iswap - 1;
            VECTOR posSaved = apos[iswap];
            apos[iswap] = apos[iposOther];
            apos[iposOther] = posSaved;
            float *au = pobstacle->au;
            float uSaved = au[iswap];
            au[iswap] = au[iposOther];
            au[iposOther] = uSaved;
            pobstacle->au[iswap] = uMax - pobstacle->au[iswap];
            pobstacle->au[iposOther] = uMax - pobstacle->au[iposOther];
        }
        MeasureCrv(pobstacle);
        pobstacle->convk = 3;
      }
    }
}
