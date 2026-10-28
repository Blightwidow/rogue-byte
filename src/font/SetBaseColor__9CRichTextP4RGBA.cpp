struct RGBA { unsigned char r, g, b, a; };
struct CRichText { char pad0[0x154]; RGBA colorA; char pad1[4]; RGBA colorB; };
extern "C" void SetBaseColor__9CRichTextP4RGBA(CRichText *self, RGBA *color)
{
    self->colorB = *color;
    self->colorA = self->colorB;
}
