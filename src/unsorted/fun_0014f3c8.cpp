#include "sly2.h"
struct M4 { QW row[4]; };
extern "C" {
void SetCmPosMat(void *, M4 *);
void *__as__6VECTORG9VU_VECTOR(void *, QW);
void func_0014F3C8(char *arg0, QW pos)
{
    M4 matrix;
    matrix.row[0] = *(QW *)(arg0 + 0x60);
    matrix.row[1] = *(QW *)(arg0 + 0x70);
    matrix.row[2] = *(QW *)(arg0 + 0x80);
    matrix.row[3] = *(QW *)(arg0 + 0x90);
    __as__6VECTORG9VU_VECTOR(&matrix.row[3], pos);
    ((float *)&matrix)[15] = 1.0f;
    SetCmPosMat(arg0, &matrix);
}
}
