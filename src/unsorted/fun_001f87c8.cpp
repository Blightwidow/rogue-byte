extern "C" {
/* 0x1F87C8: scale arg (float, in $f12) by 1000 into the s16 at obj->0x24->0xAC, then WakeXf(obj->0x20, obj->0x24) */
typedef int s32;
typedef short s16;
void WakeXf(void *, void *);
void func_001F87C8(void *arg0, float arg1) {
    s16 scaled = (s16)(arg1 * 1000.0f);
    *(s16 *)((char *)*(void **)((char *)arg0 + 0x24) + 0xAC) = scaled;
    WakeXf(*(void **)((char *)arg0 + 0x20), *(void **)((char *)arg0 + 0x24));
}
}
