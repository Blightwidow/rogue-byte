typedef struct McClient {
    int pad00[9];
    int server;
    int pad28[7];
} McClient;

typedef struct McWriteRequest {
    int fd;
    int pad04[2];
    int tailSize;
    int pad10;
    int headLength;
    int tailPointer;
    int pad1C;
    unsigned char data[0x10];
} McWriteRequest;

extern McClient B_00450880;
extern McWriteRequest B_00450900;
extern int B_00451E40[];
extern int D_002C8350;
extern int D_002C8354;

extern int PollSema(int semaphoreId);
extern int SignalSema(int semaphoreId);
extern void FlushCache(int mode);
extern void func_00243ED8(void *);
extern int sceSifCallRpc(void *client, int rpcNumber, int callMode, void *sendBuffer, int sendSize,
                         void *recvBuffer, int recvSize, void *endFunction, void *endParam);

int sceMcWrite(int fd, unsigned char *buffer, int size)
{
    unsigned int index;
    int result;
    unsigned char *alignedEnd;
    unsigned char *headBase;
    int offset;

    if (B_00450880.server == 0)
        return -0x64;
    if (PollSema(D_002C8354) < 0)
        return -0xC8;
    B_00450900.fd = fd;
    if (size < 0x11) {
        B_00450900.headLength = size;
        B_00450900.tailSize = 0;
        B_00450900.tailPointer = 0;
    } else {
        alignedEnd = (unsigned char *)(((unsigned int)buffer - 1) & 0xFFFFFFF0);
        headBase = buffer - 0x10;
        offset = alignedEnd - headBase;
        B_00450900.tailSize = size - offset;
        B_00450900.headLength = offset;
        B_00450900.tailPointer = (int)(buffer + offset);
    }
    for (index = 0; index < (unsigned int)B_00450900.headLength; index++)
        B_00450900.data[index] = buffer[index];
    FlushCache(0);
    result = sceSifCallRpc(&B_00450880, 6, 1, &B_00450900, 0x30, B_00451E40, 4, (void *)func_00243ED8, 0);
    if (result != 0) {
        SignalSema(D_002C8354);
        return -0x5B;
    }
    D_002C8350 = 6;
    return 0;
}
