extern "C" {
char *PjsgeAllocJsg(int arg0, int arg1, int arg2);

void AddSeqRecordCallSequence(int arg0, int arg1, int arg2, int arg3)
{
    char *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0xB, arg3);
    *(int *)(temp_v0 + 0x10) = arg1;
    *(int *)(temp_v0 + 0x14) = arg2;
}
}
