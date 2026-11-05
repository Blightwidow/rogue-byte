typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64;
#define NULL 0
struct Entry_2142B0 { s32 pad[5]; s32 label; };
struct Sprite_2142B0 { u16 count; u16 pad; char *entries; };
s32 FSpriteHasLabel(s32 arg0, Sprite_2142B0 *sprite, s32 label) {
    s32 i;
    s32 *p;
    if (label == -1) return 0;
    i = 0;
    if (i < sprite->count) {
        p = (s32 *)(sprite->entries + 0x14);
        do {
            i++;
            if (label == *p) return 1;
            p = (s32 *)((char *)p + 0x18);
        } while (i < sprite->count);
    }
    return 0;
}
