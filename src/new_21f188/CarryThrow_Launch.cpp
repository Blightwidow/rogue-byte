typedef int QW __attribute__((mode(TI)));
struct Obj;
struct VT {
    char pad[0x118]; short setVelDelta; short setVelIndex; void (*setVel)(void *, QW);
    short omegaDelta; short omegaIndex; void (*setOmega)(void *, QW);
    char pad2[0x260 - 0x128]; short modeDelta; short modeIndex; void (*setMode)(void *, int);
};
struct Obj { char pad[0xC]; VT *vtable; char pad10[0x13D0 - 0x10]; int state; };
struct Display { char pad[0x48]; };
struct DisplayVT { char pad[0x48]; short delta; short index; void (*hide)(void *); };
struct DisplayObj { char pad[0xC]; DisplayVT *vtable; };
struct Carry {
    void *owner; Obj *carried; char pad8[0xF0 - 0x14 + 4];
};
struct CarryThrow {
    void *owner; char pad4[0xC]; Obj *carried;
    char pad14[0x30 - 0x14]; QW omega; char pad40[0xF0 - 0x40]; QW velocity;
    char pad100[0x12C - 0x100]; DisplayObj *display;
};
extern Obj *g_2dd5bc;
extern "C" {
int FIsBasicDerivedFrom(void *, int);
void SetSoCnstrForce(void *, int);
void SetSoCnstrTorque(void *, int);
QW bevy_camera_follow_track_heading_weight(void *, void *, QW);
void func_00136530(void *, int);
void func_001A58D0(void *, int, int);
}

struct VTE { short delta; short index; void (*fn)(void *, QW); };

extern "C" void CarryThrow_Launch(CarryThrow *carry)
{
    Obj *carried = carry->carried;
    if (carried == g_2dd5bc) {
        if (carried->state != 8)
            goto tail;
        func_00136530(carried, 1);
    } else {
        func_001A58D0(carried, 0, 3);
        SetSoCnstrForce(carry->carried, 0);
        SetSoCnstrTorque(carry->carried, 0);
    }
    {
        Obj *object = carry->carried;
        object->vtable->setVel((char *)object + object->vtable->setVelDelta, carry->velocity);
        Obj *target = carry->carried;
        VTE *entry = (VTE *)((char *)target->vtable + 0x120);
        void *self = (char *)target + entry->delta;
        QW omega = bevy_camera_follow_track_heading_weight(carry->owner, 0, carry->omega);
        entry->fn(self, omega);
        if (FIsBasicDerivedFrom(carry->carried, 0x64)) {
            Obj *flier = carry->carried;
            flier->vtable->setMode((char *)flier + flier->vtable->modeDelta, 1);
        }
    }
tail:
    DisplayObj *display = carry->display;
    if (display)
        display->vtable->hide((char *)display + display->vtable->delta);
}
