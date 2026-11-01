#include "sly2.h"

struct VT_140F90 {
    char pad0[0x40];
    short deltaEnter; short indexEnter; void (*enter)(char *);
    short deltaExit; short indexExit; void (*exit)(char *);
    char pad50[0x118 - 0x50];
    short deltaPush; short indexPush; void (*push)(char *, QW);
};
struct OBJ_140F90 { char pad0[0xC]; VT_140F90 *vt; };
struct ENTRY_140F90 { OBJ_140F90 *obj; int active; };
struct SENDER_140F90 { char pad0[0x18]; char *owner; };
struct MSG_140F90 { SENDER_140F90 *sender; float speed; int kind; };
struct LINK_140F90 { void *data; char *owner; };
struct ASEGL_140F90 { char pad0[0x30]; void *asega; };
struct HITFX_140F90 { char pad0[0x44]; char *owner; char pad48[0xC]; int kind; };
struct DL_140F90 { HITFX_140F90 *first; HITFX_140F90 *last; int offset; };
struct DLI_140F90 { DL_140F90 *list; char *current; int offset; DLI_140F90 *next; };

struct JT_140F90 {
    char pad0[0xC];
    VT_140F90 *vt;
    char pad10[0x190 - 0x10];
    QW vel;
    char pad1A0[0x10];
    QW mat[3];
    char pad1E0[0x26C - 0x1E0];
    char goals[0x4C8 - 0x26C];
    int carryKind;
    char pad4CC[8];
    void *carried;
    char pad4D8[0x900 - 0x4D8];
    char carry[0x9BC - 0x900];
    int gadget;
    char pad9C0[0xDF0 - 0x9C0];
    char zap[4];
    int zapState;
    char padDF8[0x1030 - 0xDF8];
    void *asega;
    ASEGL_140F90 *link;
    int unk1038;
    char pad103C[8];
    int unk1044;
    char pad1048[0x1060 - 0x1048];
    QW target;
    QW offset;
    char pad1080[0x108C - 0x1080];
    void *grab;
    ENTRY_140F90 *entries;
    int centries;
    char pad1098[0x11B0 - 0x1098];
    char carryThrow[4];
    int throwState;
    char pad11B8[0x130C - 0x11B8];
    void *gadgetAseg;
    char handle[4];
    int handleGadget;
};

extern "C" {
void ZapContinue(void *);
void CarryThrow_SetState(void *, int);
void CarryThrow_Launch(void *);
QW func_00204E38(JT_140F90 *, SENDER_140F90 *, float);
QW PosLoWorld(void *);
int FIsBasicDerivedFrom(void *, int);
int FGadgetObjActive(void *);
void ReleaseGadgetObj(void *);
void RetractAsegaHandle(void *);
void SpendJtGadgetPower(JT_140F90 *, int);
void ApplyAsegToHandle(void *, void *, float, float, int, void *);
void SetSwGuardsFrozen(void *, int);
void SetSwGuardsMode(void *, int);
void *PloLeaseCloneObject(void *, int);
void func_001A58D0(void *, int, int);
void HitFx_Remove(HITFX_140F90 *);
void func_001CCC88(void *, void *);
void SetAsegaSpeed(void *, float);
void Carry_Attach(void *, void *);
void UnsubscribeLoObject(void *, void *);
void GoalStack_HandleMessage(void *, int, void *);
void HandlePoMessage(void *, int, void *);
extern char B_003DD490[];
extern DL_140F90 B_003E148C;
extern char *g_2e1e40;
extern DLI_140F90 *g_2dd2fc;
extern float g_2dded0;
extern float g_2bcc94;
}

static inline void PushDli_140F90(DLI_140F90 *it, DL_140F90 *list)
{
    it->list = list;
    it->current = (char *)list;
    it->offset = list->offset;
    it->next = g_2dd2fc;
    g_2dd2fc = it;
}
static inline HITFX_140F90 *PvFirst_140F90(DLI_140F90 *it)
{
    HITFX_140F90 *item = it->list->first;
    it->current = (char *)item + it->offset;
    return item;
}
static inline HITFX_140F90 *PvStep_140F90(DLI_140F90 *it)
{
    HITFX_140F90 *item = *(HITFX_140F90 **)it->current;
    it->current = (char *)item + it->offset;
    return item;
}
static inline void PopDli_140F90(DLI_140F90 *it) { g_2dd2fc = it->next; }

static inline void RemoveJtHitFx_140F90(JT_140F90 *jt)
{
    DLI_140F90 iterator;
    PushDli_140F90(&iterator, &B_003E148C);
    for (HITFX_140F90 *fx = PvFirst_140F90(&iterator); fx != 0; fx = PvStep_140F90(&iterator)) {
        if (fx->kind == 4 && fx->owner == (char *)jt)
            HitFx_Remove(fx);
    }
    PopDli_140F90(&iterator);
}

static inline void SetSwFloat_140F90(char *psw, float value)
{
    *(float *)(psw + 0x4758) = value;
}

static inline void PushJtVelocity_140F90(JT_140F90 *jt, QW vel)
{
    float scale = -1.0f;
    QW local;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(vel));
    QW *rows = jt->mat;
    asm volatile("lqc2 vf3, %0" : : "m"(jt->mat[0]));
    asm volatile("qmtc2.ni %0, vf5" : : "r"(scale));
    asm volatile("vmulx.xyzw vf1, vf4, vf5x");
    VT_140F90 *vt = jt->vt;
    asm volatile("sqc2 vf1, %0" : "=m"(jt->vel));
    short delta = vt->deltaPush;
    void (*push)(char *, QW) = vt->push;
    asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(rows));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(rows));
    char *self = (char *)jt + delta;
    asm volatile("vmulax.xyz ACC, vf3, vf4x");
    asm volatile("vmadday.xyz ACC, vf1, vf4y");
    asm volatile("vmaddz.xyz vf6, vf2, vf4z");
    asm volatile("qmfc2.ni %0, vf6" : "=r"(local));
    asm volatile("sqc2 vf5, 0($sp)");
    push(self, local);
}

extern "C" void HandleJtMessage(JT_140F90 *jt, int msg, void *pv)
{
    switch (msg) {
    case 3:
        if (pv == jt->asega || (jt->link != 0 && pv == jt->link->asega)) {
            jt->unk1038 = -1;
            if (jt->zapState >= 8 && jt->zapState <= 12) {
                ZapContinue(jt->zap);
            } else {
                switch (jt->throwState) {
                case 5:
                case 6:
                    CarryThrow_SetState(jt->carryThrow, 4);
                    break;
                case 1:
                case 2:
                    CarryThrow_SetState(jt->carryThrow, 0);
                    break;
                }
            }
        }
        break;
    case 9: {
        MSG_140F90 *pmsg = (MSG_140F90 *)pv;
        SENDER_140F90 *sender = pmsg->sender;
        if (sender->owner != (char *)jt)
            break;
        switch (pmsg->kind) {
        case 0x15E: {
            PushJtVelocity_140F90(jt, func_00204E38(jt, sender, pmsg->speed));
            break;
        }
        case 0x161:
            jt->unk1044 = 1;
            break;
        case 0x162: {
            jt->unk1044 = 0;
            QW target = jt->target;
            QW pos = PosLoWorld(jt);
            asm("lqc2 vf2, %0" : : "m"(target));
            asm("qmtc2.ni %0, vf3" : : "r"(pos));
            asm("vsub.xyzw vf1, vf2, vf3");
            asm("sqc2 vf1, %0" : "=m"(jt->offset));
            ((float *)&jt->offset)[2] = 0.0f;
            break;
        }
        case 0x27B:
            if (jt->throwState != -1)
                CarryThrow_Launch(jt->carryThrow);
            break;
        case 0x27C:
            if (jt->carryKind != 0xB)
                break;
            if (jt->carried != 0 && FIsBasicDerivedFrom(jt->carried, 0x64)) {
                void *gadgetObj = jt->carried;
                if (FGadgetObjActive(gadgetObj))
                    ReleaseGadgetObj(gadgetObj);
            }
            if (jt->gadgetAseg != 0) {
                if (jt->handleGadget == jt->gadget) {
                    RetractAsegaHandle(jt->handle);
                    jt->handleGadget = -1;
                } else {
                    SpendJtGadgetPower(jt, jt->gadget);
                    ApplyAsegToHandle(jt->gadgetAseg, jt, 0.0f, 1.0f, 8, jt->handle);
                    jt->handleGadget = jt->gadget;
                }
            } else if (jt->gadget != -1) {
                SpendJtGadgetPower(jt, jt->gadget);
                switch (jt->gadget) {
                case 14:
                    SetSwGuardsFrozen(B_003DD490, 1);
                    break;
                case 21:
                    SetSwGuardsMode(B_003DD490, 0x15);
                    break;
                case 23: {
                    void *clone = PloLeaseCloneObject(*(void **)(g_2e1e40 + 0x2010), 0);
                    if (clone != 0)
                        func_001A58D0(clone, 0, 3);
                    RemoveJtHitFx_140F90(jt);
                    SetSwFloat_140F90(B_003DD490, g_2dded0 + g_2bcc94);
                    break;
                }
                }
            }
            jt->gadgetAseg = 0;
            jt->gadget = -1;
            break;
        case 0x1C8:
            if (jt->carryKind == 0xC)
                func_001CCC88(jt->carry, jt->carried);
            break;
        case 0x1C7:
            if (jt->carryKind == 0xC) {
                SetAsegaSpeed(jt->asega, 1.0f);
                Carry_Attach(jt->carry, jt->carried);
            }
            break;
        }
        break;
    }
    case 4: {
        LINK_140F90 *plink = (LINK_140F90 *)pv;
        if (plink->owner == (char *)jt) {
            jt->grab = plink->data;
            for (int ientry = 0; ientry < jt->centries; ientry++) {
                OBJ_140F90 *obj = jt->entries[ientry].obj;
                obj->vt->enter((char *)obj + obj->vt->deltaEnter);
                jt->entries[ientry].active = 0;
            }
        }
        break;
    }
    case 5: {
        LINK_140F90 *plink = (LINK_140F90 *)pv;
        if (plink->owner == (char *)jt && plink->data == jt->grab) {
            jt->grab = 0;
            for (int ientry = 0; ientry < jt->centries; ientry++) {
                OBJ_140F90 *obj = jt->entries[ientry].obj;
                obj->vt->exit((char *)obj + obj->vt->deltaExit);
            }
        }
        break;
    }
    case 1:
        if (jt->carryKind == 0xB && jt->carried == pv) {
            UnsubscribeLoObject(pv, jt);
            jt->carried = 0;
        }
        break;
    case 11:
        if (((LINK_140F90 *)pv)->owner == (char *)jt) {
            RetractAsegaHandle(jt->handle);
            jt->handleGadget = -1;
        }
        break;
    }
    GoalStack_HandleMessage(jt->goals, msg, pv);
    HandlePoMessage(jt, msg, pv);
}
