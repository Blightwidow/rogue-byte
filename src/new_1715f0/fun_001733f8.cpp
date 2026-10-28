struct Point { int kind; int oid; void *plo; void *ploAux; void *auxData; char pad14[8]; };
struct Aux { char pad0[0x54]; void *data; };
struct Spawner { char pad0[0x40]; unsigned flags; char pad44[0xC]; int count; Point *points; char pad58[4]; int slotCount; void *slots; };
extern "C" char B_003DD490;
extern "C" void PostLoLoad(Spawner *);
extern "C" void *PloFindSwObject_thunk(void *, int, int, int);
extern "C" void *PloNew(int, int, int, int);
extern "C" void AddScriptRun(void *, int, int, int);
extern "C" void *PvAllocSwClearImpl__Fi(void *);
extern "C" void func_001A6CA8(Spawner *, int);
extern "C" void func_001733F8(Spawner *spawner)
{
    int req[2];
    int index = 0;
    PostLoLoad(spawner);
    for (; index < spawner->count; index++) {
        Point *point = (Point *)((char *)spawner->points + index * 0x1C);
        switch (point->kind) {
        case 1: {
            point->plo = PloFindSwObject_thunk(&B_003DD490, 5, point->oid, 0);
            void *aux = PloNew(0x71, 0, 0x2CB, -1);
            AddScriptRun(aux, point->oid, 1, -1);
            void *data = ((Aux *)aux)->data;
            point->ploAux = aux;
            point->auxData = data;
            break;
        }
        case 0:
        case 2:
            point->plo = PloFindSwObject_thunk(&B_003DD490, 5, point->oid, 0);
            break;
        }
    }
    req[0] = spawner->slotCount * 0x30;
    req[1] = 0x10;
    spawner->slots = PvAllocSwClearImpl__Fi(req);
    func_001A6CA8(spawner, 1);
    unsigned flags = spawner->flags;
    if (!(flags & 1)) {
        *(unsigned *)flags |= 2;
    } else {
        spawner->flags = flags | 2;
    }
}
