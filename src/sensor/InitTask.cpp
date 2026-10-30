struct Big_003DD490 { char pad[0x3AFC]; int taskCount; };
struct Task_1635A0 { char pad0[0x54]; int f54; int pad58; int f5c; char pad60[0x58]; int fB8; int fBC; int fC0; char padC4[0x2C]; int fF0; int fF4; };
extern "C" {
void InitLo();
extern Big_003DD490 B_003DD490;
void InitTask(Task_1635A0 *task) {
    InitLo();
    task->f54 = -1;
    task->fF0 = -1;
    task->fF4 = 0;
    task->f5c = -1;
    task->fB8 = -1;
    task->fBC = -1;
    task->fC0 = -1;
    B_003DD490.taskCount++;
}
}
