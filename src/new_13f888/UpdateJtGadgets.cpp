struct PAD141A50 { char pad[0x30]; int mask; };
struct JTVT141A50 {
    char pad[0x318];
    short delta318; short index318; int (*fn318)(char *, int);
    char pad2[0x328 - 0x320];
    short delta328; short index328; void (*fn328)(char *, void *);
};
struct SLOT141A50 { int id; int state; int pad8; };
struct JTGADGETS141A50 {
    char pad0[0xC]; JTVT141A50 *vt;
    char pad1[0x150 - 0x10]; PAD141A50 *ppad;
    char pad2[0x1180 - 0x154]; SLOT141A50 slots[3];
    char pad3[0x1304 - (0x1180 + 36)]; float tCooldown;
};
struct GADGETDEF141A50 { int id; int pad4; int pad8; int power; char rest[0x10]; };
extern "C" {
int FButtonPressedWithin(PAD141A50 *, int, float);
int GetJtPower(JTGADGETS141A50 *);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, int);
void SetJtGadgetSlotState(JTGADGETS141A50 *, SLOT141A50 *, int);
extern GADGETDEF141A50 D_002BCD00[];
extern int D_002C3258[];
extern float g_2dded0;
void UpdateJtGadgets(JTGADGETS141A50 *self)
{
    if (self->ppad) {
        for (int index = 0; index < 3; index++) {
            int button = D_002C3258[index];
            SLOT141A50 *slot = &self->slots[index];
            int gadget = slot->id;
            switch (slot->state) {
            case 0:
                if (FButtonPressedWithin(self->ppad, button, 0.15f)) {
                    JTVT141A50 *vt = self->vt;
                    if (!vt->fn318((char *)self + vt->delta318, gadget)) {
                        SetEmitterUnpositioned(NewEmitter(0x2E), 0);
                    } else if (GetJtPower(self) < D_002BCD00[gadget].power) {
                        SetEmitterUnpositioned(NewEmitter(0x2E), 0);
                        self->tCooldown = g_2dded0;
                    } else {
                        SetJtGadgetSlotState(self, slot, D_002BCD00[gadget].id);
                    }
                }
                break;
            case 1:
                if (!((self->ppad->mask & button) && self->vt->fn318((char *)self + self->vt->delta318, gadget))) {
                    SetJtGadgetSlotState(self, slot, 0);
                } else {
                    self->vt->fn328((char *)self + self->vt->delta328, slot);
                }
                break;
            }
        }
    }
}
}
