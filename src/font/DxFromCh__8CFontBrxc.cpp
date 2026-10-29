extern "C" void *PglyffFromCh__8CFontBrxc(char *, unsigned char);

float DxFromCh__8CFontBrxc(char *arg0, unsigned char arg1) {
    char *temp_v0;

    temp_v0 = (char *)PglyffFromCh__8CFontBrxc(arg0, arg1);
    if (temp_v0 != 0) {
        return (float)(*(unsigned short *)(temp_v0 + 0x6) + 1) * *(float *)(arg0 + 0x10);
    }
    return *(float *)(arg0 + 0x10) * (float)*(int *)(arg0 + 0x8);
}
