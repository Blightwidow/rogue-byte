extern "C" {
typedef signed char s8; typedef short s16; typedef int s32;

s32 sceMcRead(s32, s32, s32);
s32 McSync(s32, s32, s32, s32);

s32 McRead(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return McSync((s32)(arg0 + 0xFD5C), sceMcRead(arg1, arg2, arg3), 5, arg4);
}

}
