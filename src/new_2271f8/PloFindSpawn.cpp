struct Spawn227FE8 { char pad0[0x18]; int id; char pad1C[0x16C - 0x1C]; int count; int ids[1]; };
extern "C" int PloFindSwObject_thunk(int, int);
extern "C" int CploFindSwObjectsByClass(int, int, int, int, int, Spawn227FE8 **);
extern "C" Spawn227FE8 *PloFindSpawn(int arg0, int id, int arg2)
{
    Spawn227FE8 *list[0x20];
    int found = 0;
    int klass = 5;
    if (arg2 != -1) {
        found = PloFindSwObject_thunk(arg0, 5);
        klass = found != 0 ? 1 : 5;
    }
    Spawn227FE8 *result = 0;
    int count = CploFindSwObjectsByClass(arg0, klass, 0x2A, found, 0x20, list);
    for (int index = 0; index < count; index++) {
        {
            Spawn227FE8 *spawn = list[index];
            if (spawn->id != id) {
                int entryCount = spawn->count;
                int entryIndex = 0;
                if (entryCount > 0) {
                    int *entry = spawn->ids;
                    do {
                        entryIndex++;
                        if (*entry == id) goto hit;
                        entry++;
                    } while (entryIndex < entryCount);
                }
            } else {
            hit:
                result = spawn;
            }
        }
    }
    return result;
}
