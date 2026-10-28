#include "sly2.h"
struct Msg { int id; int pad4; int kind; };
struct Cur { char pad0[0x40]; int obj; };
struct Guard { char pad0[0xF60]; int flag; };
struct Goal { char pad0[0x10]; Guard *guard; char pad14[4]; Cur *cur; char pad1c[0x14]; int state; };
extern "C" int func_00209518(int);
extern "C" int Goal_FHandleMessage(Goal *, int, Msg *);
extern "C" int func_0017B690(Goal *goal, int type, Msg *msg)
{
    if (type == 9 && goal->state == 0 && goal->cur->obj != 0 && func_00209518(goal->cur->obj) == msg->id) {
        switch (msg->kind) {
        case 0x31:
            goal->guard->flag = 1;
            return 1;
        case 0x32:
            goal->guard->flag = 0;
            return 1;
        }
    }
    return Goal_FHandleMessage(goal, type, msg);
}
