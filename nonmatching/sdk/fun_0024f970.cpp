#include "types.h"

struct Cmd { int cmd; int pad[7]; };
struct Mpeg { char unknown_0x0[0x868]; void *field868; };
extern "C" {
extern char RO_002AC4E0[];
void func_0024FA38(Mpeg *, char *);
void func_0024B670(void *, Cmd *);
int func_00239450();
void func_002394A0();
}

void func_0024F970(Mpeg *pmpeg)
{
    Cmd cmd;
    func_0024FA38(pmpeg, RO_002AC4E0);
    cmd.cmd = 2;
    func_0024B670(pmpeg->field868, &cmd);
    *(u32 *)0x10002010 = 0x40000000;
    cmd.cmd = 3;
    func_0024B670(pmpeg->field868, &cmd);
    int flag = func_00239450();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFF;
    if (flag) {
        func_002394A0();
    }
    *(volatile u32 *)0x1000B020 = 0;
}
