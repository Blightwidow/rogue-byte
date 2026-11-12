// SPDX-License-Identifier: GPL-3.0-or-later
extern int func_00252148(int, int);
extern void func_002511C8(int, int *, int, int, int, int, int, int);

void func_002515F0(int context, int *words, int argument2, int *table, int index, int mode, int flagA, int argument8,
                   int argument9, int argument10, int argument11)
{
    int *slot;
    if (mode == 1) {
        if (flagA == 0 && argument10 == 0) {
            table[index + 2] = table[index] = func_00252148(context, 1);
        }
        func_002511C8(context, words + index * 2, argument2, argument8, argument9, argument10, argument11, 0);
        words[index * 2 + 4] = words[index * 2];
        words[index * 2 + 5] = words[index * 2 + 1];
        return;
    }
    slot = table + index;
    *slot = func_00252148(context, 1);
    func_002511C8(context, words + index * 2, argument2, argument8, argument9, argument10, argument11, 0);
    slot[2] = func_00252148(context, 1);
    func_002511C8(context, words + index * 2 + 4, argument2, argument8, argument9, argument10, argument11, 0);
}
