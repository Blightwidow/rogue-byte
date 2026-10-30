extern "C" {
char *PjsgeAllocJsg(void *self, int type, int flag);
void AddSeqRecordSetSmGoal(void *self, int arg1, int arg2, int arg3, int flag, int arg5) {
    char *jsg = PjsgeAllocJsg(self, 0xD, flag);
    *(int *)(jsg + 0x10) = arg1;
    *(int *)(jsg + 0x14) = arg2;
    *(int *)(jsg + 0x18) = arg3;
    *(int *)(jsg + 0x1C) = arg5;
    if (arg5 != 0) {
        *(int *)(jsg + 4) = 1;
    }
}
}
