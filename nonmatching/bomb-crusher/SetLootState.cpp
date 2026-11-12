// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "sly2.h"
#include "jt.h"
#include "sw.h"

/* the loot definition a loot object points at (0x158) */
struct LOOTDEF {
    u8 unknown_0x0[0xC];
    /* 0xC */ s32 fCountdown;
    u8 unknown_0x10[0x8];
    /* 0x18 */ s32 istg;
    /* 0x1C */ s32 cswitch;
    /* 0x20 */ s32 aswitch[1];
};

/* the object that holds the loot while it waits (0x15C) */
struct LOOTHOLDER : SO {
    u8 unknown_0x150[0x3C];
    /* 0x18C */ f32 tCountdown;
    u8 unknown_0x190[0x4];
    /* 0x194 */ struct LOOT *ploot;
    /* 0x198 */ u8 hitfx[0x10];
};

/* the message posted to the claimer (0x164) */
struct LOOTMSG {
    s32 kind;
    SO *pso;
};

struct RIPGBASE {
    u8 unknown_0x0[0x18];
    /* 0x18 */ f32 dtFlight;
    /* 0x1C */ LO *ploTarget;
    u8 unknown_0x20[0x80];
    /* 0xA0 */ f32 vel[3];
    u8 unknown_0xAC[0x40];
    /* 0xEC: the vtable pointer */
    virtual void Launch(QW pos, int grf, float g);
};

struct MATCH : RIPGBASE {
    u8 unknown_0xF0[0x14];
    /* 0x104 */ LO *ploSource;
};

struct LOOT : SO {
    u8 unknown_0x150[0x8];
    /* 0x158 */ LOOTDEF *plootdef;
    /* 0x15C */ LOOTHOLDER *pholder;
    /* 0x160 */ JT *pjt;
    /* 0x164 */ SO *psoClaim;
    u8 unknown_0x168[0x18];
    /* 0x180 */ f32 dtBlend;
    /* 0x184 */ s32 state;
    /* 0x188 */ f32 tState;
    /* 0x18C */ MATCH *pmatch;
};

static inline SO *PsoJtCarry(JT *pjt)
{
    return *(SO **)pjt->unknown_0x11A4;
}

struct CLOCK {
    f32 t;
    f32 dt;
};

extern SW B_003DD490;
extern char B_002DEB30;
extern "C" {
extern CLOCK g_2dded0;
extern QW g_2a2dd0;
extern const QW RO_002A4B60;
void LockLeaseOfPlo(void *ppool, LOOT *ploot);
void UnlockLeaseOfPlo(void *ppool, LOOT *ploot);
void func_001F6A68(LOOT *ploot);
void func_001F6978(LOOT *ploot, s32 iswitch);
void func_001F2AD0(LOOT *ploot, void *pgeom);
void func_001F6AC8(LOOT *ploot, s32 istg);
void func_001F6B48(LOOT *ploot, s32 istg);
void ShowCountdownBlot(SW *psw, float t);
void HideCountdownBlot(SW *psw);
QW PosLoWorld(void *plo);
void ReplaceSwHitFx(SW *psw, int n, QW pos, LO *plo, void *phitfx);
void bevy_camera_follow_activity(void *pact, int kind, LOOT *ploot);
void SetSoCnstrForce(LOOT *ploot, int f);
void SetSoCnstrTorque(LOOT *ploot, int f);
void SetSoDvGravity(LOOT *ploot, QW dv);
void func_001A58D0(LOOT *ploot, void *pv, int grf);
void SetLoPosMat(LOOT *ploot, MATRIX4 *pmat);
void FadeAloIn(LOOT *ploot, float dt);
MATCH *PripNewRipg(SW *psw, int kind, int grf);
void SubscribeRipObject(MATCH *pmatch, LOOT *ploot);
float GRandInRange(float min, float max);
void SetLootState(LOOT *ploot, int state);
}
void LaunchMatch(MATCH *pmatch);

static inline float GMaxF(float g1, float g2)
{
    return g1 > g2 ? g1 : g2;
}

static inline float SDistance(QW pos, QW posOther)
{
    return LaneX(SqrtX(SquaredLength(VectorSub(pos, posOther))));
}

extern "C" void SetLootState(LOOT *ploot, int state)
{
    if (ploot->state == state)
        return;
    if (B_003DD490.ppool != 0) {
        int fLeasedOld = ploot->state >= 2;
        int fLeasedNew = state >= 2;
        if (fLeasedOld) {
            if (!fLeasedNew)
                UnlockLeaseOfPlo(B_003DD490.ppool, ploot);
        } else if (fLeasedNew) {
            LockLeaseOfPlo(B_003DD490.ppool, ploot);
        }
    }
    VECTOR vel;
    VECTOR dw;
    VECTOR scale;
    int stateOld = ploot->state;
    JT *pjt = ploot->pjt;
    switch (stateOld) {
    case -1:
    default:
        break;
    case 0:
        func_001F6A68(ploot);
        for (int iswitch = 0; iswitch < ploot->plootdef->cswitch; iswitch++)
            func_001F6978(ploot, ploot->plootdef->aswitch[iswitch]);
        for (int igeom = 0; igeom < ploot->cgeom; igeom++)
            func_001F2AD0(ploot, (char *)ploot->ageom + igeom * 0xB0);
        if (ploot->plootdef->istg != -1)
            func_001F6AC8(ploot, ploot->plootdef->istg);
        break;
    case 1:
        if (ploot->plootdef->fCountdown)
            ShowCountdownBlot(&B_003DD490, ploot->pholder->tCountdown + 0.99f);
        ReplaceSwHitFx(&B_003DD490, 1, PosLoWorld(ploot->pholder), ploot->pholder, ploot->pholder->hitfx);
        if (state == 2)
            bevy_camera_follow_activity(&B_002DEB30, 0x2F, ploot);
        ploot->pholder->ploot = 0;
        ploot->pholder = 0;
        ploot->HandleSpliceEvent(5, 0, 0, 0, 0);
        break;
    case 2:
        ploot->pmatch = 0;
        if (state == 4)
            ploot->dtBlend = 0.3f;
        break;
    case 3:
        ploot->pmatch = 0;
        break;
    case 4: {
        JT *pjtHeld = ploot->pjt;
        ploot->pjt = 0;
        PsoJtCarry(pjtHeld)->Remove();
        pjtHeld->plootHeld = 0;
        if (ploot->plootdef->istg != -1)
            func_001F6AC8(ploot, ploot->plootdef->istg);
        if (ploot->plootdef->fCountdown)
            HideCountdownBlot(&B_003DD490);
        break;
    }
    case 5: {
        if (ploot->psoClaim) {
            LOOTMSG msg;
            msg.kind = 1;
            msg.pso = ploot->psoClaim;
            struct VT { u8 unknown_0x0[0x198]; s16 delta; s16 index; void (*pfn)(void *, LOOTMSG *); };
            VT *pvt = *(VT **)((char *)ploot->psoClaim + 0xC);
            pvt->pfn((char *)ploot->psoClaim + pvt->delta, &msg);
        }
        SetSoCnstrForce(ploot, 1);
        SetSoCnstrTorque(ploot, 1);
        ploot->Slot35(g_2a2dd0);
        ploot->Slot36(g_2a2dd0);
        SetSoDvGravity(ploot, g_2a2dd0);
        break;
    }
    case 6:
        ploot->dtBlend = 0.0f;
        break;
    }
    ploot->state = state;
    ploot->tState = g_2dded0.t;
    switch (state) {
    case 0:
        ploot->plootdef = 0;
        func_001A58D0(ploot, 0, 0);
        ploot->Remove();
        break;
    case 1:
        ReplaceSwHitFx(&B_003DD490, -1, g_2a2dd0, 0, ploot->pholder->hitfx);
        SetLoPosMat(ploot, ploot->pholder->PmatWorld());
        func_001A58D0(ploot, ploot->pholder->psoParent, 3);
        ploot->pholder->ploot = ploot;
        if (stateOld != 3) {
            ploot->Remove();
            FadeAloIn(ploot, 0.5f);
        }
        ploot->HandleSpliceEvent(6, 0, 0, 0, 0);
        break;
    case 2:
    case 6:
        PsoJtCarry(ploot->pjt)->Add();
        if (ploot->state == 2) {
            ploot->pmatch = PripNewRipg(&B_003DD490, 6, 0);
        } else {
            ploot->pmatch = 0;
            ploot->HandleSpliceEvent(6, 0, 0, 0, 0);
            ploot->HandleSpliceEvent(5, 0, 0, 0, 0);
        }
        if (ploot->pmatch) {
            ploot->pmatch->Launch(PosLoWorld(ploot), 0, 1.0f);
            SubscribeRipObject(ploot->pmatch, ploot);
            float s = SDistance(PosLoWorld(ploot), PosLoWorld(PsoJtCarry(ploot->pjt)));
            ploot->pmatch->ploTarget = PsoJtCarry(ploot->pjt);
            ploot->pmatch->dtFlight = GMaxF(s, 250.0f) * 0.002f;
            f32 *pvel = ploot->pmatch->vel;
            pvel[0] = 0.0f;
            pvel[2] = -3000.0f;
            pvel[1] = 0.0f;
            ploot->pmatch->ploSource = ploot;
            LaunchMatch(ploot->pmatch);
            ploot->Add();
        }
        SetLoPosMat(ploot, PsoJtCarry(ploot->pjt)->PmatWorld());
        func_001A58D0(ploot, PsoJtCarry(ploot->pjt), 3);
        if (ploot->pmatch == 0)
            SetLootState(ploot, 4);
        break;
    case 3:
        SetLoPosMat(ploot, ploot->pholder->PmatWorld());
        func_001A58D0(ploot, ploot->pholder->psoParent, 3);
        ploot->pmatch = PripNewRipg(&B_003DD490, 6, 0);
        if (ploot->pmatch) {
            ploot->pmatch->Launch(PosLoWorld(PsoJtCarry(pjt)), 0, 1.0f);
            SubscribeRipObject(ploot->pmatch, ploot);
            float s = SDistance(PosLoWorld(PsoJtCarry(pjt)), PosLoWorld(ploot));
            ploot->pmatch->ploTarget = ploot;
            ploot->pmatch->dtFlight = GMaxF(s, 250.0f) * 0.002f;
            f32 *pvel = ploot->pmatch->vel;
            pvel[0] = 0.0f;
            pvel[2] = -3000.0f;
            pvel[1] = 0.0f;
            ploot->pmatch->ploSource = PsoJtCarry(pjt);
            LaunchMatch(ploot->pmatch);
            ploot->Add();
            if (ploot->pmatch)
                break;
        }
        SetLootState(ploot, 1);
        break;
    case 4:
        ploot->pjt->plootHeld = ploot;
        if (ploot->plootdef->istg != -1)
            func_001F6B48(ploot, ploot->plootdef->istg);
        break;
    case 5: {
        func_001A58D0(ploot, 0, 3);
        SetSoCnstrForce(ploot, 0);
        SetSoCnstrTorque(ploot, 0);
        QW row = ploot->PmatWorld()->row[0];
        *(QW *)&scale = VectorFromFloat(1000.0f);
        *(QW *)&vel = VectorScaleX(row, *(QW *)&scale);
        ploot->Slot35(*(QW *)&vel);
        float dx = GRandInRange(-6.2831855f, 6.2831855f);
        float dy = GRandInRange(-6.2831855f, 6.2831855f);
        float dz = GRandInRange(-6.2831855f, 6.2831855f);
        dw.x = dx;
        dw.y = dy;
        dw.z = dz;
        ploot->Slot36(*(QW *)&dw);
        SetSoDvGravity(ploot, RO_002A4B60);
        bevy_camera_follow_activity(&B_002DEB30, 0x30, ploot);
        break;
    }
    }
}
