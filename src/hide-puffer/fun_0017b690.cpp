#include "sly2.h"
struct Msg { int id; int pad4; int kind; };
struct Cur { char pad0[0x40]; int obj; };
struct Guard { char pad0[0xF60]; int flag; };
#include "goal.h"
struct GOAL_17B690 : GOAL {
    int state;
};
extern "C" int func_00209518(int);
extern "C" int Goal_FHandleMessage(GOAL_17B690 *, int, Msg *);
extern "C" int func_0017B690(GOAL_17B690 *goal, int type, Msg *msg)
{
    if (type == 9 && goal->state == 0 && ((Cur *)goal->pgoalChild)->obj != 0 && func_00209518(((Cur *)goal->pgoalChild)->obj) == msg->id) {
        switch (msg->kind) {
        case 0x31:
            ((Guard *)goal->pstep)->flag = 1;
            return 1;
        case 0x32:
            ((Guard *)goal->pstep)->flag = 0;
            return 1;
        }
    }
    return Goal_FHandleMessage(goal, type, msg);
}
