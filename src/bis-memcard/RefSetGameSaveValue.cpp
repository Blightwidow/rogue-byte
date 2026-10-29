typedef int s32;
extern "C" {
void RefSetSaveValue(s32, void *, s32, s32, s32);
extern int B_003E0EA8;

s32 RefSetGameSaveValue(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    RefSetSaveValue(arg0, &B_003E0EA8, arg1, arg2, arg3);
    return arg0;
}

}
