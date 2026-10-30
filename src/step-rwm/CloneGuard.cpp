typedef int s32; typedef short s16;
struct VEnt { char pad0[0x148]; s16 adj; s16 pad; void (*fn)(void *, s32); };
struct Part { char pad[0xC]; VEnt *vt; };
struct Guard { char pad[0xF64]; Part *part; };
extern "C" {
void CloneStep();
void func_00209770(void *, void *);
void CloneGuardAnimrefs(void *);
void CloneGuard(Guard *arg0, Guard *arg1) {
    Part *part = arg0->part;
    CloneStep();
    func_00209770((char *)arg0 + 0xFD0, arg0);
    arg0->part = part;
    VEnt *vt = part->vt;
    void (*fn)(void *, s32) = vt->fn;
    fn((char *)part + vt->adj, (s32)arg1->part);
    CloneGuardAnimrefs(arg0);
}
}
