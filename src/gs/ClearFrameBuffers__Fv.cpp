#include "types.h"
extern "C" {
void AddDmaEnd__4DMAS(char *);
void AddDmaRefs__4DMASiP2QW(char *, s32, void *);
void AllocStatic__4DMASiP2QW(char *, s32, void *);
void BlastAqwGifsBothFrames__FP2QW(void *);
void Detach__4DMASPiPP2QW(char *, s32, s32);
void __4DMAS(char *);
extern char B_002DF260[];

void ClearFrameBuffers__Fv(void) {
    char dmas[0x40] __attribute__((aligned(16)));

    __4DMAS(dmas);
    AllocStatic__4DMASiP2QW(dmas, 2, dmas + 0x20);
    AddDmaRefs__4DMASiP2QW(dmas, 0x25, B_002DF260);
    AddDmaEnd__4DMAS(dmas);
    Detach__4DMASPiPP2QW(dmas, 0, 0);
    BlastAqwGifsBothFrames__FP2QW(dmas + 0x20);
}

}
