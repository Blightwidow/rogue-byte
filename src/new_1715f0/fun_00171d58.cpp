extern "C" {
int func_00205458(void *self, int kind);
void GoalBrain_SetCommand(int brain, void *command);
void *memset(void *, int, unsigned);
struct Cmd_171D58 { int kind; char pad[0x6C]; };
void func_00171D58(void *self) {
    Cmd_171D58 command __attribute__((aligned(16)));
    int brain = func_00205458(self, 0x9C);
    if (brain != 0) {
        memset(&command, 0, 0x70);
        command.kind = 1;
        GoalBrain_SetCommand(brain, &command);
    }
}
}
