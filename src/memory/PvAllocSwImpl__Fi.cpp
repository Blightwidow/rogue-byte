typedef int s32;
extern "C" {
void CheckForOutOfMemory__Fv(s32);
extern s32 g_2f6384;

s32 PvAllocSwImpl__Fi(s32 *arg0) {
    if (arg0[0] != 0) {
        CheckForOutOfMemory__Fv(arg0[0]);
        s32 align = arg0[1];
        s32 top = g_2f6384 - 1; s32 aligned = (top + align) & -align;
        g_2f6384 = aligned + ((arg0[0] + 0xF) & -0x10);
        return aligned;
    }
    return 0;
}
}
