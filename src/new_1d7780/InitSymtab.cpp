extern "C" {
/* 0x1D8600: InitSymtab: store the count at +0xD4, allocate a table of arg1 16-byte entries (pair = {count * 16, 16}) and store its pointer at +0xD8 */
typedef int s32;
void *PvAllocSwImpl__Fi(s32);
void InitSymtab(char *arg0, s32 arg1) {
    s32 pair[2];
    pair[0] = arg1 << 4;
    pair[1] = 0x10;
    *(s32 *)(arg0 + 0xD4) = arg1;
    *(void **)(arg0 + 0xD8) = PvAllocSwImpl__Fi((s32)pair);
}
}
