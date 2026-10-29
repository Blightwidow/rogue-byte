typedef signed char s8; typedef int s32;
extern "C" {
void AppendSlEntry(void *, s8 *);
void ResetVjoy();
extern char B_003E133C;
extern char D_002CA240;

s8 *VJOY_constructor(s8 *arg0, s32 arg1) {
    *(s32*)(arg0) = 0;
    *(s32*)(arg0+4) = 0;
    *(char**)(arg0+0xC) = &D_002CA240;
    ResetVjoy();
    *(s32*)(arg0+0x80) = -1;
    *(s32*)(arg0+0x7C) = arg1;
    AppendSlEntry(&B_003E133C, arg0);
    return arg0;
}
}
