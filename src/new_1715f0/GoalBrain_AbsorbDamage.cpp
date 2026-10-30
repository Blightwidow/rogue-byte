struct Absorb_176B80 { int a; int pad4; int c; int d; int e; char rest[0x4C]; };
struct Brain_176B80 { char pad[0x10]; int owner; };
extern "C" {
void PaloAbsorbWkr(Absorb_176B80 *);
void *memset(void *, int, unsigned);
void GoalBrain_AbsorbDamage(Brain_176B80 *self, int arg1, int arg2) {
    Absorb_176B80 request __attribute__((aligned(16)));
    memset(&request, 0, 0x60);
    request.a = arg2;
    request.e = arg1;
    request.d = 0x40000;
    request.c = self->owner;
    PaloAbsorbWkr(&request);
}
}
