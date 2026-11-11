#include "types.h"
#include "vu0inline.h"
#include "po.h"
struct CLIPEDGE { char data[0x180]; };
struct OBJ : PO {
    char pad180[0x240 - 0x180];
    QW offset;
    char pad250[0x11AC - 0x250];
    int field11AC;
};
struct NODE { int hit; NODE *next; char pad8[4]; OBJ *pobj; };
struct SENSORSET { char pad[0x64]; NODE *pnodes; };
struct BSP { char pad[0xEC]; void *pclip; char pad0xf0[0x130 - 0xF0]; BSP *pnext; };
struct SENSOR {
    char pad0[0xE4];
    SENSORSET *pset;
    void *pvolume;
    void *pvolumeExtra;
    int fForce;
    int fSuppress;
    unsigned flags;
};
extern "C" {
void *PpoSwFocusBase(void *);
int FSwBinocActive(void *);
int FIsLoInWorld(OBJ *);
int FIsBasicDerivedFrom(void *, int);
QW PosLoWorld(OBJ *);
QW func_00153E60(SENSOR *);
QW ConvertAloPos(void *, BSP *, QW);
int ClsgClipEdgeToBsp(void *, int, QW, QW, int, CLIPEDGE *);
int func_00227C90(void *, QW);
int func_00154770(SENSOR *, OBJ *);
int FSensorSightBlocked(SENSOR *, OBJ *);
extern char B_003DD490;
extern BSP *B_003E1480;
}

extern "C" int NNextSensorState(SENSOR *psensor, OBJ *pobj, int state)
{
    CLIPEDGE clip;
    void *pfocus = PpoSwFocusBase(&B_003DD490);
    if (pobj == 0 || !FIsLoInWorld(pobj)) {
        state = 0;
    } else if (FIsBasicDerivedFrom(pobj, 0x32) && pobj->NAlertLevel() == 2) {
        state = 0;
    } else if (FIsBasicDerivedFrom(pobj, 0x34) && pfocus && FIsBasicDerivedFrom(pfocus, 0x46)) {
        state = 0;
    } else if (FSwBinocActive(&B_003DD490)) {
        state = 0;
    } else if (psensor->fSuppress) {
        state = 0;
    } else if (FIsBasicDerivedFrom(pobj, 0x34) && pobj->field11AC) {
        state = 0;
    } else if (psensor->fForce) {
        state = 1;
    } else {
        QW pos;
        if (FIsBasicDerivedFrom(pobj, 0x33))
            pos = VectorAdd(PosLoWorld(pobj), pobj->offset);
        else
            pos = PosLoWorld(pobj);
        for (BSP *pbsp = B_003E1480; pbsp; pbsp = pbsp->pnext) {
            QW from = ConvertAloPos(0, pbsp, func_00153E60(psensor));
            QW to = ConvertAloPos(0, pbsp, pos);
            if (ClsgClipEdgeToBsp(pbsp->pclip, 0x7FFFFFFF, from, to, 4, &clip) > 0) {
                state = 0;
                goto done;
            }
        }
        switch (state) {
        case 0: {
            SENSORSET *pset = psensor->pset;
            if (pset) {
                for (NODE *pnode = pset->pnodes; pnode; pnode = pnode->next) {
                    if (pnode->pobj == pobj) {
                        if (pnode->hit) {
                            state = 1;
                            goto done;
                        }
                        break;
                    }
                }
            }
            if (!func_00227C90(psensor->pvolume, pos)) {
                state = 0;
            } else if (psensor->pvolumeExtra && !func_00227C90(psensor->pvolumeExtra, pos)) {
                state = 0;
            } else if ((psensor->flags & 1) || !func_00154770(psensor, pobj)) {
                state = 1;
                if (!(psensor->flags & 2))
                    state = FSensorSightBlocked(psensor, pobj) == 0;
            } else {
                state = 0;
            }
            break;
        }
        case 1:
            if (psensor->pvolumeExtra && !func_00227C90(psensor->pvolumeExtra, pos)) {
                state = 0;
            } else if (!func_00227C90(psensor->pvolume, pos)) {
                state = 2;
            } else if (psensor->flags & 8) {
                if (FSensorSightBlocked(psensor, pobj))
                    state = 0;
            }
            break;
        case 2:
            if (psensor->pvolumeExtra && !func_00227C90(psensor->pvolumeExtra, pos)) {
                state = 0;
            } else if (func_00227C90(psensor->pvolume, pos)) {
                if ((psensor->flags & 2) || !FSensorSightBlocked(psensor, pobj))
                    state = 1;
            } else if (psensor->flags & 8) {
                if (FSensorSightBlocked(psensor, pobj))
                    state = 0;
            }
            break;
        }
    }
done:
    return state;
}
