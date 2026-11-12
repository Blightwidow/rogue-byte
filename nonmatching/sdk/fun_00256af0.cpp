struct ARR { char pad[0x10]; int *pbBase; };
struct OWNER { char pad0[0xC]; ARR *parr; int (*pfnHash)(int *, int); };
struct ENTRY256AF0 { int key; int index; };
extern "C" int *HashTable_Insert(OWNER *, int *, int *);
extern "C" void func_00256AF0(OWNER *powner, int *pelem)
{
    ENTRY256AF0 entry;
    entry.index = pelem - powner->parr->pbBase;
    entry.key = powner->pfnHash(pelem, entry.index);
    HashTable_Insert(powner, &entry.key, &entry.index);
}
