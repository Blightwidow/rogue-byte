// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct EVT_12F590 { float t; int type; void *pv; void *pv2; };
struct EVDATA0_12F590 { int n0; int n1; int n2; int n3; float g4; float g5; float g6; };
struct EVDATA20_12F590 { int n0; int n1; float g; };
struct EVDATA17_12F590 { int n0; int n1; int n2; float g; };
extern "C" {
unsigned U8Read__18CBinaryInputStream(Bis *);
int S8Read__18CBinaryInputStream(Bis *);
int S16Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
float F32Read__18CBinaryInputStream(Bis *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocSwImpl__Fi(ALLOCREQ *);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
int func_00117FB0(Bis *, void *);
}
static inline void *PvAllocSwClear(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwClearImpl__Fi(&req);
}
static inline void *PvAllocSw(int cb)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwImpl__Fi(&req);
}
static inline void *PvAllocSwCopy(int cb, void *pv)
{
    ALLOCREQ req;
    req.cb = cb;
    req.cbAlign = 0x10;
    return PvAllocSwCopyImpl__FiPv(&req, pv);
}
static inline void *PvLoadEvdata0(Bis *pbis)
{
    EVDATA0_12F590 data;
    data.n0 = S16Read__18CBinaryInputStream(pbis);
    data.n1 = S32Read__18CBinaryInputStream(pbis);
    data.n2 = S32Read__18CBinaryInputStream(pbis);
    data.n3 = S32Read__18CBinaryInputStream(pbis);
    data.g6 = F32Read__18CBinaryInputStream(pbis);
    data.g4 = F32Read__18CBinaryInputStream(pbis);
    data.g5 = F32Read__18CBinaryInputStream(pbis);
    return PvAllocSwCopy(sizeof(data), &data);
}
static inline void *PvLoadEvdata20(Bis *pbis)
{
    EVDATA20_12F590 data;
    data.n0 = S32Read__18CBinaryInputStream(pbis);
    data.n1 = S32Read__18CBinaryInputStream(pbis);
    data.g = F32Read__18CBinaryInputStream(pbis);
    return PvAllocSwCopy(sizeof(data), &data);
}
extern "C" void LoadAsegEventsFromBrx(void *paseg, Bis *pbis, int fTime, int *pcevt, EVT_12F590 **paevt)
{
    int cevt = U8Read__18CBinaryInputStream(pbis);
    *pcevt = cevt;
    EVT_12F590 *aevt = (EVT_12F590 *)PvAllocSwClear(cevt * 0x10);
    *paevt = aevt;
    for (int ievt = 0; ievt < cevt; ievt++) {
        EVT_12F590 *pevt = &aevt[ievt];
        pevt->type = S8Read__18CBinaryInputStream(pbis);
        if (fTime)
            pevt->t = S16Read__18CBinaryInputStream(pbis) * (1.0f / 60.0f);
        switch (pevt->type) {
        case 0: {
            EVDATA0_12F590 data;
            data.n0 = S16Read__18CBinaryInputStream(pbis);
            data.n1 = S32Read__18CBinaryInputStream(pbis);
            data.n2 = S32Read__18CBinaryInputStream(pbis);
            data.n3 = S32Read__18CBinaryInputStream(pbis);
            data.g6 = F32Read__18CBinaryInputStream(pbis);
            data.g4 = F32Read__18CBinaryInputStream(pbis);
            data.g5 = F32Read__18CBinaryInputStream(pbis);
            pevt->pv = PvAllocSwCopy(sizeof(data), &data);
            break;
        }
        case 3:
            *(float *)&pevt->pv2 = S16Read__18CBinaryInputStream(pbis) * (1.0f / 60.0f);
            pevt->pv = (void *)S16Read__18CBinaryInputStream(pbis);
            break;
        case 5:
            *(float *)&pevt->pv = S16Read__18CBinaryInputStream(pbis) * (1.0f / 60.0f);
            *(float *)&pevt->pv2 = F32Read__18CBinaryInputStream(pbis);
            break;
        case 7:
        case 8:
            pevt->pv = (void *)S32Read__18CBinaryInputStream(pbis);
            *(float *)&pevt->pv2 = F32Read__18CBinaryInputStream(pbis);
            break;
        case 13:
        case 14:
        case 15:
        case 16:
            pevt->pv = (void *)S32Read__18CBinaryInputStream(pbis);
            pevt->pv2 = (void *)S32Read__18CBinaryInputStream(pbis);
            break;
        case 17:
            pevt->pv = PvAllocSwClear(0x10);
            ((EVDATA17_12F590 *)pevt->pv)->n0 = S32Read__18CBinaryInputStream(pbis);
            ((EVDATA17_12F590 *)pevt->pv)->n1 = S32Read__18CBinaryInputStream(pbis);
            ((EVDATA17_12F590 *)pevt->pv)->n2 = S32Read__18CBinaryInputStream(pbis);
            ((EVDATA17_12F590 *)pevt->pv)->g = F32Read__18CBinaryInputStream(pbis);
            break;
        case 20:
            pevt->pv = PvLoadEvdata20(pbis);
            break;
        case 1:
        case 2:
        case 21:
            pevt->pv = (void *)S16Read__18CBinaryInputStream(pbis);
            break;
        case 4:
        case 11:
        case 12:
        case 22:
            pevt->pv = (void *)S32Read__18CBinaryInputStream(pbis);
            break;
        case 24: {
            char *pb = (char *)PvAllocSw(0x18);
            func_00117FB0(pbis, pb);
            func_00117FB0(pbis, pb + 8);
            func_00117FB0(pbis, pb + 0x10);
            pevt->pv = pb;
            break;
        }
        case 6:
        case 9:
        case 10:
        case 18:
        case 19:
        case 23:
            break;
        }
    }
}
