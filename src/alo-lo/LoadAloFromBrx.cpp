#include "sly2.h"
struct Bis;
struct ALLOCREQ { int cb; int cbAlign; };
struct VT { short delta; short index; void *(*fn)(void *, int); };
struct XFREC {
    float m[16]; char pad40[0x54];
    int kind; int unused98; int word9C; void *pxf; int unusedA4; XFREC *pxfMirror; short limitLo; short limitHi; char padB0[0x10]; QW vecC0; char padD0[0x10]; QW vecE0; char padF0[0x10];
};
struct ALO { char pad0[0xC]; char *vt; char pad10[0x30]; int *pflags; char pad44[0xC]; int count; XFREC *recs; void *p58; void *p5C; void *p60; };
struct ACT { int type; ALO *owner; XFREC *xf; int link; char pad10[4]; int arg14; void *vtable; int field1C; QW vec20; };
struct ACTS { ACT base; };
extern "C" {
unsigned U8Read__18CBinaryInputStream(Bis *);
int S8Read__18CBinaryInputStream(Bis *);
int S16Read__18CBinaryInputStream(Bis *);
int S32Read__18CBinaryInputStream(Bis *);
float F32Read__18CBinaryInputStream(Bis *);
void ReadVector__18CBinaryInputStreamP6VECTOR(Bis *, void *);
void CBinaryInputStream_ReadMatrix4(Bis *, void *);
void func_00117F90(Bis *, void *);
void func_00117FB0(Bis *, void *);
void *PvAllocSwClearImpl__Fi(ALLOCREQ *);
void *PvAllocAct(int);
QW GetXfDofValue(void *, void *);
void InsertXfAct(ALO *, XFREC *, ACT *);
void LoadAloIkLimbs(ALO *, Bis *);
void LoadXfMirrors(ALO *, Bis *);
void func_0021C888(ALO *, Bis *);
void func_0022C818(ALO *, XFREC *);
void UpdateAloXfWorld(ALO *);
extern char D_002CA6A0[], D_002CA7A0[], D_002CA7E0[], D_002CA820[];
}
static inline void *ReadXf(ALO *palo, Bis *pbis)
{
    int id = S16Read__18CBinaryInputStream(pbis);
    VT *vt = (VT *)(palo->vt + 0x198);
    return vt->fn((char *)palo + vt->delta, id);
}
extern "C" void LoadAloFromBrx(ALO *palo, Bis *pbis)
{
    int index = 0;
    ALLOCREQ req;
    int count = S16Read__18CBinaryInputStream(pbis);
    req.cb = count << 8;
    req.cbAlign = 0x10;
    palo->count = count;
    palo->recs = (XFREC *)PvAllocSwClearImpl__Fi(&req);
    {
        ACT *actB;
        ACT *actC;
        ACT *actA;
        ACT *actD;
        int hasA;
        int hasB;
        int hasC;
        for (; index < palo->count; index++) {
            XFREC *rec = &palo->recs[index];
            rec->pxf = ReadXf(palo, pbis);
            rec->kind = S16Read__18CBinaryInputStream(pbis);
            rec->word9C = S32Read__18CBinaryInputStream(pbis);
            unsigned flags = U8Read__18CBinaryInputStream(pbis);
            if (flags & 1) {
                float scaleA = F32Read__18CBinaryInputStream(pbis);
                rec->limitHi = 1000;
                rec->limitLo = (int)(scaleA * 1000.0f);
            } else if (flags & 2) {
                rec->limitLo = (int)(F32Read__18CBinaryInputStream(pbis) * 1000.0f);
                rec->limitHi = (int)(F32Read__18CBinaryInputStream(pbis) * 1000.0f);
            } else {
                rec->limitLo = 1000;
                rec->limitHi = 1000;
            }
            hasA = flags & 4;
            if (hasA) {
                ACT *fresh = (ACT *)PvAllocAct(0x30);
                fresh->vtable = D_002CA820;
                fresh->type = 1;
                fresh->field1C = 2;
                actA = fresh;
                actA->arg14 = S8Read__18CBinaryInputStream(pbis);
            }
            hasB = flags & 8;
            if (hasB) {
                ACT *fresh = (ACT *)PvAllocAct(0x80);
                fresh->type = 2;
                fresh->vtable = D_002CA7E0;
                actB = fresh;
                actB->arg14 = S8Read__18CBinaryInputStream(pbis);
                *(float *)((char *)actB + 0x60) = F32Read__18CBinaryInputStream(pbis);
                func_00117F90(pbis, (char *)actB + 0x30);
                func_00117FB0(pbis, (char *)actB + 0x50);
                func_00117F90(pbis, (char *)actB + 0x40);
                func_00117FB0(pbis, (char *)actB + 0x58);
                *(int *)((char *)actB + 0x64) = S8Read__18CBinaryInputStream(pbis);
                *(int *)((char *)actB + 0x68) = S8Read__18CBinaryInputStream(pbis);
                *(int *)((char *)actB + 0x6C) = S32Read__18CBinaryInputStream(pbis);
            }
            hasC = flags & 0x10;
            if (hasC) {
                ACT *fresh = (ACT *)PvAllocAct(0x28);
                fresh->type = 4;
                fresh->vtable = D_002CA7A0;
                actC = fresh;
                actC->arg14 = S8Read__18CBinaryInputStream(pbis);
                *(float *)((char *)actC + 0x1C) = F32Read__18CBinaryInputStream(pbis);
                *(float *)((char *)actC + 0x20) = F32Read__18CBinaryInputStream(pbis);
            }
            int hasD = flags & 0x20;
            if (hasD) {
                ACT *fresh = (ACT *)PvAllocAct(0x30);
                fresh->vtable = D_002CA6A0;
                fresh->type = 9;
                fresh->arg14 = 0x14;
                actD = fresh;
                ReadVector__18CBinaryInputStreamP6VECTOR(pbis, (char *)actD + 0x20);
            }
            switch (rec->kind) {
            case 0:
            case 13:
            case 15:
                CBinaryInputStream_ReadMatrix4(pbis, rec);
                break;
            case 8:
            case 14:
                memset(rec, 0, 0x40);
                rec->m[15] = 1.0f;
                rec->m[10] = 1.0f;
                rec->m[5] = 1.0f;
                rec->m[0] = 1.0f;
                rec->pxfMirror = (XFREC *)ReadXf(palo, pbis);
                rec->m[12] = -rec->pxfMirror->m[12];
                rec->m[13] = -rec->pxfMirror->m[13];
                rec->m[14] = -rec->pxfMirror->m[14];
                break;
            default:
                CBinaryInputStream_ReadMatrix4(pbis, rec);
                QW dof = GetXfDofValue(rec, rec);
                rec->vecE0 = dof;
                rec->vecC0 = dof;
                break;
            }
            func_0022C818(palo, rec);
            if (hasA) {
                actA->owner = palo;
                actA->xf = rec;
                actA->link = -1;
                actA->vec20 = GetXfDofValue(rec, rec);
                InsertXfAct(palo, rec, actA);
            }
            if (hasB) {
                actB->owner = palo;
                actB->xf = rec;
                actB->link = *(int *)((char *)actB + 0x68);
                actB->vec20 = GetXfDofValue(rec, rec);
                InsertXfAct(palo, rec, actB);
            }
            if (hasC) {
                actC->owner = palo;
                actC->xf = rec;
                actC->link = -1;
                InsertXfAct(palo, rec, actC);
            }
            if (hasD) {
                actD->owner = palo;
                actD->xf = rec;
                actD->link = -1;
                InsertXfAct(palo, rec, actD);
            }
        }
    }
    UpdateAloXfWorld(palo);
    LoadAloIkLimbs(palo, pbis);
    LoadXfMirrors(palo, pbis);
    func_0021C888(palo, pbis);
    palo->p58 = ReadXf(palo, pbis);
    palo->p5C = ReadXf(palo, pbis);
    palo->p60 = ReadXf(palo, pbis);
    if (palo->count > 0) {
        int *pword = palo->pflags;
        if (((int)pword ^ 1) & 1) {
            *pword &= ~0x20;
            return;
        }
        palo->pflags = (int *)((int)pword & ~0x20);
    }
}
