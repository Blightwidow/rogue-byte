extern "C" {
struct Obj228750;
struct VT228750 {
    char pad0[0x18]; short delta18; short pad1A; void (*fn1C)(char *, int, int, int, int, int);
    char pad20[0x130 - 0x20]; short delta130; short pad132; void (*fn134)(char *, Obj228750 *);
};
struct Obj228750 { char pad0[0xC]; VT228750 *vt; };
struct Warp228750 { char pad0[0x13C]; int state; };
struct Link228750 { int a; int b; };
struct Spawn228750 {
    char pad0[0xC]; VT228750 *vt;
    char pad10[0xE0 - 0x10]; int rsmg; char padE4[0x124 - 0xE4]; int task;
    char pad128[0x148 - 0x128]; int linkCount; Link228750 links[1];
};
extern char B_002DDF40, B_002DEB30, B_003DD490;
Obj228750 *PloFindSwObject_thunk(char *, int, int, Spawn228750 *);
int CploFindSwObjectsByClass(char *, int, int, int, int, Warp228750 **);
void SetResetFlag__FP2CM(char *);
void TriggerRsmg(char *, int, char *, Spawn228750 *, int);
void ApplyTaskStateRequests(char *, int, char *, Spawn228750 *);
void Warp_SetState(Warp228750 *, int);
void ActivateSpawn(Spawn228750 *spawn)
{
    Warp228750 *warps[0x20];
    for (int index = 0; index < spawn->linkCount; index++) {
        Link228750 *link = &spawn->links[index];
        Obj228750 *first = PloFindSwObject_thunk(&B_003DD490, 4, link->a, spawn);
        if (first != 0) {
            Obj228750 *second = PloFindSwObject_thunk(&B_003DD490, 4, link->b, spawn);
            if (second != 0) first->vt->fn134((char *)first + first->vt->delta130, second);
        }
    }
    TriggerRsmg(&B_003DD490, spawn->rsmg, (char *)spawn + 0xE4, spawn, 1);
    ApplyTaskStateRequests(&B_002DEB30, spawn->task, (char *)spawn + 0x128, spawn);
    int count = CploFindSwObjectsByClass(&B_003DD490, 5, 0x1A, 0, 0x20, warps);
    for (int index = count - 1; index >= 0; index--) {
        if (warps[index]->state != 2) Warp_SetState(warps[index], 0);
    }
    SetResetFlag__FP2CM(&B_002DDF40);
    spawn->vt->fn1C((char *)spawn + spawn->vt->delta18, 5, 0, 0, 0, 0);
}
}
