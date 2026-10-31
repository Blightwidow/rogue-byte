extern "C" {
void *memset(void *, int, unsigned int);
struct Cmd_209E28 { int kind; int pad[3]; int arg1; char rest[0x5C]; };
void *func_00205458(int, int);
void GoalBrain_SetCommand(void *, Cmd_209E28 *);
void PostGuardStunCommand(int arg0, int arg1) {
    Cmd_209E28 cmd;
    void *brain = func_00205458(arg0, 0x9C);
    memset(&cmd, 0, sizeof(cmd));
    cmd.kind = 6;
    cmd.arg1 = arg1;
    GoalBrain_SetCommand(brain, &cmd);
}
}
