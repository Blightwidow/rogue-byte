#include "types.h"

typedef struct LeaseTable {
    char pad0[0xC];
    s32 field_0xC;
    char pad10[0x68 - 0x10];
    s32 field_0x68;
} LeaseTable;

typedef struct LeaseOwner {
    char pad0[0xE0];
    LeaseTable *field_0xE0;
} LeaseOwner;

s32 PleaseFromIclone(LeaseOwner *owner, s32 arg1) {
    LeaseTable *table;

    table = owner->field_0xE0;
    return table->field_0x68 + ((arg1 - table->field_0xC) * 0x50);
}
