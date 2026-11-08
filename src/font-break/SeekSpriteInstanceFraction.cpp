struct LABEL { char pad0[8]; float dt; char pad1[0x18 - 0xC]; };
struct INST { char pad0[8]; short ilabel; char pad1[0x18 - 0xA]; };
struct SPRITE { char pad0[4]; LABEL *labels; INST *insts; };
struct Slot;
// Callee (src/font-break/SeekSpriteInstanceTime.cpp): time first in $f12, then sprite, instance, slot pointer.
extern "C" void SeekSpriteInstanceTime(float, SPRITE *, int, Slot *);

// Clamp of a value into [low, high], as an inline function with the bounds as parameters.
static inline float GClamp(float value, float low, float high)
{
    float lowered = low < value ? value : low;
    return lowered < high ? lowered : high;
}

// Retail: max.s $f0, $f0(0.0), $f12, then min.s $f0, $f1(1.0), $f0 -- the upper bound is the first
// operand. Writing the clamp inline in the body with the literal 1.0f gives min.s $f0, $f0, $f1
// (score 1); passing the bounds through an inline clamp helper makes 1.0f a parameter value, which
// gcc puts first, as retail has. Same max/min shape as the matched callee SeekSpriteInstanceTime.
extern "C" void SeekSpriteInstanceFraction(SPRITE *sprite, int iinst, float fraction, Slot *slot)
{
    float clamped = GClamp(fraction, 0.0f, 1.0f);
    int ilabel = sprite->insts[iinst].ilabel;
    if (ilabel >= 0)
        SeekSpriteInstanceTime(sprite->labels[ilabel].dt * clamped, sprite, iinst, slot);
}
