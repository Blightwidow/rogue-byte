#include "sly2.h"
struct Side_144640 { char pad0[8]; void *obj; char pad1[0x40 - 0xC]; };
struct Item_144640 { Side_144640 sides[2]; char pad2[0xAC - 0x80]; Item_144640 *next; };
struct Chain_144640 { Item_144640 *head; Chain_144640 *next; };
struct Goal_144640 { char pad[0x40]; int *kind; };
struct World_144640 { char pad[0x64]; Chain_144640 *chain; };
struct Jt_144640 { char pad0[0xEC]; World_144640 *world; char pad1[0x2DC - 0xF0]; int f2DC; char pad2[0x1084 - 0x2E0]; Goal_144640 *goal; };
struct Act_144640 { Jt_144640 *jt; char pad0[0x10 - 4]; QW pos; float distance; float tNext; int flag; };
struct Alo_144640 { char pad[0x130]; float f130; };
struct Ent_144640 { char pad[0x4C]; int f4C; };
extern "C" {
int bevy_player_p4_144068(Jt_144640 *);
int FSwHandsOff(void *);
int FIsBasicDerivedFrom(void *, int);
Ent_144640 *func_00205458(void *, int);
void bevy_camera_follow_activity(void *, int, void *);
void FadeAloOut(void *, float);
QW PosLoWorld(Jt_144640 *);
int FFindSurfaceAlongUp(void *, int, int, float, float);
int func_0017D608(void *);
void WarpJtToPoint(Jt_144640 *, QW);
extern char B_002DEB30[];
extern char B_003DD490[];
extern float D_002BD2D0;
extern float D_002BD2D4;
extern float g_2dded0;
void func_00144640(Act_144640 *self) {
    QW sp0;
    if (self->flag != 0) {
        if (self->jt->f2DC == -1) {
            self->flag = 0;
        }
    } else if (bevy_player_p4_144068(self->jt) != 0) {
        if (g_2dded0 < self->tNext) {
        } else {
            self->tNext = g_2dded0 + D_002BD2D0;
            if (FSwHandsOff(B_003DD490) != 0) {
                int found = 0;
                for (Chain_144640 *chain = self->jt->world->chain; chain != 0; chain = chain->next) {
                    for (Item_144640 *item = chain->head; item != 0; item = item->next) {
                        int diff = ((void *)self->jt != item->sides[0].obj);
                        void *other = item->sides[1 - diff].obj;
                        if (FIsBasicDerivedFrom(other, 0x38) != 0) {
                            Ent_144640 *ent = func_00205458(other, 0xA9);
                            if (ent == 0 || ent->f4C == 0) {
                                if (((Alo_144640 *)other)->f130 >= 0.0f) {
                                    bevy_camera_follow_activity(B_002DEB30, 0x17, other);
                                }
                                found = 1;
                                FadeAloOut(other, 0.5f);
                            }
                        }
                    }
                }
                if (found != 0) return;
            }
            Goal_144640 *goal = self->jt->goal;
            if (goal != 0) {
                if (*goal->kind != 0x24) return;
            } else {
                Ent_144640 *ent = func_00205458(self->jt, 0xA8);
                if (ent == 0) return;
                if (ent->f4C >= 2) return;
                if (ent->f4C < 0) return;
            }
            {
                QW pos = PosLoWorld(self->jt);
                float scale = D_002BD2D4;
                float rate = D_002BD2D0;
                float prev = self->distance;
                int token1, token2, token3;
                asm("qmtc2.ni %1, vf2" : "=r" (token1) : "r" (pos));
                asm("lqc2 vf3, 0x10(%1)\n\tvsub.xyzw vf1, vf2, vf3\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (token2) : "r" (self), "r" (token1));
                asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (token3) : "r" (token2));
                int bits;
                asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (token3));
                float distance = *(float *)&bits;
                if ((prev - distance) < scale * rate) {
                    asm("sqc2 vf3, 0(%0)" : : "r" (&sp0));
                    if (FFindSurfaceAlongUp(&sp0, 0, 0, 100.0f, -150.0f) != 0 || func_0017D608(&sp0) != 0) {
                        WarpJtToPoint(self->jt, sp0);
                        self->flag = 1;
                    }
                }
                self->distance = distance;
            }
        }
    }
}
}
