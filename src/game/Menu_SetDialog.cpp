#include "sly2.h"
extern "C" float g_2ddf0c;
extern "C" float D_002C3254;
extern "C" void *NewEmitter(int);
extern "C" void SetEmitterUnpositioned(void *, int);
extern "C" void Menu_SetDialog(char *self, int kind, int arg)
{
    *(int *)(self + 0x38) = arg;
    *(int *)(self + 0x30) = kind;
    if (kind == 0) goto zero;
    if (kind > 0) goto general;
    if (kind != -1) goto general;
    *(float *)(self + 0x34) = -10.0f;
    return;
zero:
    *(float *)(self + 0x34) = 3.402823466e+38f;
    SetEmitterUnpositioned(NewEmitter(0x29), 0);
    return;
general:
    *(float *)(self + 0x34) = g_2ddf0c + D_002C3254;
    SetEmitterUnpositioned(NewEmitter(0x36), 0);
}
