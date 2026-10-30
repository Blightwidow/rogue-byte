#include "sly2.h"
struct VT_13B860 {
    char pad0[0x18]; short d18; short i18; void (*f1C)(void *, int, int, int, int, int);
    char pad1[0x48 - 0x20]; short d48; short i48; void (*f4C)(void *);
    char pad2[0xE8 - 0x50]; short dE8; short iE8; void (*fEC)(void *, QW);
    short dF0; short iF0; void (*fF4)(void *, void *);
    char pad3[0x118 - 0xF8]; short d118; short i118; void (*f11C)(void *, QW);
    short d120; short i120; void (*f124)(void *, QW);
    char pad4[0x198 - 0x128]; short d198; short i198; void (*f19C)(void *, void *, void *);
};
struct Bomb_13B860;
union W_13B860 { void *p; int i; float f; };
struct Msg_13B860 { W_13B860 w0, w4, w8, wC, w10; char pad14[0xC]; QW dir; QW f40; char pad40[0x20]; QW f70; };
struct Bomb_13B860 {
    char pad0[0x0C]; VT_13B860 *vt; char pad1[0x18]; unsigned long flags; char pad2[0x124]; float f154; char pad3[4];
    float f15C; char pad4[4]; int f164; Bomb_13B860 *f168; float f16C; char pad5[4]; int f174; char pad6[8]; QW pos180;
    char a190[0x30]; QW f1C0; QW f1D0; int f1E0; char pad7[8]; int f1EC; int f1F0; char pad8[0xC]; void *f200;
};
struct Frame_13B860 { char pad[0x10]; };
struct Phit_13B860 { char pad[0x54]; int f54; };
struct Link_13B860 { char pad[0x14]; void **f14; };
extern "C" {
void CStackFrame_Construct(Frame_13B860 *);
void CStackFrame_Destructor(Frame_13B860 *, int);
int FIsBasicDerivedFrom(void *, int);
void GetBombVictims(Bomb_13B860 *, int *, void ***);
void PaloAbsorbWkr(Msg_13B860 *);
Phit_13B860 *PhitfxSpawn(int, QW, void *);
QW PosLoWorld(void *);
void PrepareBombDetonation(Bomb_13B860 *, QW, QW);
extern char B_003DD490[];
extern int D_002BC9E0;
extern QW g_2a2dc0;
extern float RO_002A4B1C;
void DetonateBomb(Bomb_13B860 *self) {
    Frame_13B860 frame;
    int count;
    void **victims;
    Msg_13B860 msg;
    if ((int)(self->flags >> 60) & 1) {
        PrepareBombDetonation(self, PosLoWorld(self), g_2a2dc0);
        if (self->f164 == 0) {
            int index = 0;
            CStackFrame_Construct(&frame);
            GetBombVictims(self, &count, &victims);
            if (count > 0) {
                do {
                    void *victim = victims[index];
                    memset(&msg, 0, 0x60);
                    msg.wC.i = self->f1EC;
                    msg.w10.i = self->f1F0;
                    msg.dir = self->pos180;
                    msg.w0.p = self;
                    msg.w8.p = victim;
                    int token0, token1, token2, token3, token4;
                    QW pos = PosLoWorld(victim);
                    asm("qmtc2.ni %1, vf2" : "=r" (token0) : "r" (pos));
                    asm("lqc2 vf1, 0x180(%1)\n\tvsub.xyzw vf1, vf2, vf1\n\tvmul.xyz vf2, vf1, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z" : "=r" (token1) : "r" (self), "r" (token0));
                    asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=r" (token2) : "r" (token1));
                    int bits;
                    asm("qmfc2.ni %0, vf2" : "=r" (bits) : "r" (token2));
                    if (*(float *)&bits < 0.0001f) {
                        asm("qmtc2.ni %1, vf2" : "=r" (token3) : "r" (g_2a2dc0), "r" (token2));
                    } else {
                        asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf2, vf1, Q" : "=r" (token3) : "r" (token2));
                    }
                    asm("qmtc2.ni %1, vf1" : "=r" (token4) : "r" (D_002BC9E0), "r" (token3));
                    index++;
                    asm("vmulx.xyzw vf2, vf2, vf1x\n\tsqc2 vf1, 0x70(%1)\n\tsqc2 vf2, 0x40(%1)" : : "r" (token4), "r" (&msg) : "memory");
                    PaloAbsorbWkr(&msg);
                } while (index < count);
            }
            CStackFrame_Destructor(&frame, 2);
        }
        self->vt->fEC((char *)self + self->vt->dE8, self->pos180);
        self->vt->fF4((char *)self + self->vt->dF0, self->a190);
        self->vt->f11C((char *)self + self->vt->d118, self->f1C0);
        self->vt->f124((char *)self + self->vt->d120, self->f1D0);
        Bomb_13B860 *other = self->f168;
        if (other != 0) {
            msg.w0.i = 9;
            msg.w4.p = self;
            msg.w8.f = self->f16C;
            msg.wC.f = self->f15C;
            other->vt->f19C((char *)other + other->vt->d198, &msg, other);
        }
        if (self->f1E0 != 0) {
            void *attacker = self->f200;
            void *owner = self;
            if (attacker != (void *)self && FIsBasicDerivedFrom(attacker, 0x70) != 0) {
                void **link = ((Link_13B860 *)attacker)->f14;
                if (link != 0) {
                    void *linked = *link;
                    owner = (linked == attacker) ? (void *)self : linked;
                }
            }
            PhitfxSpawn(*(int *)(B_003DD490 + 0x402C), PosLoWorld(self), owner)->f54 = 1;
        }
        self->vt->f4C((char *)self + self->vt->d48);
        self->f174 = 0;
        self->f154 = RO_002A4B1C;
        self->vt->f1C((char *)self + self->vt->d18, 5, 0, 0, 0, 0);
    }
}
}
