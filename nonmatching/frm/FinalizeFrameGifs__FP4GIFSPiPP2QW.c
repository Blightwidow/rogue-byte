#include "m2c_macros.h"

M2C_UNK AddDmaEnd__4DMAS(s32);                      /* extern */
M2C_UNK AddPrimEnd__4GIFS(s32);                     /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK Detach__4DMASPiPP2QW(s32, s32, s32);        /* extern */
M2C_UNK PackAD__4GIFSll(s32, M2C_UNK, M2C_UNK);     /* extern */

void FinalizeFrameGifs__FP4GIFSPiPP2QW(s32 arg0, s32 arg1, s32 arg2) {
    AddPrimPack__4GIFSiiUl(0, 1, 0xE);
    PackAD__4GIFSll(arg0, 0x61, 0);
    AddPrimEnd__4GIFS(arg0);
    AddDmaEnd__4DMAS(arg0);
    Detach__4DMASPiPP2QW(arg0, arg1, arg2);
}
