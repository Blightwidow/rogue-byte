#include "sly2.h"
struct SLOTHEAP;
struct ENTRY { char pad[0x94]; int id; int pad98; int sub; char padA0[0x100 - 0xA0]; };
struct ALO { char pad[0x50]; int count; ENTRY *entries; };
struct HANDLE { int a; int b; char pad8[4]; void *vtable; char pad10[0x10]; ALO *alo; ENTRY *entry; char pad28[8]; };
extern SLOTHEAP B_003E15CC;
extern char D_002CA2C0[];
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);
void *memset(void *, int, unsigned int);

HANDLE *func_001F8510(ALO *alo, int sub, int id)
{
    for (int index = 0; index < alo->count; index++) {
        ENTRY *entry = &alo->entries[index];
        if (entry->id != id) continue;
        if (sub != -1 && entry->sub != sub) continue;
        HANDLE *handle = (HANDLE *)PvAllocSlotheapImpl(&B_003E15CC);
        memset(handle, 0, 0x30);
        handle->vtable = D_002CA2C0;
        handle->alo = alo;
        handle->entry = entry;
        handle->a = 0;
        handle->b = 0;
        return handle;
    }
    return 0;
}
