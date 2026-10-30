struct VT_213830 { char pad[0xA8]; short delta; short unused; void (*fn)(void *, int); };
struct Obj_213830 { char pad0[0xC]; VT_213830 *vt; char pad1[0x7C - 0x10]; int a7c; int a80; int a84; char pad2[0xAC - 0x88]; int aac; };
extern "C" {
void PlayRootSpriteLabel(int);
void SetBlotModal(void *, int);
void PlayBlotLabel(Obj_213830 *self, int arg1) {
    PlayRootSpriteLabel(self->a84);
    self->vt->fn((char *)self + self->vt->delta, 1);
    if (self->aac != 0) {
        SetBlotModal(self, 0);
    }
    self->a7c = arg1;
}
}
