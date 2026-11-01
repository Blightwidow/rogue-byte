static inline float Clamp(float value, float low, float high) { float result = value > low ? value : low; return result < high ? result : high; }
static inline float fmax2(float a, float b) { float r; asm("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fmin2(float a, float b) { float r; asm("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
struct Anim217FE0 { char pad0[8]; float length; char pad1[12]; };
struct Slot217FE0 { char pad0[8]; short anim; char pad1[14]; };
struct Sprite217FE0 { char pad0[4]; Anim217FE0 *anims; Slot217FE0 *slots; };
extern "C" void SeekSpriteInstanceTime(Sprite217FE0 *, float, int, int);
extern "C" void SeekSpriteInstanceFraction(Sprite217FE0 *sprite, int index, float fraction, int arg2)
{
    float clamped = Clamp(fraction, 0.0f, 1.0f);
    int anim = sprite->slots[index].anim;
    if (anim >= 0) SeekSpriteInstanceTime(sprite, sprite->anims[anim].length * clamped, index, arg2);
}
