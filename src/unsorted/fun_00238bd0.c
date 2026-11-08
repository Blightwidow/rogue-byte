struct RpcClientData {
    int words[9];
    int serverReady;
};
extern struct RpcClientData B_0044BE80;
extern int D_002C4A94;
extern int sceSifBindRpc(struct RpcClientData *client, unsigned int number, unsigned int mode);

int func_00238BD0(void)
{
    int count;
    while (1) {
        if (sceSifBindRpc(&B_0044BE80, 0x80000003, 0) < 0) {
            return -1;
        }
        if (B_0044BE80.serverReady != 0) {
            D_002C4A94 = 0;
            break;
        }
        count = 0x100000;
        while (count-- != 0) {
        }
    }
    return 0;
}
