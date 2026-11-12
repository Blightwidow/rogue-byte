#include "ps2inline.h"
typedef struct {
    u64 frame1;
    u64 frame1Address;
    u64 zbuf1;
    u64 zbuf1Address;
    u64 xyoffset1;
    u64 xyoffset1Address;
    u64 scissor1;
    u64 scissor1Address;
    u64 field40;
    u64 field40Address;
    u64 field50;
    u64 field50Address;
    u64 field60;
    u64 field60Address;
    u64 test1;
    u64 test1Address;
} DrawEnv;

extern short sceGszbufaddr(short psm, short width, short height);

int sceGsSetDefDrawEnv(DrawEnv *env, short psm, short width, short height, short ztest, short zpsm)
{
    u64 offsetY;
    u64 offsetX;
    env->frame1Address = 0x4C;
    env->frame1 = (u64)(((width + 63) >> 6) & 0x3F) << 16 | (u64)(psm & 0xF) << 24;
    env->zbuf1Address = 0x4E;
    if (ztest == 0) {
        env->zbuf1 = (u64)sceGszbufaddr(psm, width, height) | (u64)(zpsm & 0xF) << 24 | 0x100000000UL;
    } else {
        env->zbuf1 = (u64)sceGszbufaddr(psm, width, height) | (u64)(zpsm & 0xF) << 24;
    }
    offsetX = (0x800 - (long)(short)(width >> 1)) << 4;
    offsetY = (0x800 - (long)(short)(height >> 1)) << 36;
    env->xyoffset1Address = 0x18;
    env->xyoffset1 = offsetX | offsetY;
    env->scissor1Address = 0x40;
    env->scissor1 = (u64)(width - 1) << 16 | (u64)(height - 1) << 48;
    env->field40Address = 0x1A;
    env->field40 |= 1;
    env->field50Address = 0x46;
    env->field50 |= 1;
    env->field60Address = 0x45;
    if (psm & 2) {
        env->field60 |= 1;
    } else {
        env->field60 &= ~1UL;
    }
    env->test1Address = 0x47;
    if (ztest != 0) {
        env->test1 = (u64)(ztest & 3) << 17 | 0x10000;
    } else {
        env->test1 = 0x30000;
    }
    MemoryBarrier();
    return 8;
}
