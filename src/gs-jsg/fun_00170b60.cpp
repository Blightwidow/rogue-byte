extern "C" {
/* 0x170B60: allocate a 0x10-byte command (type 1) and copy the 8-byte payload into its upper half */
typedef struct Payload8_170B60 { unsigned char bytes[8]; } Payload8_170B60;
void *PcmdAllocScript(void *, int, int);
void func_00170B60(void *arg0, const void *arg1) {
    char *command = (char *)PcmdAllocScript(arg0, 1, -1);
    *(Payload8_170B60 *)(command + 8) = *(const Payload8_170B60 *)arg1;
}
}
