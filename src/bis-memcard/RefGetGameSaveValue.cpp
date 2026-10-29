extern "C" {
/* 0x2581C0: forwards its arguments to RefGetSaveValue with the global object, returns arg0 */
typedef int s32;
extern int B_003E0EA8;
void RefGetSaveValue(void *, void *, s32, s32);
s32 RefGetGameSaveValue(s32 arg0, s32 arg1, s32 arg2) {
    RefGetSaveValue((void *)arg0, &B_003E0EA8, arg1, arg2);
    return arg0;
}
}
