typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {

void AddTaskAnim(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 count;
    s32 *entry;

    if (*(s32 *)(arg0 + 0x50) == 0) {
        count = *(s32 *)(arg0 + 0xB0);
        if (count < 0x20) {
            *(s32 *)(arg0 + 0xB0) = count + 1;
            entry = (s32 *)(*(char **)(arg0 + 0xB4) + count * 0x18);
            entry[0] = arg1;
            entry[1] = arg2;
            entry[2] = arg3;
            entry[3] = arg4;
            entry[4] = arg5;
            entry[5] = arg6;
        }
    }
}

}
