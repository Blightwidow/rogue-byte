typedef int s32;
extern "C" {
s32 FAsegaGone(s32);
s32 GetSmaCur(s32);
s32 GetSmaGoal(s32);
s32 func_0017F550(char *arg0) {
    s32 current;
    s32 difference;
    s32 result;

    if (*(s32 *)(arg0 + 0x194) != 0) {
        return FAsegaGone(*(s32 *)(arg0 + 0x194));
    }
    result = 1;
    if (*(s32 *)(arg0 + 0x198) != 0) {
        current = GetSmaCur(*(s32 *)(arg0 + 0x198));
        difference = current ^ GetSmaGoal(*(s32 *)(arg0 + 0x198));
        result = difference == 0;
    }
    return result;
}
}
