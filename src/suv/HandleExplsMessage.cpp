typedef int s32;
extern "C" {
s32 UnsubscribeLoObject(s32 object, char *owner);
void HandleExplsMessage(char *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 1) {
        if (arg2 == *(s32 *)(arg0 + 0x100)) {
            UnsubscribeLoObject(arg2, arg0);
            *(s32 *)(arg0 + 0x100) = 0;
        } else if (arg2 == *(s32 *)(arg0 + 0x104)) {
            UnsubscribeLoObject(arg2, arg0);
            *(s32 *)(arg0 + 0x104) = 0;
        }
    }
}
}
