extern "C" {
typedef int s32;
typedef short s16;
typedef float f32;
void WakeXf(s32, void *, f32);

void func_001F8830(void *arg0, f32 fparg0) {
    char *target = *(char **)((char *)arg0 + 0x24);
    *(s16 *)(target + 0xAE) = (s16)(fparg0 * 1000.0f);
    WakeXf(*(s32 *)((char *)arg0 + 0x20), *(void **)((char *)arg0 + 0x24), fparg0 * 1000.0f);
}
}
