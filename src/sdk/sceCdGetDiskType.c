extern int D_002C676C;
extern int D_002C7940;
extern int D_002C82C0;

extern int func_00241F98(int mode);
extern int sceSifCallRpc(int *client, int rpcNumber, int callMode, int *sendBuffer, int sendSize,
                         int *recvBuffer, int recvSize, void *endFunction, void *endParam);
extern void SignalSema(int semaphoreId);

int sceCdGetDiskType(void)
{
    int result;

    if (func_00241F98(1) == 0)
        return -1;
    result = sceSifCallRpc(&D_002C82C0, 3, 0, 0, 0, &D_002C7940, 4, 0, 0);
    if (result < 0) {
        SignalSema(D_002C676C);
        return -1;
    }
    result = *(int *)((unsigned int)&D_002C7940 | 0x20000000);
    SignalSema(D_002C676C);
    return result;
}
