// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
void func_00236960(const char* format, ...);
void sceSifInitRpc(int mode);
void func_00236C00(void);
int func_00239198(const char* command, int flags);

int sceSifRebootIop(const char* argument) {
    char command[0x50];
    const char* prefix = "rom0:UDNL ";
    const char* scan = argument;
    char* destination;

    while (*scan != 0) {
        scan++;
    }
    const char* base = argument - 11;
    if ((unsigned int)(scan - base) >= 0x51) {
        func_00236960("too long parameter '%s'\n", argument);
        return 0;
    }
    sceSifInitRpc(0);
    func_00236C00();
    destination = command;
    while (*prefix != 0) {
        *destination++ = *prefix++;
    }
    while (*argument != 0) {
        *destination++ = *argument++;
    }
    *destination = 0;
    return func_00239198(command, 0);
}
}
