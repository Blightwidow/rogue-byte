typedef int s32; typedef unsigned int u32; typedef signed char s8;
extern "C" {
int AddDmaBulk__4DMASiP2QW(s8 *, s32, s32);
int Align__4VIFSi(s8 *, int);
void AddVifDirect__4VIFSiP2QWi(s8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Align__4VIFSi(arg0, 3);
    u32 *slot = *(u32 **)(arg0 + 0xC);
    u32 hdr = (arg3 << 31) | 0x50000000; *(u32 **)(arg0 + 0xC) = slot + 1; *slot = arg1 | hdr;
    AddDmaBulk__4DMASiP2QW(arg0, arg1, arg2);
}
}
