typedef int s32;
extern "C" {
extern int *D_002BE080[];
extern int *D_002BE1B8[];
s32 LabelFromEpselMode(char *arg0) {
    s32 mode = *(s32 *)(arg0 + 0x11C);
    if (mode == -1) return -1;
    if (mode == 8) {
        s32 sub = *(s32 *)(arg0 + 0x120);
        if (sub != -1)
            return D_002BE1B8[*(s32 *)(arg0 + 0x128)][sub];
    }
    return D_002BE080[*(s32 *)(arg0 + 0x110)][*(s32 *)(arg0 + 0x11C)];
}
}
