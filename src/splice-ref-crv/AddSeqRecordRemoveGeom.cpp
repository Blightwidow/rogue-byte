extern "C" {
char *PjsgeAllocJsg(int arg0, int arg1, int arg2);

void AddSeqRecordRemoveGeom(int arg0, int arg1, int arg2)
{
    char *temp_v0;

    temp_v0 = PjsgeAllocJsg(arg0, 0x2F, 1);
    *(int *)(temp_v0 + 0x10) = arg1;
    *(int *)(temp_v0 + 0x14) = arg2;
}
}
