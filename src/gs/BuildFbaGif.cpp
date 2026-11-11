#include "types.h"
extern "C" {
void AddPrimPack__4GIFSiiUl(char *, s32, s32, s32);
void AllocStatic__4DMASiP2QW(char *, s32, s32);
void EndPrim__4GIFSi(char *, s32);
void PackAD__4GIFSll(char *, s32, s32);
void __4GIFS(char *);
void BuildFbaGif(s32 count, s32 buffer, s32 value) {
    char gifs[0x30] __attribute__((aligned(16)));
    __4GIFS(gifs);
    AllocStatic__4DMASiP2QW(gifs, count, buffer);
    AddPrimPack__4GIFSiiUl(gifs, 0, 1, 0xE);
    PackAD__4GIFSll(gifs, 0x4A, value);
    EndPrim__4GIFSi(gifs, 1);
}
}
