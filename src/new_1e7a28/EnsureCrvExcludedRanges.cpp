typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {

s32 PvAllocSwClearImpl__Fi(s32 *info);
s32 BuildCrvExcludedRanges(s32 ranges, char *owner);

void EnsureCrvExcludedRanges(char *arg0) {
    /* Two-word argument block; the frame keeps the full 16 bytes. */
    s32 info[4];
    s32 allocated;

    if (*(s32 *)(arg0 + 0x180) == 0) {
        info[0] = 0x9C;
        info[1] = 0x10;
        allocated = PvAllocSwClearImpl__Fi(info);
        *(s32 *)(arg0 + 0x180) = allocated;
        BuildCrvExcludedRanges(allocated, arg0);
    }
}

}
