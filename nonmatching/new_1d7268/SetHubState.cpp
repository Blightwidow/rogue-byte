struct CRef { int tagk; int n; int pad[2]; };
struct VT1 { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct VT2 { char pad[0x48]; short delta; short index; void (*fn)(void *, void *); };
struct VT3 { char pad[0x260]; short delta; short index; void (*fn)(void *, int, void *); };
struct HUB { char pad0[0xC]; VT1 *vt; char pad1[0x180 - 0x10]; int state; int sm; char pad2[4]; };
struct OBJ2 { char pad0[0xC]; VT2 *vt; };
struct OBJ3 { char pad0[0xC]; VT3 *vt; };
struct BASE { char pad[0x74]; int f74; };
extern "C" {
extern char B_003DD490[];
extern int g_2dfbc0;
extern char B_002DFC00[];
extern char B_002E0D00[];
extern const char RO_002A7878[];
int CploFindSwObjectsByClass(void *, int, int, int, int, void *);
void DeliverJtLoot(void *);
int IsmsFindSmOptional__FP2SM3OID(int, int);
int OidFromSmIsms(int, int);
void StepHubState(void *, int);
void bevy_jobs_162e38(void *);
void bevy_player_p18_gadget_refill(void *, int);
void func_00187E78(void *);
void func_001D8A38(CRef *, const char *, int);
void CRef_Destruct(CRef *);
void func_001F1448(int, void *, int, int, void *);
}
struct GLOBALS { char pad[0x3B0C]; BASE *job; };
static inline void Msg3(OBJ3 *obj) { obj->vt->fn((char *)obj + obj->vt->delta, 4, obj); }
static inline void Msg2(OBJ2 *obj) { obj->vt->fn((char *)obj + obj->vt->delta, obj); }
void SetHubState(HUB *hub, int state)
{
    void *found1[4];
    OBJ3 *found2[0x20];
    OBJ2 *found3[0x20];
    CRef ref;
    if (hub->state == state) return;
    if (hub->state == 1) {
        func_001F1448(0, hub, -1, 0, (char *)hub + 0x188);
        hub->vt->fn((char *)hub + hub->vt->delta, 6, 0, 0, 0, 0);
    }
    hub->state = state;
    if (state != 1) return;
    BASE *job = ((GLOBALS *)B_003DD490)->job;
    if (job && job->f74 == 0) bevy_jobs_162e38(job);
    int count = CploFindSwObjectsByClass(B_003DD490, 5, 0x34, 0, 3, found1);
    for (int index = 0; index < count; index++) {
        void *obj = found1[index];
        DeliverJtLoot(obj);
        bevy_player_p18_gadget_refill(obj, 1);
    }
    count = CploFindSwObjectsByClass(B_003DD490, 0x105, 0x64, 0, 0x20, found2);
    for (int index = 0; index < count; index++) {
        OBJ3 *obj = found2[index];
        Msg3(obj);
    }
    count = CploFindSwObjectsByClass(B_003DD490, 0x105, 0x4F, 0, 0x20, found3);
    for (int index = 0; index < count; index++) {
        OBJ2 *obj = found3[index];
        Msg2(obj);
    }
    int id;
    if (hub->sm) {
        func_001D8A38(&ref, RO_002A7878, 0);
        int value = ref.n;
        CRef_Destruct(&ref);
        if (IsmsFindSmOptional__FP2SM3OID(hub->sm, value) == -1) id = OidFromSmIsms(hub->sm, 0);
        else id = value;
    } else {
        id = -1;
    }
    func_001F1448(hub->sm, hub, id, 0, (char *)hub + 0x188);
    StepHubState(hub, 0);
    func_00187E78(g_2dfbc0 & 2 ? B_002DFC00 : B_002E0D00);
    hub->vt->fn((char *)hub + hub->vt->delta, 5, 0, 0, 0, 0);
}
