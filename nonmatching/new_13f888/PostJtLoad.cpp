#include "sly2.h"
struct UL { unsigned long v; } __attribute__((packed));
struct SwWorld { char pad0[0x3BF4]; unsigned flags; char pad3bf8[0x3D58 - 0x3BF8]; int serial; };
struct SlotEntry { short adjust; short pad; void (*function)(void *, ...); };
struct SwObject { char pad0[0xC]; char *vtable; };
struct AllocRequest { int size; int align; };
struct ObjectEntry { void *object; int pad; };
struct Jt {
    char pad0[0xC]; char *vtable;
    char pad10[0x44]; char *body;
    char pad58[0x1088 - 0x58]; int alert; int pad108c; ObjectEntry *objects; int objectCount;
};
extern "C" {
void PostStepLoad();
void SetSoProperties(void *, int, void *);
void func_001959C0(void *);
void LoadAttach(void *);
void func_0019F3F0(void *);
void PostJtLoadZap__FP2JT(void *);
void PostBinocLoad(void *);
void CarryThrow_EnsureBlends(void *);
void PostJtLoadPipe(void *);
int CploFindSwObjects_thunk(SwWorld *, int, int, void *, int, void **);
void *PvAllocSwClearImpl__Fi(AllocRequest *);
void LoadJtGadgetSlots(void *);
void bevy_player_p18_gadget_refill(void *, int);
int PalertEnsure(void *);
void SetSoMass__FP2SOf(void *, float);
QW PosLoWorld(void *);
char *PmatLoWorld(void *);
void QueueSwCallback(SwWorld *, void *, unsigned long, int);
extern SwWorld B_003DD490;
extern char D_002BC9F0[];
extern const UL RO_002A4D10;
}
#define SLOT(object, offset) ((SlotEntry *)((object)->vtable + (offset)))
void PostJtLoad(Jt *self)
{
    void *found[16];
    AllocRequest request;
    QW saved[3];
    PostStepLoad();
    SetSoProperties(self, 0x35, D_002BC9F0);
    func_001959C0((char *)self + 0x2C0);
    LoadAttach((char *)self + 0x4C0);
    func_0019F3F0((char *)self + 0x9E0);
    PostJtLoadZap__FP2JT((char *)self + 0xDF0);
    PostBinocLoad((char *)self + 0xF00);
    CarryThrow_EnsureBlends((char *)self + 0x11B0);
    PostJtLoadPipe((char *)self + 0xF50);
    int count = CploFindSwObjects_thunk(&B_003DD490, 0x401, 0x2AB, self, 0x10, found);
    if (count != 0) {
        AllocRequest *pointer = &request;
        pointer->size = count * 8;
        self->objectCount = count;
        pointer->align = 0x10;
        self->objects = (ObjectEntry *)PvAllocSwClearImpl__Fi(pointer);
        for (int index = 0; index < count; index++) {
            self->objects[index].object = found[index];
            SwObject *object = (SwObject *)self->objects[index].object;
            SlotEntry *slot = SLOT(object, 0x48);
            slot->function((char *)object + slot->adjust);
        }
    }
    SlotEntry *slot = SLOT(self, 0x278);
    slot->function((char *)self + slot->adjust, 0);
    slot = SLOT(self, 0x340);
    slot->function((char *)self + slot->adjust);
    LoadJtGadgetSlots(self);
    bevy_player_p18_gadget_refill(self, B_003DD490.flags & 4);
    self->alert = PalertEnsure(self);
    SetSoMass__FP2SOf(self, 0.25f);
    if (*(int *)(self->body + 0x94) == 0) {
        QW position = PosLoWorld(self);
        char *matrix = PmatLoWorld(self);
        saved[0] = *(QW *)matrix;
        saved[1] = *(QW *)(matrix + 0x10);
        saved[2] = *(QW *)(matrix + 0x20);
        char *body = self->body;
        memset(body, 0, 0x40);
        *(float *)(body + 0x0) = 1.0f;
        *(float *)(body + 0x3C) = 1.0f;
        *(float *)(body + 0x28) = 1.0f;
        *(float *)(body + 0x14) = 1.0f;
        int serial = B_003DD490.serial + 1;
        B_003DD490.serial = serial;
        *(int *)(self->body + 0xA4) = serial;
        char *vtable = self->vtable;
        slot = (SlotEntry *)(vtable + 0x90);
        slot->function((char *)self + slot->adjust, vtable);
        slot = SLOT(self, 0xE8);
        slot->function((char *)self + slot->adjust, position);
        slot = SLOT(self, 0xF0);
        slot->function((char *)self + slot->adjust, saved);
    }
    QueueSwCallback(&B_003DD490, self, RO_002A4D10.v, 0);
}
