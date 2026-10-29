typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
extern "C" {
extern char B_003DD490[];
char *PloFindSwObject_thunk(char *sw, s32 kind, s32 arg2, s32 arg3);

char *PaloFindDancerAnim(s32 arg0, s32 arg1) {
    char *found;

    found = PloFindSwObject_thunk(B_003DD490, 4, arg1, arg0);
    if (found != NULL) {
        char *sub = *(char **)(found + 0xC);
        void (*callback)(char *) = *(void (**)(char *))(sub + 0x4C);
        callback(found + *(s16 *)(sub + 0x48));
    }
    return found;
}

}
