#include "sly2.h"
struct SW;
struct BLOT;
struct VT { char pad[0x188]; short delta; short index; void (*fnMessage)(void *, int); short delta2; short index2; void (*fnStop)(void *); };
struct BLOTV { char pad[0xC]; VT *vt; };
struct WIPE { int wipes; int fHasTrans; char trans[0x4C]; BLOTV *pblot; };
extern "C" char B_003DD490[];
extern "C" void SetSwLoadRequest(void *, void *);
extern "C" void SetWipeWipes(WIPE *pwipe, int wipesNew)
{
    if (pwipe->wipes != wipesNew) {
        pwipe->wipes = wipesNew;
        switch (wipesNew) {
        case 0:
            pwipe->fHasTrans = 0;
            memset(pwipe->trans, 0, 0x4C);
            if (pwipe->pblot) {
                BLOTV *pblot = pwipe->pblot;
                pblot->vt->fnStop((char *)pblot + pblot->vt->delta2);
            }
            break;
        case 1: {
            BLOTV *pblot = pwipe->pblot;
            pblot->vt->fnMessage((char *)pblot + pblot->vt->delta, 0x311);
            break;
        }
        case 2: {
            BLOTV *pblot = pwipe->pblot;
            pblot->vt->fnMessage((char *)pblot + pblot->vt->delta, 0x30F);
            break;
        }
        case 3:
            SetSwLoadRequest(B_003DD490, pwipe->trans);
            pwipe->fHasTrans = 0;
            memset(pwipe->trans, 0, 0x4C);
            break;
        }
    }
}
