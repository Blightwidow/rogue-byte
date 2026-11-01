#include "sly2.h"
extern "C" MATRIX4 *__ml__FRC7MATRIX4T0(MATRIX4 *result, const MATRIX4 *mat1, const MATRIX4 *mat2)
{
    int status;
    asm volatile("lqc2 vf4, 0x30(%0)" : : "r" (mat1));
    asm volatile("lqc2 vf8, 0x30(%0)" : : "r" (mat2));
    asm volatile("lqc2 vf1, 0x0(%0)" : : "r" (mat1));
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r" (mat1));
    asm volatile("lqc2 vf3, 0x20(%0)" : : "r" (mat1));
    asm volatile("lqc2 vf5, 0x0(%0)" : : "r" (mat2));
    asm volatile("lqc2 vf6, 0x10(%0)" : : "r" (mat2));
    asm volatile("lqc2 vf7, 0x20(%0)" : : "r" (mat2));
    asm volatile("vcallms 0x60");
    asm volatile("cfc2.i %0, $vi0" : "=r" (status));
    asm volatile("sqc2 vf5, 0x0(%0)" : : "r" (result) : "memory");
    asm volatile("sqc2 vf6, 0x10(%0)" : : "r" (result) : "memory");
    asm volatile("sqc2 vf7, 0x20(%0)" : : "r" (result) : "memory");
    asm volatile("sqc2 vf8, 0x30(%0)" : : "r" (result) : "memory");
    return result;
}
