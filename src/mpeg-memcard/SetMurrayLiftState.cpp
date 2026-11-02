#include "sly2.h"
struct VTE { short delta; short index; void *fn; };
struct VTBASIC { char pad0[0x100]; VTE getRef; char pad108[0x118 - 0x108]; VTE setXf; };
struct BASIC { char pad0[0xC]; VTBASIC *vt; };
struct XFH { char pad[0x98]; short flags98; char pad9a[6]; int xfA0; };
struct SOB { char pad0[0xC]; VTBASIC *vt; char pad10[0x18]; unsigned long flags; char pad30[0x28]; XFH *xf58; XFH *xf5C; };
struct REFB { int id; int a; int b; char pad[0x94]; QW q; char pada[0x1C]; float f; };
struct PEA { char pad[0x14]; int aseg; };
struct PEAH { char pad[0x14]; void *aseg; char pad18[4]; float time; char pad20[0x20]; float dur; };
struct CARRY { char pad[0x180]; SOB *so; char pad184[0xC]; BASIC *a190; char pad194[4]; BASIC *a198; };
struct MURRAY {
    char pad0[0x60]; int xf60;
    char pad64[0x1030 - 0x64]; PEAH *peah;
    char pad1034[0x1088 - 0x1034]; struct { char pad[0x1C]; int flag; } *pgadget;
    char pad108c[0x13EC - 0x108C]; struct { char pad[0x60]; int xf; } *pheld; CARRY *pcarry;
    int f13F4, f13F8, f13FC, f1400, f1404, f1408;
    char pad140c[0x1448 - 0x140C];
    int f1448; int pad144c; int state; float stateTime;
    char pad1458[0x15F4 - 0x1458]; int f15F4; int f15F8; int f15FC; int f1600; int f1604; int pad1608; int f160C;
    REFB *pref1610; REFB *pref1614; int f1618; int f161C; int f1620; int f1624;
};
static inline float Now(const float *pclock) { return *pclock; }
extern "C" {
void func_0012E460(void *);
int func_001A58D0(void *, void *, int);
void SetSoCnstrForce(void *, int);
void SetSoNoXpsAll(void *, int);
float *PeaFindAsegLabel(void *, int);
void PredictXfTransform(int, int, QW *, int, float);
void ConvertAloMat(QW *, void *, int, QW *);
void func_001B72B0(void *, int, void *, QW *, QW *);
int FIsBasicDerivedFrom(void *, int);
void PostGuardStunCommand(void *, void *);
void CalcMurrayThrow(void *, QW, float *, float *, QW *, QW *);
int func_0012DE58(void *, void *, int, QW, QW, float);
QW ConvertXfVec(int, int, QW);
int func_0012DC18(void *, void *, int, int, int, QW);
int func_0012DD28(void *, int, int, void *);
int func_0012DDB0(void *, int, int, int, int, QW *);
void func_00209E88(void *);
void DetachMurrayObject(void *);
void SetMurrayState(void *, int);
extern float RO_002C0A3C, RO_002C0A40;
extern QW RO_002A2D30;
extern float g_2dded0;
void SetMurrayLiftState(MURRAY *self, int state)
{
    if (self->state == state) return;
    if (self->state == 1) {
        func_0012E460(&self->f13FC);
        func_0012E460(&self->f1400);
    }
    self->state = state;
    self->stateTime = Now(&g_2dded0);
    QW sp[8];
    float t;
    switch (state) {
    case 0:
        self->f1448 = 0;
        break;
    case 1: {
        SOB *so;
        if (self->pcarry && (so = self->pcarry->so, ((int)(so->flags >> 60) & 1))) {
            SetSoCnstrForce(so, 0);
            self->f1404 = so->xf58->flags98;
            self->f1408 = so->xf5C->flags98;
            func_001A58D0(so, 0, 0xF);
            SetSoNoXpsAll(so, 1);
            float *label = PeaFindAsegLabel(self->peah->aseg, 0x1C7);
            t = (*label - self->peah->time) / self->peah->dur;
            PredictXfTransform(self->pheld->xf, self->xf60, sp, 0, t);
            ConvertAloMat(&sp[4], self, 0, sp);
            sp[0] = sp[4]; sp[1] = sp[5]; sp[2] = sp[6]; sp[3] = sp[7];
            func_001B72B0(self, 0, sp, &sp[4], &sp[5]);
            if (FIsBasicDerivedFrom(so, 0x38)) PostGuardStunCommand(so, self);
            CalcMurrayThrow(self, sp[5], label, &t, &sp[6], &sp[7]);
            self->f13FC = func_0012DE58(so, so->xf58, 5, sp[5], sp[7], Now(&g_2dded0) + t);
            VTE *vte = &so->vt->setXf;
            void *obj = (char *)so + vte->delta;
            ((void (*)(void *, QW))vte->fn)(obj, ConvertXfVec(so->xf58->xfA0, 0, sp[6]));
            self->f1400 = func_0012DC18(so, so->xf5C, 5, 7, 2, sp[4]);
        } else {
            goto detach;
        }
        break;
    }
    case 2: {
        SOB *so;
        if (self->pcarry == 0 || (so = self->pcarry->so, ((int)(so->flags >> 60) & 1) == 0)) {
detach:
            DetachMurrayObject(self);
            self->pcarry = 0;
            SetMurrayState(self, 0);
        } else {
            void *held = self->pheld;
            func_001A58D0(so, held, 0xF);
            SetSoNoXpsAll(so, 1);
            func_001B72B0(self, ((int *)held)[0x60 / 4], &RO_002A2D30, &sp[1], &sp[0]);
            self->f13F8 = func_0012DC18(so, so->xf5C, 5, 7, 2, sp[1]);
            self->f13F4 = func_0012DC18(so, so->xf58, 5, 7, 2, sp[0]);
            BASIC *a190 = self->pcarry->a190;
            if (a190) {
                REFB *ref = self->pref1610;
                VTE *vte = &a190->vt->getRef;
                ref->id = ((int (*)(void *, QW *))vte->fn)((char *)a190 + vte->delta, &sp[2]);
                ref->q = sp[5];
                ref->f = RO_002C0A3C;
                self->f1618 = func_0012DD28(self, ref->a, 5, ref);
                self->f161C = func_0012DD28(self, ref->b, 5, ref);
                self->f1604 = func_0012DDB0(self, self->f15F4, 5, 5, ref->id, &sp[2]);
            }
            BASIC *a198 = self->pcarry->a198;
            if (a198) {
                REFB *ref = self->pref1614;
                VTE *vte = &a198->vt->getRef;
                ref->id = ((int (*)(void *, QW *))vte->fn)((char *)a198 + vte->delta, &sp[2]);
                ref->q = sp[5];
                ref->f = RO_002C0A40;
                self->f1620 = func_0012DD28(self, ref->a, 5, ref);
                self->f1624 = func_0012DD28(self, ref->b, 5, ref);
                self->f160C = func_0012DDB0(self, self->f15FC, 5, 5, ref->id, &sp[2]);
            }
            if (FIsBasicDerivedFrom(so, 0x38)) func_00209E88(so);
            int *clear = (int *)((char *)self + 0x190);
            clear[2] = 0;
            clear[1] = 0;
            *(int *)((char *)self + 0x190) = 0;
        }
        break;
    }
    }
    if (self->state < 2) {
        if (self->state >= 0) {
            self->pgadget->flag = 1;
            return;
        }
    }
    self->pgadget->flag = 0;
}
}
