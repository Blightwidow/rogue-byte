struct VTENTRY { short delta; short unused; void (*fn)(void *); };
struct ALO_VT { char pad[0x40]; VTENTRY slot_0x40; VTENTRY slot_0x48; };
struct ALO { char pad[0xC]; ALO_VT *vt; char pad10[0x12C - 0x10]; float alpha; };
extern "C" int FIsBasicDerivedFrom(ALO *, int);

extern "C" void SetAloAlpha(ALO *alo, float alpha)
{
    if (alpha <= 0.0f) {
        if (FIsBasicDerivedFrom(alo, 0x69) == 0)
            alo->vt->slot_0x48.fn((char *)alo + alo->vt->slot_0x48.delta);
    } else {
        alo->vt->slot_0x40.fn((char *)alo + alo->vt->slot_0x40.delta);
    }
    alo->alpha = alpha;
}
