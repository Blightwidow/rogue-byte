#include "sly2.h"
#include "so.h"
struct DIALOG { char pad[0x1C8]; SO *pso; };
int FIgnoreSoIntersection(DIALOG *, SO *);
int UntriggerDialog(DIALOG *pdialog, SO *psoOther)
{
    SO *pso = pdialog->pso;
    if (pso) {
        if (psoOther->poxa == pso->poxa)
            return 3;
    }
    return FIgnoreSoIntersection(pdialog, psoOther);
}
