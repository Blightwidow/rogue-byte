#include "sly2.h"
typedef signed char s8;
extern "C" {
QW ConvertXfPos(int, int, QW);
void InvalidateXfmMatWorld(s8 *);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
}
extern "C" void TranslateXfmToPos(s8 *arg0, QW pos)
{
    s8 *matrix = arg0 + 0x60;
    QW local = ConvertXfPos(0, *(int *)(arg0 + 0x50), pos);
    __as__6VECTORG9VU_VECTOR(arg0 + 0x90, local);
    *(float *)(matrix + 0x3C) = 1.0f;
    InvalidateXfmMatWorld(arg0);
}
