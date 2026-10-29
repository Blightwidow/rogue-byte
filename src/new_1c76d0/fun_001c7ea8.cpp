extern "C" {
typedef int s32;
typedef short s16;
typedef void (*FnSlot_1C7EA8)(char *, s32);
void func_001CB5D0(char *);
void func_001C7EA8(char *arg0)
{
    char *temp_v0;
    FnSlot_1C7EA8 fn;
    func_001CB5D0(arg0);
    temp_v0 = *(char **)(arg0 + 0xC);
    fn = *(FnSlot_1C7EA8 *)(temp_v0 + 0x264);
    fn(arg0 + *(s16 *)(temp_v0 + 0x260), -1);
}
}
