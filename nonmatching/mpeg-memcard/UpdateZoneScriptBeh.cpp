#include "types.h"
#include "vu0inline.h"
#include "ps2inline.h"

struct ZoneSgs { char pad[0xE8]; int firstHandle; int secondHandle; };
struct ZoneOwner {
    char pad0[0xF64];
    ZoneSgs *sgs;
    char pad1[0x1070 - 0xF68];
    float curve[3];
    float pad2;
    float lowLimit;
    float highLimit;
    float reach;
};
struct ZoneScript {
    int pad0[4];
    ZoneOwner *owner;
    int pad1[7];
    int state;
    float timeStamp;
};

extern "C" {
void func_001EEF98();
int func_001EF0A8(ZoneScript *);
int FIsGuardInSgs(ZoneOwner *, int);
QW PosLoWorld(void *);
int func_00227C90(int, QW);
void SetZoneScriptState(ZoneScript *, int);
char *func_00205458(ZoneOwner *, int);
extern float g_2dded0;
extern void *g_2e1e40;

void UpdateZoneScriptBeh(ZoneScript *self)
{
    QW origin;
    func_001EEF98();
    while (func_001EF0A8(self) == 0) {
        int previousState = self->state;
        switch (previousState) {
        case 0:
            if (func_00227C90(self->owner->sgs->secondHandle, PosLoWorld(g_2e1e40)) == 0)
                SetZoneScriptState(self, 1);
            break;
        case 1:
            if (func_00227C90(self->owner->sgs->firstHandle, PosLoWorld(g_2e1e40)) != 0)
                SetZoneScriptState(self, 0);
            else if (self->owner->reach < g_2dded0 - self->timeStamp)
                SetZoneScriptState(self, 2);
            break;
        case 2:
            break;
        }
        if (previousState == self->state)
            break;
    }
    if (self->state == 0 && FIsGuardInSgs(self->owner, 9) != 0) {
        origin = PosLoWorld(self->owner);
        QW other = PosLoWorld(g_2e1e40);
        ZoneOwner *owner = self->owner;
        float distance = LaneX(SqrtX(SquaredLengthXy(VectorSub(origin, other))));
        float *coefficients = owner->curve;
        float value = owner->curve[0] + distance * (coefficients[1] + distance * coefficients[2]);
        float result;
        if (value < owner->lowLimit)
            result = owner->lowLimit;
        else if (owner->highLimit < value)
            result = owner->highLimit;
        else
            result = value;
        char *first = func_00205458(self->owner, 0xA7);
        char *second = func_00205458(self->owner, 0xB8);
        if (first != 0)
            *(float *)(first + 0xC4) = result;
        else if (second != 0)
            *(float *)(second + 0x38) = result;
    }
}
}
