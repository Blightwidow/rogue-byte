extern "C" void *memset(void *, int, unsigned);
extern float g_2dded0;
struct ABS_20D108 { int a; int pad4; int b; int c; int d; char rest[0x60 - 0x14]; };
struct FALL_20D108 { char pad0[4]; int state; float timer; };
extern "C" void PaloAbsorbWkr(ABS_20D108 *);
extern "C" void SetFallCheckState(int *self, int state);
void SetFallCheckState(int *self, int state)
{
    ABS_20D108 absorb;
    FALL_20D108 *fall = (FALL_20D108 *)self;
    if (*(int *)((char *)self + 4) != state) {
        *(int *)((char *)self + 4) = state;
        *(float *)((char *)self + 8) = g_2dded0;
        if (state == 2) {
            memset(&absorb, 0, 0x60);
            int owner = *self;
            absorb.a = owner;
            absorb.b = owner;
            absorb.c = 0x4000;
            absorb.d = 0;
            PaloAbsorbWkr(&absorb);
        }
    }
}
