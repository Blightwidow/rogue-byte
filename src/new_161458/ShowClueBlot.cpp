#include "sly2.h"
extern "C" void func_00212A30(char *);
extern "C" void ShowClueBlot(char *arg0)
{
    char *temp_s0 = *(char **)(arg0 + 0x3BB8);
    if (temp_s0 != 0) {
        char *vtable = *(char **)(temp_s0 + 0xC);
        short offset = *(short *)(vtable + 0x188);
        void (*fn)(char *, int) = *(void (**)(char *, int))(vtable + 0x18C);
        fn(temp_s0 + offset, -1);
        func_00212A30(temp_s0);
    }
}
