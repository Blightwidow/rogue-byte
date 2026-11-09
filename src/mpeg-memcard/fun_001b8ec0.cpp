#include "types.h"
struct Murray {
    char pad0[0x150]; struct Target *target;
    char pad154[0x1030 - 0x154]; int jumper0;
    char pad1034[0x1840 - 0x1034]; int state; float stateTime;
    char pad1848[0x1900 - 0x1848]; int jumper; char pad1904[4]; int flag1908;
    char pad190c[0x1AC0 - 0x190C]; int flag1AC0;
};
struct Target { char pad[0x1C]; float speed; char pad20[0x60]; int kind; };
extern "C" {
extern float g_2dded0;
extern float RO_002C0A30, RO_002C0A34;
static inline float Ld(const float *p) { return *p; }
int FAsegaGone(int);
int FJumperDone(int);
void SetMurrayState(Murray *, int);
void UpdateJumper(int);
void func_001B8D30(Murray *, int);
void func_001B8EC0(Murray *self) {
    int previous;
    for (;;) {
        previous = self->state;
        switch (previous) {
        case 0:
            if (self->jumper0 == 0 || FAsegaGone(self->jumper0) != 0) func_001B8D30(self, 1);
            break;
        case 1:
            if (self->jumper0 == 0 || FAsegaGone(self->jumper0) != 0) {
                SetMurrayState(self, 0);
            } else if (self->flag1908 != 0) {
                func_001B8D30(self, 2);
            } else if (self->flag1AC0 == 0 && Ld(&RO_002C0A30) < g_2dded0 - self->stateTime) {
                func_001B8D30(self, 3);
            }
            break;
        case 2:
            if (self->jumper == 0 || FJumperDone(self->jumper) != 0) {
                if (self->flag1AC0 != 0) func_001B8D30(self, 0);
                else SetMurrayState(self, 0);
            } else {
                UpdateJumper(self->jumper);
            }
            break;
        case 3:
            if (self->jumper0 == 0 || FAsegaGone(self->jumper0) != 0) {
                SetMurrayState(self, 0);
            } else if (Ld(&RO_002C0A34) < g_2dded0 - self->stateTime) {
                Target *target = self->target;
                if (target->kind == 1 && target->speed > 0.0f) SetMurrayState(self, 0);
            }
            break;
        }
        if (self->state != previous) { if (self->state != -1) continue; }
        break;
    }
}
}
