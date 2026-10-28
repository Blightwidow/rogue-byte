#include "sly2.h"
struct TFT { char pad[0x20]; int size; char pad24[8]; unsigned char chConv; };

int FNegTftUl__FP3TFTP2UL(TFT *t, unsigned long *pul)
{
    int neg = 0;
    switch (t->size) {
    case 0:
        ((int *)pul)[1] = 0;
        break;
    case 1:
        *pul = *(unsigned short *)pul;
        break;
    case 2:
        break;
    }
    if (t->chConv == 'd' || t->chConv == 'i') {
        switch (t->size) {
        case 0: {
            int value = *(int *)pul;
            if (value < 0) {
                *(int *)pul = -value;
                neg = 1;
            }
            break;
        }
        case 1: {
            short value = *(short *)pul;
            if (value < 0) {
                *(unsigned short *)pul = -*(unsigned short *)pul;
                neg = 1;
            }
            break;
        }
        case 2: {
            long value = (long)*pul;
            if (value < 0) {
                *pul = (unsigned long)-value;
                neg = 1;
            }
            break;
        }
        }
    }
    return neg;
}
