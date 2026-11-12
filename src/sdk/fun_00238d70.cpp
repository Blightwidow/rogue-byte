extern "C" {
struct SifClient {
    char field_0x0[0x24];
    int field_0x24;
};
extern struct SifClient B_0044C240;
extern char B_0044C040[];
extern char B_0044C268[];
extern int D_002C4A98;
int sceSifBindRpc(struct SifClient *client, unsigned int rpcNumber, unsigned int mode);
int sceSifCallRpc(struct SifClient *client, int rpcNumber, int mode, void *sendBuffer, int sendSize,
                  void *receiveBuffer, int receiveSize, void *endFunction, void *endParameter);
void *memcpy(void *destination, const void *source, unsigned int count);

int func_00238D70(void) {
    int bindResult;
    int callResult;
    int spinCount;

    if (D_002C4A98 < 0) {
        for (;;) {
            bindResult = sceSifBindRpc(&B_0044C240, 0x80000006, 0);
            if (bindResult < 0) {
                return -1;
            }
            if (B_0044C240.field_0x24 != 0) {
                D_002C4A98 = 0;
                callResult = sceSifCallRpc(&B_0044C240, 0xFF, 0, 0, 0, B_0044C040, 4, 0, 0);
                if (callResult < 0) {
                    return 0xFFFEFFFF;
                }
                memcpy(B_0044C268, B_0044C040, 4);
                return 0;
            }
            spinCount = 0x100000;
            do {
                spinCount--;
            } while (spinCount != -1);
        }
    }
    return 0;
}
}
