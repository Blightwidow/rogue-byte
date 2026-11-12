extern "C" {
struct Payload_238F38 { unsigned char bytes[0xFC]; };
struct Command_238F38 { int command; int size; char pad8[0xFC]; Payload_238F38 data; };
int func_00238D70(void);
int func_00238E70(void);
void *memcpy(void *, const void *, unsigned int);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern Command_238F38 B_0044C040;
extern char B_0044C240[];
int func_00238F38(int command, int size, void *data, int *output) {
    if (func_00238D70() < 0) {
        return -0x10000;
    }
    if (func_00238E70() != 0) {
        return -0x10004;
    }
    B_0044C040.command = command;
    if (data != 0) {
        if (size >= 0xFD) {
            B_0044C040.data = *(Payload_238F38 *)data;
            B_0044C040.size = 0xFC;
        } else {
            memcpy(&B_0044C040.data, data, size);
            B_0044C040.size = size;
        }
    } else {
        B_0044C040.size = 0;
    }
    if (sceSifCallRpc(B_0044C240, 6, 0, &B_0044C040, 0x200, &B_0044C040, 8, 0, 0) < 0) {
        return -0x10001;
    }
    int status = B_0044C040.command;
    *output = B_0044C040.size;
    return status;
}
}
