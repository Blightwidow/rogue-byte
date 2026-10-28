struct Cmd { int type; int label; int pad8[4]; Cmd *next; };
struct Script { char pad[0x50]; Cmd *first; };
Cmd *PcmdFindScriptLabel(Script *script, int label)
{
    volatile int reserved;
    Cmd *cmd = script->first;
    while (cmd) {
        if (cmd->type == 9 && cmd->label == label)
            break;
        cmd = cmd->next;
    }
    return cmd;
}
