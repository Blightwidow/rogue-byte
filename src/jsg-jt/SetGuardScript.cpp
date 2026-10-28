struct SCRIPTSTATE { int pcmd; int context; };
struct SCRIPT { int frame; char pad[0x4C]; int first; };
struct BEHB {
    int pad0[3];
    virtual void v0();
    virtual void v1();
    virtual void HandleEvent(int, int, int, int, int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void ExecuteCmd(int);
};
struct BEH : BEHB {
    char pad1[8];
    char goal[0x18];
    SCRIPT *script;
    int context;
    int cmd;
    int unk3C;
    int unk40;
    SCRIPTSTATE *state;
    int unk48;
    int flag;
};
extern "C" void Goal_Pop(void *);
extern "C" void CFramePtr_Assign(void *, int);
extern "C" void SidebagPtr_Assign(void *, int);
extern "C" void SetGuardScript(BEH *beh, SCRIPT *script, int flag, SCRIPTSTATE *resume)
{
    if (script == beh->script)
        return;
    if (beh->script != 0) {
        Goal_Pop(beh->goal);
        beh->HandleEvent(3, 0, 0, 0, 0);
        CFramePtr_Assign(beh, 0);
        SidebagPtr_Assign((char *)beh + 4, 0);
        beh->context = 0;
        beh->cmd = 0;
        beh->unk40 = 0;
        beh->flag = 0;
    }
    beh->script = script;
    if (script == 0)
        return;
    CFramePtr_Assign(beh, script->frame);
    beh->HandleEvent(2, 0, 0, 0, 0);
    beh->flag = flag;
    if (resume == 0 || resume->pcmd == 0) {
        SCRIPT *current = beh->script;
        int first = current->first;
        beh->context = (int)current;
        beh->cmd = first;
    } else {
        beh->cmd = resume->pcmd;
        beh->state = resume;
        beh->context = resume->context;
    }
    if (beh->cmd != 0)
        beh->ExecuteCmd(beh->cmd);
    beh->state = 0;
}
