#include "sly2.h"
struct NOTICE { int a; void *b; char pad[0x38]; };
struct OVT { char pad[0x198]; short d198; short i198; void (*f198)(void *, NOTICE *); };
struct OWN { char pad[0xC]; OVT *vt; };
struct BVT {
    char pad[0x18]; short d18; short i18; void (*f18)(void *, int, int, int, int, int);
};
struct PVT { char pad[0x48]; short d48; short i48; void (*f48)(void *); };
struct POOLO { char pad[0xC]; PVT *vt; char pad2[0x100 - 0x10]; int idClue; };
struct BOTTLE { char pad[0xC]; BVT *vt; char pad2[0x150 - 0x10]; int state; char pad3[0x210 - 0x154]; OWN *owner; };
extern "C" {
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, void *);
QW PosLoWorld(BOTTLE *);
void SpawnSwHitFx(void *, int, QW, void *);
POOLO *PpoolFromLoClone(BOTTLE *);
int FIsBasicDerivedFrom(POOLO *, int);
void SetClueFound(int, int);
void ShowClueBlot(void *);
void SetDprizeDprizes(BOTTLE *, int);
extern char B_003DD490[];
}
void SetCluebottleState(BOTTLE *pbottle, int state)
{
    if (state == pbottle->state)
        return;
    if (state == 1) {
        OWN *owner = pbottle->owner;
        if (owner != 0) {
            NOTICE notice;
            notice.a = state;
            notice.b = pbottle;
            owner->vt->f198((char *)owner + owner->vt->d198, &notice);
        } else {
            SetEmitterUnpositioned(NewEmitter(0x29), 0);
        }
        state = 2;
        char *sw = B_003DD490;
        QW pos = PosLoWorld(pbottle);
        SpawnSwHitFx(sw, 0, pos, pbottle);
        pbottle->vt->f18((char *)pbottle + pbottle->vt->d18, 5, 0, 0, 0, 0);
        POOLO *ppool = PpoolFromLoClone(pbottle);
        if (ppool != 0 && FIsBasicDerivedFrom(ppool, 7) != 0) {
            POOLO *pclue = PpoolFromLoClone(pbottle);
            SetClueFound(pclue->idClue, 1);
            pclue->vt->f48((char *)pclue + pclue->vt->d48);
            ShowClueBlot(sw);
        }
    }
    SetDprizeDprizes(pbottle, state);
}
