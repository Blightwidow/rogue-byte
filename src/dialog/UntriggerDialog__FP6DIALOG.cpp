#include "sly2.h"
struct SO { char pad[0xEC]; int key; };
struct DIALOG { char pad[0x1C8]; SO *pso; };
int FIgnoreSoIntersection(DIALOG *, SO *);
int UntriggerDialog(DIALOG *pdialog, SO *psoOther)
{
    SO *pso = pdialog->pso;
    if (pso) {
        if (psoOther->key == pso->key)
            return 3;
    }
    return FIgnoreSoIntersection(pdialog, psoOther);
}
