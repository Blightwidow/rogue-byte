#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
struct JT { char pad[0x1000]; unsigned grfTargetMask; };
struct LOB { char pad[0xE0]; unsigned flags; };
struct CARRY {
    JT *pjt; char pad0[4]; float w0; char pad1[0x1C - 0xC]; float w1; char pad2[0x30 - 0x20];
    void *pasegbl; char pad3[4]; void *pxfBase; char pad4[0x80 - 0x3C];
    void *pactLook; LOB *ploTargetGiven; float sPath; LOB *ploTarget; int nKind;
    void *pactGoalPos; char pad5[4]; void *pactGoalRot; char pad6[4];
    int nState; float tState;
};
extern "C" {
void func_0012E460(void *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(void *);
void FindCrvClosestPointAll(void *, QW, void *, void *, void *, void *, float *);
LOB *func_001CCA40(JT *, LOB *);
QW GetXfDofValue(void *, void *);
void *func_0012DC18(JT *, void *, int, int, int, QW);
void ReblendAsegbl(void *);
void QueueSwCallbackOnce(void *, JT *, unsigned long, void *);
extern char B_003DD490[];
extern float g_2dded0;
extern const UL g_2a77c8;
}

void Carry_SetState(CARRY *carry, int state)
{
    if (state == carry->nState) return;
    if (carry->nState == 1) {
        func_0012E460(&carry->pactGoalPos);
        func_0012E460(&carry->pactGoalRot);
    }
    carry->nState = state;
    carry->tState = g_2dded0;
    switch (state) {
    case -1:
        func_0012E460(&carry->pactLook);
        carry->nKind = state;
        carry->ploTarget = 0;
        carry->ploTargetGiven = 0;
        carry->sPath = 0.0f;
        break;
    case 0:
    case 1: {
        LOB *given = carry->ploTargetGiven;
        carry->nKind = 1;
        carry->ploTarget = given;
        if (FIsBasicDerivedFrom(given, 10)) {
            QW pos = PosLoWorld(carry->pjt);
            FindCrvClosestPointAll(carry->ploTargetGiven, pos, 0, 0, 0, 0, &carry->sPath);
            carry->nKind = 0;
        } else if (FIsBasicDerivedFrom(carry->ploTargetGiven, 0x14) && (carry->ploTargetGiven->flags & carry->pjt->grfTargetMask)) {
            carry->nKind = 2;
        } else if (FIsBasicDerivedFrom(carry->ploTargetGiven, 0x30)) {
            LOB *anchor = func_001CCA40(carry->pjt, carry->ploTargetGiven);
            if (anchor) {
                carry->ploTarget = anchor;
                carry->nKind = 2;
            }
        }
        if (carry->nKind == 2) {
            QW dof = GetXfDofValue(carry->pxfBase, carry->pxfBase);
            carry->pactLook = func_0012DC18(carry->pjt, carry->pxfBase, 5, 7, 3, dof);
        }
        carry->w1 = 0.5f;
        carry->w0 = 0.5f;
        ReblendAsegbl(carry->pasegbl);
        QueueSwCallbackOnce(B_003DD490, carry->pjt, g_2a77c8.v, carry);
        break;
    }
    }
}
