typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
struct ProxySound {
    s32 id;
    f32 volume;
    f32 pitch;
    f32 positionX;
    f32 positionY;
};

struct ProxySoundOwner {
    char pad0[0xE4];
    s32 count;
    ProxySound *sounds;
};

extern "C" {
void AddProxySnd(ProxySoundOwner *owner, s32 id, s32 volume, s32 pitch, f32 positionX, f32 positionY) {
    s32 count = owner->count;
    if (count < 8) {
        ProxySound *entry = owner->sounds + count;
        owner->count = count + 1;
        entry->id = id;
        entry->volume = (f32) volume;
        entry->pitch = (f32) pitch;
        entry->positionX = positionX;
        entry->positionY = positionY;
    }
}

}
