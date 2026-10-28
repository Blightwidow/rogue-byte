#include "m2c_macros.h"

M2C_UNK HashTable_Clear(s32);                       /* extern */

void HashTable_Clear_thunk(s32 arg0) {
    HashTable_Clear(arg0 + 0x14);
}
