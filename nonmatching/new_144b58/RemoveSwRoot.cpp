typedef int s32; typedef signed char s8;
extern "C" {
s32 FFindDlEntry(s32);
void RemoveDlEntry(s32, s8 *);
void RemoveSwRoot(s8 *arg0, s8 *arg1) {
    s32 temp_s2 = (s32)(arg0 + 0x20);
    if (FFindDlEntry(temp_s2) != 0) {
        if (*(s8 **)(arg0 + 0x39A4) == arg1) {
            *(s8 **)(arg0 + 0x39A4) = *(s8 **)(arg1 + 4);
        }
        RemoveDlEntry(temp_s2, arg1);
    }
}
}
