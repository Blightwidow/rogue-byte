struct ENT_13E368 { int id; char *pch; };
struct OBJ_13E368 { char pad[0x4640]; int count; ENT_13E368 *entries; };
extern "C" const char RO_002A4BE0[];
extern "C" char *PchzStringFromId(OBJ_13E368 *pobj, int id)
{
    if (id == -1)
        return (char *)RO_002A4BE0;
    for (int i = 0; i < pobj->count; i++) {
        if (pobj->entries[i].id == id)
            return pobj->entries[i].pch;
    }
    return (char *)RO_002A4BE0;
}