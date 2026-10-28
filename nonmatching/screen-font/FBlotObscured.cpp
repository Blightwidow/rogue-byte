#include "sly2.h"

typedef struct BLOT {
    char pad[0xA0];
    int unk0xA4;
    void **unk0xA8;
    void **unk0xAC;
    void **unk0xB0;
    void **unk0xB4;
} BLOT;

extern "C" void *B_003E1060;

extern "C" int FBlotObscured(void *pblot)
{
    void *cur = B_003E1060;
    if (cur == 0) {
        return 0;
    }
    while (1) {
        int a = *(int *)((char *)pblot + 0xA4);
        int b = *(int *)((char *)cur + 0xA4);
        if (a < b) {
            return 1;
        }
        cur = *(void **)((char *)cur + 0xB4);
        if (cur == 0) {
            return 0;
        }
    }
}
