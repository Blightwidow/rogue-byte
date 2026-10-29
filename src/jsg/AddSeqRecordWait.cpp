typedef int s32;
typedef signed char s8;
extern "C" {
s8 *PjsgeAllocJsg(void *, s32, s32);

void AddSeqRecordWait(void *arg0, s32 arg1, s32 arg2) {
    s8 *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 4, 0);
    *(s32 *)(temp_v0 + 0x10) = arg1;
    *(s32 *)(temp_v0 + 0x14) = arg2;
}

}
