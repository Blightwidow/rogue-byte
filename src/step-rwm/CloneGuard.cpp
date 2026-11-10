#include "types.h"
struct VEnt { char pad0[0x148]; s16 adj; s16 pad; void (*fn)(void *, s32); };
struct Part { char pad[0xC]; VEnt *vt; };
#include "stepguard.h"
extern "C" {
void CloneStep();
void func_00209770(void *, void *);
void CloneGuardAnimrefs(void *);
void CloneGuard(STEPGUARD *arg0, STEPGUARD *arg1) {
    Part *part = (Part *)arg0->psensor;
    CloneStep();
    func_00209770((char *)arg0 + 0xFD0, arg0);
    arg0->psensor = (SENSOR *)part;
    VEnt *vt = part->vt;
    void (*fn)(void *, s32) = vt->fn;
    fn((char *)part + vt->adj, (s32)arg1->psensor);
    CloneGuardAnimrefs(arg0);
}
}
