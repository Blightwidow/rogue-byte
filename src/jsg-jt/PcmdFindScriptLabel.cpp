// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct CMD { int type; int label; char pad[0x10]; CMD *next; };
struct SCRIPT { char pad[0x50]; CMD *first; };
extern "C" CMD *PcmdFindScriptLabel(SCRIPT *script, int label)
{
    VECTOR vector;
    CMD *cmd = script->first;
    while (cmd != 0) {
        if (cmd->type == 9 && cmd->label == label)
            break;
        cmd = cmd->next;
    }
    return cmd;
}
