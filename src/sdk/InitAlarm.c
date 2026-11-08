/* SPDX-License-Identifier: GPL-3.0-or-later */

struct syscall_entry {
    int number;
    int handler;
};

extern struct syscall_entry D_002C59F0[];
extern int D_002C5288[];
extern int D_002C59C8[];

void RFU116_SetSyscall_3(int number, int handler);
void func_00239910(int destination, int *source, int size);
int RFU091_2(int number);
void FlushCache(int mode);

void InitAlarm(void)
{
    struct syscall_entry *entry;
    unsigned int index;

    if ((*(volatile unsigned int *)0x10001810 & 0x100) == 0) {
        RFU116_SetSyscall_3(D_002C59F0[0].number, D_002C59F0[0].handler);
        func_00239910(0x80076000, D_002C5288, 0x740);
        func_00239910(0x82000, D_002C59C8, 0x28);
        FlushCache(0);
        FlushCache(2);
        RFU116_SetSyscall_3(D_002C59F0[1].number, D_002C59F0[1].handler);
        entry = &D_002C59F0[2];
        for (index = 2; index < 8; index++) {
            RFU116_SetSyscall_3(entry->number, RFU091_2(entry->number));
            entry++;
        }
    }
}
