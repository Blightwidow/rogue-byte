#include "sly2.h"

struct TaskObject {
    char pad0[0xC];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};

struct Task {
    char pad0[0x54];
    int state;
    float f58;
    char pad1[0x78 - 0x5C];
    float f78;
    char pad2[0x80 - 0x7C];
    TaskObject *object;
};

extern "C" void UpdateLo(Task *task);
extern "C" void SendTaskTimeLimit(Task *task, int limit);
extern "C" float g_2dded0[2];
extern "C" int B_003E0F9C;

extern "C" void UpdateTask(Task *task)
{
    UpdateLo(task);
    if (task->state == 1) {
        if (0.0f < task->f78) {
            float gap = g_2dded0[0] - task->f58;
            if (gap < task->f78) {
                if (task->f78 + g_2dded0[1] <= gap) {
                    SendTaskTimeLimit(task, 0);
                }
            }
        }
    }
    if (task->object != 0) {
        int chooseFirst = (task->state == 1);
        if (B_003E0F9C != 0) {
            chooseFirst = 0;
        }
        if (chooseFirst) {
            task->object->v7();
        } else {
            task->object->v8();
        }
    }
}
