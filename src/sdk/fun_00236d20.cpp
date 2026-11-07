// SPDX-License-Identifier: GPL-3.0-or-later
struct EntryTable {
    char pad0[0x1C];
    char *entries;
    int count;
};
extern "C" {
void *func_00236CF0(void);
void *func_00236D20(EntryTable *table, int index) {
    if (index < 0 || index >= table->count) {
        return func_00236CF0();
    }
    return table->entries + index * 64;
}
}
