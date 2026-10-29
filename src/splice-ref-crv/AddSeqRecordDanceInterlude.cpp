extern "C" {
/* 0x1E0880: allocate a record of kind 0x4B from the Jsg pool (arg0 passes through), store arg1 at +0x10 and arg2 at +0x14 */
typedef int s32;
char *PjsgeAllocJsg(void *, s32, s32);
void AddSeqRecordDanceInterlude(void *arg0, s32 arg1, s32 arg2) {
    char *record;
    record = PjsgeAllocJsg(arg0, 0x4B, 1);
    *(s32 *)(record + 0x10) = arg1;
    *(s32 *)(record + 0x14) = arg2;
}
}
