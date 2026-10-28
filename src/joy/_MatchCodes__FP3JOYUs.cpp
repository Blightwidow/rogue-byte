#include "sly2.h"
struct CODE { int *pgrf; int cgrf; char pad[8]; int igrf; int unk14; CODE *pnext; };
struct CODELIST { CODE *pfirst; char pad[0xC - 4]; float tFire; };
struct JOY { char pad[0x10B4]; int btnLatest; };
struct CLOCK { char pad[0x3C]; float tReal; };
extern JOY B_002DFC00;
extern int B_003DA0B8;
extern CLOCK g_2dded0;
void _MatchCodes__FP3JOYUs(CODELIST *plist, JOY *pjoy, unsigned short btn)
{
    if (pjoy != &B_002DFC00)
        return;
    if (btn == pjoy->btnLatest || pjoy->btnLatest == 0 || B_003DA0B8 == 0)
        return;
    for (CODE *pcode = plist->pfirst; pcode != 0; pcode = pcode->pnext) {
        int igrf = pcode->igrf;
        int fDone = igrf >= pcode->cgrf;
        if (!fDone) {
            if (pcode->pgrf[igrf] == pjoy->btnLatest) pcode->igrf = igrf + 1; else pcode->igrf = 0;
        }
    }
    plist->tFire = g_2dded0.tReal + 1.0f;
}
