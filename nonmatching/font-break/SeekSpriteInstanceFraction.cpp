struct Anim217FE0 { char pad0[8]; float length; char pad1[12]; };
struct Slot217FE0 { char pad0[8]; short anim; char pad1[14]; };
struct Sprite217FE0 { char pad0[4]; Anim217FE0 *anims; Slot217FE0 *slots; };
extern "C" void SeekSpriteInstanceTime(Sprite217FE0 *, float, int, int);
extern "C" void SeekSpriteInstanceFraction(Sprite217FE0 *sprite, int index, float fraction, int arg2)
{
    float lowered = 0.0f;
    lowered = lowered < fraction ? fraction : lowered;
    float clamped = lowered < 1.0f ? lowered : 1.0f;
    int anim = sprite->slots[index].anim;
    if (anim >= 0) SeekSpriteInstanceTime(sprite, sprite->anims[anim].length * clamped, index, arg2);
}
