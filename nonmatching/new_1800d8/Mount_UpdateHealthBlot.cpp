extern "C" void SeekBlotLabel(void*, int, float);
struct Mount { char pad0[0x180]; int hpMax; int hp; char pad1[0x2A0 - 0x188]; void* blot; };
extern "C" void Mount_UpdateHealthBlot(Mount* self)
{
    if (self->blot) {
        int hp = self->hp;
        if (hp < 1) hp = 0;
        float lost = 1.0f - (float)hp / (float)self->hpMax;
        if (lost < 0.0f) lost = 0.0f;
        else if (1.0f < lost) lost = 1.0f;
        SeekBlotLabel(self->blot, 0x34F, lost);
    }
}
