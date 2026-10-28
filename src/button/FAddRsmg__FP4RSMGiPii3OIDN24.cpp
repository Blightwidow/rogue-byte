#include "sly2.h"
struct RSMG { int oidRoot; int oidSM; int oidTriggerGoal; int oidUntriggerGoal; };
extern "C" int FAddRsmg__FP4RSMGiPii3OIDN24(void *unused, RSMG *arsmg, int crsmgMax, int *pcrsmg, int fOnTrigger, int oidRoot, int oidSM, int oidGoal)
{
    int irsmg;
    for (irsmg = 0; irsmg < *pcrsmg; irsmg++) {
        RSMG *prsmg = &arsmg[irsmg];
        if (prsmg->oidRoot == oidRoot && (prsmg->oidSM == -1 || prsmg->oidSM == oidSM)) {
            if (fOnTrigger != 0)
                prsmg->oidTriggerGoal = oidGoal;
            else
                prsmg->oidUntriggerGoal = oidGoal;
            return 1;
        }
    }
    int irsmgNew = *pcrsmg;
    if (irsmgNew + 1 >= crsmgMax)
        return 0;
    *pcrsmg = irsmgNew + 1;
    RSMG *prsmgNew = (RSMG *)(irsmgNew * 16 + (int)arsmg);
    prsmgNew->oidRoot = oidRoot;
    prsmgNew->oidSM = oidSM;
    if (fOnTrigger != 0) {
        prsmgNew->oidTriggerGoal = oidGoal;
        prsmgNew->oidUntriggerGoal = -1;
    } else {
        prsmgNew->oidUntriggerGoal = oidGoal;
        prsmgNew->oidTriggerGoal = -1;
    }
    return 1;
}
