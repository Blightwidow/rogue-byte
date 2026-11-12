#include "sly2.h"

extern "C" {
extern void *B_004502C8;
extern int D_002C6764;
extern void *B_004502CC;
extern void *B_004502D0;
}

int *func_00241BB8(void *p)
{
    void (*fn)(void) = (void (*)(void))B_004502C8;
    if (!fn)
        return (int *)p;
    if (D_002C6764)
        return (int *)p;
    void *tmp = B_004502CC;
    fn();
    B_004502CC = B_004502D0;
    return (int *)p;
}
