typedef long s64;
typedef unsigned long u64;
typedef float f32;
struct Timer {
    char pad0[0x68];
    s64 ticks;
};
struct CLOCK {
    char pad0[0x204];
    union Slot {
        int count;
        Timer *timer;
    } slots[1];
};
extern "C" {
f32 __floatdisf(s64);
f32 MarkClockTickRealOnly__FP5CLOCK(CLOCK *clock)
{
    int count = clock->slots[0].count;
    Timer *timer;
    if (count > 0) {
        timer = (*(CLOCK *)((char *)clock + count * 4)).slots[0].timer;
    } else {
        timer = 0;
    }
    if (timer == 0) {
        return 0.0f;
    }
    s64 ticks = timer->ticks;
    f32 value;
    if (ticks >= 0) {
        value = __floatdisf(ticks);
    } else {
        value = 2.0f * __floatdisf((ticks & 1) | ((u64)ticks >> 1));
    }
    return value * 3.390842e-9f;
}
}
