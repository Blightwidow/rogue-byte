#include "sly2.h"
struct UL_159500 { unsigned long v; } __attribute__((packed));
struct Bytes8_159500 { char b[8]; };
struct ALLOCREQ_159500 { int size; int align; };
struct BOX_159500 { float minX, minY, minZ, minW; float maxX, maxY, maxZ, maxW; };
struct EMITB_159500 {
    int cref;
    int pad4;
    int *pflag;
    int pad0C;
    int type;
    char pad14[0xC];
    int oidFollow;
    char pad24[0xC];
    BOX_159500 *pbox;
};
struct VTE_159500 { short delta; short unused; void (*fn)(void *, void *); };
struct EMITTER_159500 {
    char pad0[0xC];
    char *vt;
    char pad10[0x30];
    int flags;
    char pad44[0x9C];
    int fE0;
    EMITB_159500 *pemitb;
    char padE8[8];
    int mode;
    int fF4;
    union { Bytes8_159500 bF8; struct { float gMin, gMax; } lmF8; };
    int f100;
    float f104;
    union { Bytes8_159500 b108; struct { float gMin, gMax; } lm108; };
    float f110;
    int f114;
    int oidTarget;
    char dl11C[0x14];
    float f130;
    float f134;
    float f138;
    float f13C;
    float f140;
};
extern "C" {
extern const UL_159500 RO_002A5140;
extern const float RO_002A5148;
extern char B_003DD490[];
void BindEmitter(EMITTER_159500 *);
void QueueSwCallback(char *, EMITTER_159500 *, unsigned long, int);
float GRandInRange(float, float);
void PauseEmitterIndefinite__FP7EMITTER(EMITTER_159500 *);
void PauseEmitter__FP7EMITTERf(EMITTER_159500 *, float);
EMITTER_159500 *PloFindSwObject_thunk(char *, int, int, void *);
EMITTER_159500 *PloNew(int, void *, int, int);
void *PvAllocSwCopyImpl__FiPv(ALLOCREQ_159500 *, void *);
void func_001A6CA8(EMITTER_159500 *, int);
void *PmatLoWorld(EMITTER_159500 *);
void AppendDlEntry(char *, EMITTER_159500 *);

void CEmitter_PostLoad(EMITTER_159500 *pemitter)
{
    BindEmitter(pemitter);
    if (*pemitter->pemitb->pflag != 0)
        QueueSwCallback(B_003DD490, pemitter, RO_002A5140.v, 0);
    if (pemitter->mode == -1) {
        if (pemitter->f104 != 0.0f || pemitter->f114 != 0)
            pemitter->mode = 3;
        else if (pemitter->f110 != 0.0f)
            pemitter->mode = 1;
        else
            pemitter->mode = 0;
    }
    switch (pemitter->mode) {
    case 2:
        pemitter->f138 = RO_002A5148;
        pemitter->f130 = GRandInRange(pemitter->lmF8.gMin, pemitter->lmF8.gMax);
        if (pemitter->f114 != 0)
            PauseEmitterIndefinite__FP7EMITTER(pemitter);
        else if (GRandInRange(0.0f, 1.0f) <= pemitter->f104)
            PauseEmitter__FP7EMITTERf(pemitter, GRandInRange(pemitter->lm108.gMin, pemitter->lm108.gMax));
        break;
    case 3:
        pemitter->f138 = RO_002A5148;
        pemitter->f130 = GRandInRange(pemitter->lmF8.gMin, pemitter->lmF8.gMax) * 60.0f;
        if (pemitter->f114 != 0)
            PauseEmitterIndefinite__FP7EMITTER(pemitter);
        else if (GRandInRange(0.0f, 1.0f) <= pemitter->f104)
            PauseEmitter__FP7EMITTERf(pemitter, GRandInRange(pemitter->lm108.gMin, pemitter->lm108.gMax));
        break;
    case 0:
    case 1:
        pemitter->f138 = 1.0f;
        pemitter->f134 = 1.0f;
        pemitter->f130 = GRandInRange(pemitter->lmF8.gMin, pemitter->lmF8.gMax);
        break;
    }
    EMITB_159500 *pemitb = pemitter->pemitb;
    pemitter->f13C = 1.0f;
    if (pemitb->type == 1) {
        BOX_159500 *pbox = pemitb->pbox;
        if (*pemitb->pflag != 0) {
            float dx = fabsf(pbox->maxX - pbox->minX);
            float dy = fabsf(pbox->maxY - pbox->minY);
            float dz = fabsf(pbox->maxZ - pbox->minZ);
            float r;
            if (dy < dx && dz < dx)
                r = dx;
            else if (dz < dy)
                r = dy;
            else
                r = dz;
            pemitter->f140 = r * 0.5f;
        }
        if (pemitter->f100 != 0) {
            if (pemitter->f110 != 0.0f)
                pemitter->f13C = (pbox->maxX - pbox->minX) * (pbox->maxY - pbox->minY) * (pbox->maxZ - pbox->minZ) * 0.000001f;
            else
                pemitter->f13C = (pbox->maxY - pbox->minY) * (pbox->maxZ - pbox->minZ) * 0.0001f;
        }
    }
    if (pemitter->oidTarget != -1) {
        EMITTER_159500 *ptarget = PloFindSwObject_thunk(B_003DD490, 5, pemitter->oidTarget, 0);
        if (ptarget == 0) {
            ptarget = PloNew(0x1D, 0, pemitter->oidTarget, -1);
            ALLOCREQ_159500 req;
            req.size = 0x100;
            req.align = 0x10;
            EMITB_159500 *pemitbNew = (EMITB_159500 *)PvAllocSwCopyImpl__FiPv(&req, pemitter->pemitb);
            ptarget->pemitb = pemitbNew;
            pemitbNew->cref = 1;
            int *pflag = pemitter->pemitb->pflag;
            if (*pflag != 0) {
                req.align = 0x10;
                req.size = 0x14;
                ptarget->pemitb->pflag = (int *)PvAllocSwCopyImpl__FiPv(&req, pflag);
                ptarget->pemitb->oidFollow = -1;
                *ptarget->pemitb->pflag = 0;
            }
            ptarget->mode = pemitter->mode;
            ptarget->fF4 = pemitter->fF4;
            ptarget->bF8 = pemitter->bF8;
            ptarget->f100 = pemitter->f100;
            ptarget->f104 = pemitter->f104;
            ptarget->b108 = pemitter->b108;
            ptarget->f110 = pemitter->f110;
            ptarget->f114 = pemitter->f114;
            func_001A6CA8(ptarget, 1);
            VTE_159500 *pvte = (VTE_159500 *)((char *)ptarget->vt + 0xF0);
            pvte->fn((char *)ptarget + pvte->delta, PmatLoWorld(pemitter));
        }
        pemitter->fE0 = 0;
        AppendDlEntry(ptarget->dl11C, pemitter);
        int flags = pemitter->flags;
        if (((flags ^ 1) & 1) != 0)
            *(int *)flags &= ~2;
        else
            pemitter->flags = flags & ~2;
    }
}
}
