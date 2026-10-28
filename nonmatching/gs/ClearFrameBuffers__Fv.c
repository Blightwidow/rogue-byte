#include "m2c_macros.h"

M2C_UNK AddDmaEnd__4DMAS(void *);                   /* extern */
M2C_UNK AddDmaRefs__4DMASiP2QW(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK BlastAqwGifsBothFrames__FP2QW(M2C_UNK *);   /* extern */
M2C_UNK Detach__4DMASPiPP2QW(void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK __4DMAS(void *);                            /* extern */
extern M2C_UNK B_002DF260;

void ClearFrameBuffers__Fv(void) {
    char sp[0x400];
    M2C_UNK sp20;

    __4DMAS(sp);
    AllocStatic__4DMASiP2QW(sp, 2, &sp20);
    AddDmaRefs__4DMASiP2QW(sp, 0x25, &B_002DF260);
    AddDmaEnd__4DMAS(sp);
    Detach__4DMASPiPP2QW(sp, 0, 0);
    BlastAqwGifsBothFrames__FP2QW(&sp20);
}
