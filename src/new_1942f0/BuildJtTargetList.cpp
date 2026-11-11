// SPDX-License-Identifier: GPL-3.0-or-later
#include "ps2inline.h"
#include "vu0inline.h"
#include "jt.h"


/* a candidate of the player's target list (0x30 bytes); the world keeps four (from 0x4680) */
struct TGT {
    LO *plo;
    struct TGTDEF { u8 unknown_0x0[0x14]; s32 idLabel; } *ptgtdef;
    f32 sRank;
    s32 iRank;
    LO *ploClone;
    f32 tShown;
    u8 unknown_0x18[0x8];
    QW pos;
};

/* the target interface of a targetable object: InsertTargetCandidate reads 0x18 and 0x1C; the list link follows at 0x24 */
struct TARGET {
    u8 unknown_0x0[0x24];
    DLE dleTarget;
};

/* the classes before TARGET in each object (the casts retail makes put TARGET at 0x190, 0xE0, 0x130) */
struct BASE190 { u8 unknown_0x0[0x190]; };
struct BASEE0 { u8 unknown_0x0[0xE0]; };
struct BASE130 { u8 unknown_0x0[0x130]; };
struct TGTOBJA : BASE190, TARGET { };
struct TGTOBJB : BASEE0, TARGET { };
struct TGTOBJC : BASE130, TARGET { };
struct TGTLOBASE : LO {
    u8 unknown_0x50[0x90];
    /* 0xE0 */ struct TGTLO *pnext;
    u8 unknown_0xE4[0x4];
    /* 0xE8 */ u32 grf;
    u8 unknown_0xEC[0x14];
};
struct TGTLO : TGTLOBASE, TARGET { };

struct SWTARGETS {
    u8 unknown_0x0[0x4678];
    /* 0x4678 */ s32 ctgt;
    u8 unknown_0x467C[0x4];
    /* 0x4680 */ TGT atgt[4];
    /* 0x4740 */ s32 idLabel;
};

struct HUD;
struct POOLO { u8 unknown_0x0[0x18]; s32 oid; };

extern SWTARGETS B_003DD490;
extern HUD B_003DA0C0;
extern DL B_003E13B4;
extern DL B_003E13C0;
extern DL B_003E13CC;
extern DL B_003E13D8;
extern DL B_003E13F0;
extern DL B_003E13FC;
extern DL B_003E1408;
extern DL B_003E1414;
extern DL B_003E1438;
extern f32 RO_002BF660;
extern f32 RO_002BF664;
extern f32 RO_002BF70C;

extern "C" {
int FIsPoSwFocusBase(JT *);
void *memset(void *, int, unsigned int);
QW PosLoWorld(JT *);
void InsertTargetCandidate(void *, JT *, QW, void *, TARGET *, int, TGT *);
int FIsBasicDerivedFrom(void *, int);
void EmitTargetSparkles(SWTARGETS *, JT *, int, TGT *);
void UpdateSwTargetList(SWTARGETS *, JT *, int, TGT *);
int func_001DA5B0(HUD *);
POOLO *PpoolFromLoClone(LO *);
void ClearHudLabel(HUD *, int);
void ShowHudLabel(float, HUD *, int);
}

static inline int FFarFrom(QW pos, QW posOther)
{
    return RO_002BF660 < LaneX(SqrtX(SquaredLength(VectorSub(pos, posOther))));
}

extern "C" void BuildJtTargetList(void *pv, JT *pjt, int grf)
{
    if (FIsPoSwFocusBase(pjt)) {
        TGT atgt[4];
        QW posJt;
        int ctgt;
        memset(atgt, 0, sizeof(atgt));
        for (unsigned int i = 0; i < 4; i++) {
            atgt[i].iRank = -1;
            atgt[i].sRank = RO_002BF664;
        }
        posJt = PosLoWorld(pjt);
        if (grf & 8) {
            for (TGTOBJA *p = (TGTOBJA *)B_003E13F0.head; p; p = (TGTOBJA *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 0x10) {
            for (TGTOBJB *p = (TGTOBJB *)B_003E13FC.head; p; p = (TGTOBJB *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 0x80) {
            for (TGTOBJB *p = (TGTOBJB *)B_003E1414.head; p; p = (TGTOBJB *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 4) {
            for (TGTOBJC *p = (TGTOBJC *)B_003E1438.head; p; p = (TGTOBJC *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 0x400) {
            for (TGTOBJB *p = (TGTOBJB *)B_003E13D8.head; p; p = (TGTOBJB *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 0x200) {
            for (TGTOBJA *p = (TGTOBJA *)B_003E13CC.head; p; p = (TGTOBJA *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 2) {
            for (TGTOBJA *p = (TGTOBJA *)B_003E13C0.head; p; p = (TGTOBJA *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 1) {
            for (TGTLO *p = (TGTLO *)B_003E13B4.head; p; p = p->pnext)
                if ((p->grf & 1) && FIsBasicDerivedFrom(p, 0x13))
                    InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        if (grf & 0x20) {
            for (TGTOBJB *p = (TGTOBJB *)B_003E1408.head; p; p = (TGTOBJB *)p->dleTarget.next)
                InsertTargetCandidate(pv, pjt, posJt, p, p, 4, atgt);
        }
        for (ctgt = 4; ctgt > 0 && atgt[ctgt - 1].plo == 0; ctgt--)
            ;
        EmitTargetSparkles(&B_003DD490, pjt, ctgt, atgt);
        UpdateSwTargetList(&B_003DD490, pjt, ctgt, atgt);
        int idCur = func_001DA5B0(&B_003DA0C0);
        if (idCur == -1 || idCur == B_003DD490.idLabel) {
            int idLabel;
            if (B_003DD490.ctgt == 0 || FFarFrom(posJt, B_003DD490.atgt[0].pos)) {
                idLabel = -1;
            } else {
                POOLO *ppool = 0;
                if (B_003DD490.atgt[0].ploClone)
                    ppool = PpoolFromLoClone(B_003DD490.atgt[0].ploClone);
                if (ppool && ppool->oid == 0x624 && RO_002BF70C < B_003DD490.atgt[0].tShown)
                    idLabel = 0x125;
                else
                    idLabel = B_003DD490.atgt[0].ptgtdef->idLabel;
            }
            if (idLabel != idCur) {
                if (idLabel == -1)
                    ClearHudLabel(&B_003DA0C0, B_003DD490.idLabel);
                else
                    ShowHudLabel(-1.0f, &B_003DA0C0, idLabel);
                B_003DD490.idLabel = idLabel;
            }
        }
    }
}
