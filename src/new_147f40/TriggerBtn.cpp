#include "sly2.h"
struct OVT { char pad[0x18]; short deltaEvent; short indexEvent; void (*pfnEvent)(void *, int, int, int, int, int); short deltaMsg; short indexMsg; void (*pfnMsg)(void *, int, void *); };
struct ALO { char pad[0xC]; OVT *vt; };
struct BTN { ALO *palo; char pad[0x9C - 4]; int fNoSound; char pad2[0xA4 - 0xA0]; int fNoButtonsReset; };
extern "C" void *NewEmitter(int);
extern "C" void SetEmitterUnpositioned(void *, ALO *);
extern "C" void RunBtnAsegs(BTN *, int);
void SetBtnButtons__FP3BTN7BUTTONS(BTN *, int);
void TriggerBtn(BTN *pbtn)
{
    ALO *palo = pbtn->palo;
    OVT *vt = palo->vt;
    vt->pfnEvent((char *)palo + vt->deltaEvent, 5, 0, 0, 0, 0);
    if (pbtn->fNoSound == 0) {
        ALO *paloEmit = pbtn->palo;
        void *pemitter = NewEmitter(2);
        SetEmitterUnpositioned(pemitter, paloEmit);
    }
    RunBtnAsegs(pbtn, 0);
    if (pbtn->fNoButtonsReset == 0)
        SetBtnButtons__FP3BTN7BUTTONS(pbtn, 2);
    ALO *paloMsg = pbtn->palo;
    OVT *vtMsg = paloMsg->vt;
    vtMsg->pfnMsg((char *)paloMsg + vtMsg->deltaMsg, 6, pbtn);
}
