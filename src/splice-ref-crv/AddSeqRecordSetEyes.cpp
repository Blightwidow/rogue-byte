extern "C" {
extern char *PjsgeAllocJsg(void *, int, int);

void AddSeqRecordSetEyes(char *jsg, int arg1, int arg2, float fparg0) {
    char *temp_v0;

    temp_v0 = PjsgeAllocJsg(jsg, 0x35, 1);
    *(int *)(temp_v0 + 0x10) = arg1;
    *(int *)(temp_v0 + 0x14) = arg2;
    *(float *)(temp_v0 + 0x18) = fparg0;
}
}
