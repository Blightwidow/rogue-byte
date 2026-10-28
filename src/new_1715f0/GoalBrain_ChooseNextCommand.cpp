#include "sly2.h"
struct VT { char pad[0x2C0]; short delta; short index; void *(*fn)(void *); };
struct GUARD { char pad[0xC]; VT *vt; char pad2[0xFBC - 0x10]; int mode; };
struct GUARD2 { char pad[0x1010]; int cunk; };
struct GOAL { char pad[0x10]; GUARD *pguard; char pad2[0x1C]; int kindRunning; };
struct CMD { int kind; char pad[0xC]; int arg; float g; char pad2[0x58]; };
struct SW { int x; };
extern SW B_003DD490;
extern "C" {
int FIsBasicDerivedFrom(void *, int);
int PpoSwFocusBase(SW *);
int func_00177D20(GOAL *);
int func_00177D70(GOAL *);
int func_00208B38(void *, void *);
float func_00208BB0(void *);
QW PosLoWorld(void *);
int SpawnSwHitFx(SW *, int, QW, void *);
void GoalBrain_SetCommand(GOAL *, CMD *);
}
void GoalBrain_ChooseNextCommand(GOAL *pgoal)
{
    CMD cmd;
    memset(&cmd, 0, 0x70);
    if (FIsBasicDerivedFrom(pgoal->pguard, 0x3B) != 0 && ((GUARD2 *)pgoal->pguard)->cunk > 0) {
        cmd.kind = 0xD;
        cmd.arg = PpoSwFocusBase(&B_003DD490);
    } else if (pgoal->pguard->mode == 0x15) {
        cmd.kind = 0x12;
        cmd.arg = PpoSwFocusBase(&B_003DD490);
        cmd.g = 3.4028235e38f;
    } else if (func_00177D20(pgoal) != 0) {
        cmd.kind = 0xC;
    } else if (func_00177D70(pgoal) != 0) {
        cmd.kind = 0xF;
    } else {
        GUARD *guard = pgoal->pguard;
        VT *vt = guard->vt;
        void *target = vt->fn((char *)guard + vt->delta);
        if (target != 0) {
            if (func_00208B38(pgoal->pguard, target) != 0) {
                cmd.kind = 0x12;
                cmd.arg = (int)target;
                cmd.g = func_00208BB0(pgoal->pguard);
            } else {
                cmd.kind = 4;
                cmd.arg = (int)target;
            }
        } else {
            int running = pgoal->kindRunning;
            if (running < 0xB) {
                if (running > 5) {
                    cmd.kind = 2;
                    cmd.arg = SpawnSwHitFx(&B_003DD490, 0, PosLoWorld(pgoal->pguard), pgoal->pguard);
                } else
                    cmd.kind = 1;
            } else
                cmd.kind = 1;
        }
    }
    GoalBrain_SetCommand(pgoal, &cmd);
}
