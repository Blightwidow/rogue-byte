extern "C" {
typedef int s32;
typedef unsigned char u8;
typedef struct { u8 bytes[8]; } Bytes8_170BA0;
char *PcmdAllocScript(void *arg0, s32 arg1, s32 arg2);

void func_00170BA0(void *arg0, Bytes8_170BA0 *arg1) {
    char *dest = PcmdAllocScript(arg0, 2, -1);
    *(Bytes8_170BA0 *)(dest + 8) = *arg1;
}
}
