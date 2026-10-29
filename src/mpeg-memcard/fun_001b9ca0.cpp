extern "C" {
/* SPDX-License-Identifier: GPL-3.0-or-later */
typedef int s32;
typedef short s16;

void GoalStack_Clear(char *goalStack);
char *func_00205438(char *guard, s32 id);

void func_001B9CA0(char *arg0, s32 arg1) {
    char *object;
    char *vtable;
    s16 thisOffset;
    void (*method)(char *);

    GoalStack_Clear(arg0 + 0x26C);
    if (arg1 != 0) {
        object = func_00205438(arg0, 0xC6);
        vtable = *(char **)(object + 0xC);
        thisOffset = *(s16 *)(vtable + 0x40);
        method = *(void (**)(char *))(vtable + 0x44);
        method(object + thisOffset);
    }
}

}
