#include "sly2.h"
struct VT_1C60B8 {
    char p0[8]; short d8; short pa; void (*f8)(void *, void *);
    short d10; short pb; void (*f10)(void *, void *);
    char p1[0x28]; short d40; short pc; void (*f40)(void *, void *);
    short d48; short pd; void (*f48)(void *, void *);
};
struct OBJ_1C60B8 { char pad[0xC]; VT_1C60B8 *vt; };
extern "C" {
int PpoolFromLoClone(void *);
void *PsmaApplySm(int, unsigned, int, int);
void RetractSma(void *);
void SetSmaGoal__FP3SMA3OID(void *, int);
void SkipSma(void *, float);
void UnlockLeaseOfPlo(int, void *);
void func_001A58D0(void *, unsigned, int);
extern QW D_002C0D60;
extern QW g_2a2dd0;
}
struct Clock { float time; float dt; };
extern Clock g_2dded0;
#define F(type, base, off) (*(type *)((char *)(base) + (off)))

extern "C" void SetDprizeDprizes(void *self, unsigned state)
{
    int sma = -1;
    if (F(unsigned, self, 0x150) == state)
        return;
    if (state != 0 && state != 5)
        func_001A58D0(self, state, 0);
    unsigned old = F(unsigned, self, 0x150);
    if ((int)old == -1 || old == 2) {
        void *source = F(void *, self, 0x58);
        F(QW, self, 0x170) = F(QW, source, 0x30);
        F(QW, self, 0x180) = F(QW, source, 0xB0);
    }
    if (state < 6) {
        switch (state) {
        case 0: {
            int goal = F(int, self, 0x15C);
            sma = (~goal != 0) ? goal : 0x184;
            F(QW, self, 0x190) = g_2a2dd0;
            break;
        }
        case 3:
        case 4:
            sma = 0x183;
            F(QW, self, 0x190) = D_002C0D60;
            break;
        case 2: {
            OBJ_1C60B8 *obj = (OBJ_1C60B8 *)self;
            F(float, self, 0x1CC) = 3.4028235e38f;
            ((void (*)(void *))obj->vt->f48)((char *)self + obj->vt->d48);
            int pool = PpoolFromLoClone(self);
            if (pool != 0)
                UnlockLeaseOfPlo(pool, self);
            break;
        }
        case 5:
            sma = 0x186;
            F(QW, self, 0x190) = g_2a2dd0;
            break;
        }
    }
    if (state == 0 || ((int)state >= 0 && (int)state < 6 && (int)state >= 4)) {
        OBJ_1C60B8 *child = F(OBJ_1C60B8 *, self, 0x16C);
        if (child != 0)
            child->vt->f40((char *)child + child->vt->d40, child);
    } else {
        OBJ_1C60B8 *child = F(OBJ_1C60B8 *, self, 0x16C);
        if (child != 0)
            child->vt->f48((int *)child + child->vt->d48, child);
    }
    F(unsigned, self, 0x150) = state;
    F(float, self, 0x154) = g_2dded0.time;
    if (sma != -1) {
        void *current = F(void *, self, 0x168);
        if (current == 0) {
            OBJ_1C60B8 *created = (OBJ_1C60B8 *)PsmaApplySm(F(int, self, 0x164), state, sma, 0);
            F(void *, self, 0x168) = created;
            created->vt->f8((char *)created + created->vt->d8, created);
            float skip = F(float, self, 0x160);
            if (skip > 0.0f)
                SkipSma(F(void *, self, 0x168), skip);
        } else {
            SetSmaGoal__FP3SMA3OID(current, sma);
        }
    } else {
        OBJ_1C60B8 *current = F(OBJ_1C60B8 *, self, 0x168);
        if (current != 0) {
            RetractSma(current);
            OBJ_1C60B8 *again = F(OBJ_1C60B8 *, self, 0x168);
            again->vt->f10((char *)again + again->vt->d10, again);
            F(void *, self, 0x168) = 0;
        }
    }
}
