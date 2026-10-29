typedef int s32;
typedef signed char s8;
extern "C" {
s8 *PjsgeAllocJsg(void *, s32, s32);

void AddSeqRecordPlayGuardScript(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0x55, arg3);
    *(s32 *)(temp_v0 + 0x10) = arg1;
    *(s32 *)(temp_v0 + 0x14) = arg2;
}

}
