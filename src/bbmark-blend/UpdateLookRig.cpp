struct JOY { char pad[0x30]; unsigned grf; };
struct VT { char pad[0x318]; short delta; short idx; int (*fn)(void *, int); };
struct JT { char pad0[0xC]; VT *vt; char pad1[0x140]; JOY *pjoy; };
struct RIG { JT *pjt; int state; char pad0[4]; int fCanRestart; char pad1[4]; int fReleased; char pad2[0xC8]; int pasega; };
extern "C" {
int FAsegaGone(int);
int GrfbtnVjoyPressedWithin(float, JOY *, int);
void ClearVjoyPresses(JOY *, int);
void SetLookRigState(RIG *, int);
}
extern "C" void UpdateLookRig(RIG *prig, int mode)
{
    if (prig->pasega != 0 && FAsegaGone(prig->pasega) != 0)
        SetLookRigState(prig, -1);
    if (mode != prig->state && prig->state != -1)
        SetLookRigState(prig, mode);
    if (mode != -1 && (prig->state == -1 || prig->fCanRestart != 0)) {
        if (GrfbtnVjoyPressedWithin(0.1f, prig->pjt->pjoy, 0x80) != 0 &&
            prig->pjt->vt->fn((char *)prig->pjt + prig->pjt->vt->delta, 2) != 0) {
            ClearVjoyPresses(prig->pjt->pjoy, 0x80);
            SetLookRigState(prig, -1);
            SetLookRigState(prig, mode);
        }
    }
    if ((prig->pjt->pjoy->grf & 0x80) == 0)
        prig->fReleased = 1;
}
