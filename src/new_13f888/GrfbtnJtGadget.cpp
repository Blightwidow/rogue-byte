extern "C" {
extern unsigned D_002C3258[];
}

struct JTENTRY_141EA8 { int nKey; int pad[2]; };

extern "C" unsigned GrfbtnJtGadget(char *pThis, int nKey)
{
    struct JTENTRY_141EA8 *pEntry = (struct JTENTRY_141EA8 *)(pThis + 0x1180);
    unsigned *pFlags = D_002C3258;
    unsigned accumulated = 0;
    int nRemain = 2;
    do {
        if (nKey == pEntry->nKey) {
            accumulated |= *pFlags;
        }
        pFlags++;
        pEntry++;
        nRemain--;
    } while (nRemain >= 0);
    return accumulated;
}
