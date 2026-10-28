#include "m2c_macros.h"

M2C_UNK AddPrimPack__4GIFSiiUl(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(void *, s32, s32);  /* extern */
M2C_UNK EndPrim__4GIFSi(void *, M2C_UNK);           /* extern */
M2C_UNK PackAD__4GIFSll(void *, M2C_UNK, s32);      /* extern */
M2C_UNK __4GIFS(void *);                            /* extern */

void BuildFbaGif(s32 arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    __4GIFS(sp);
    AllocStatic__4DMASiP2QW(sp, arg0, arg1);
    AddPrimPack__4GIFSiiUl(sp, 0, 1, 0xE);
    PackAD__4GIFSll(sp, 0x4A, arg2);
    EndPrim__4GIFSi(sp, 1);
}
