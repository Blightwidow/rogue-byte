#include "sly2.h"
struct VTB { char pad[0x198]; short delta; short index; void (*fn)(void *, int *); };
struct VTC { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct VTE { short delta; short index; void (*fn)(void *, QW, float, int); };
struct RIPVT { char pad[8]; VTE e; };
struct OBJ { char pad[0xC]; VTB *vt; };
struct DP;
struct DP { char pad0[0xC]; VTC *vt; char pad1[0x150 - 0x10]; int state; char pad2[0x210 - 0x154]; OBJ *oncollect; char pad3[0x230 - 0x214]; float waitMin; float waitMax; float wait; };
struct SW;
struct MAT { QW r0; QW r1; QW r2; };
extern "C" {
float GRandInRange(float, float);
char *PripNewRipg(SW *, int, int);
QW PosLoWorld(DP *);
MAT *PmatLoWorld(DP *);
int NewEmitter(int);
void SetEmitterUnpositioned(int, int);
void ShowCoinBlot(SW *);
void bevy_camera_follow_activity(void *, int, DP *);
void SetDprizeDprizes(DP *, int);
void func_001C67A0(DP *, int);
extern SW B_003DD490;
extern char D_002C0DA0;
extern char B_002DEB30;
}

void func_001C65F8(DP *dp, int newState)
{
    if (dp->state == newState) return;
    switch (newState) {
    case 0:
        dp->wait = GRandInRange(dp->waitMin, dp->waitMax);
        break;
    case 1: {
        char *rip = PripNewRipg(&B_003DD490, 9, 0);
        if (rip) {
            char *sub = *(char **)(rip + 0xEC);
            *(DP **)(rip + 0xF4) = dp;
            *(char **)(rip + 0xF0) = &D_002C0DA0;
            *(int *)(rip + 0xF8) = 0;
            VTE *entry = &((RIPVT *)sub)->e;
            char *target = rip + entry->delta;
            QW pos = PosLoWorld(dp);
            entry->fn(target, pos, 1.0f, 0);
            *(DP **)(rip + 0x1C) = dp;
            MAT *mat = PmatLoWorld(dp);
            *(QW *)(rip + 0x40) = mat->r0;
            *(QW *)(rip + 0x50) = mat->r1;
            *(QW *)(rip + 0x60) = mat->r2;
        } else {
            func_001C67A0(dp, 0);
        }
        SetEmitterUnpositioned(NewEmitter(0x29), 0);
        OBJ *obj = dp->oncollect;
        if (obj) {
            struct { int msg[2]; char pad[0x38]; } loc;
            int *msg = loc.msg;
            msg[0] = 1;
            msg[1] = (int)dp;
            VTB *vtobj = obj->vt;
            vtobj->fn((char *)obj + vtobj->delta, msg);
        }
        newState = 2;
        dp->vt->fn((char *)dp + dp->vt->delta, 5, 0, 0, 0, 0);
        ShowCoinBlot(&B_003DD490);
        bevy_camera_follow_activity(&B_002DEB30, 0x12, dp);
        break;
    }
    }
    SetDprizeDprizes(dp, newState);
}
