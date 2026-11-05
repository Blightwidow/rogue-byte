struct Bytes8 { char bytes[8]; };
struct SPIRE { char pad0[0x100]; Bytes8 saved; };
extern "C" void CloneXfm(SPIRE *, SPIRE *);
extern "C" void CloneSpire__FP5SPIRET0(SPIRE *self, SPIRE *other)
{
    Bytes8 saved = self->saved;
    CloneXfm(self, other);
    self->saved = saved;
}
