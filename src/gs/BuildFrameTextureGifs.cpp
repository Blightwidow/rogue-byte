struct GIFS { char pad[0x30]; };
struct QW;
extern "C" void __4GIFS(GIFS *);
extern "C" void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddPrimEnd__4GIFS(GIFS *);
extern "C" char B_002DEBE0, g_2decd0, B_002DFB00, B_002DFB20;
extern "C" int g_2dedb0;
extern "C" void BuildFrameTextureGifs(void)
{
    unsigned long *current;
    unsigned long *other;
    if (g_2dedb0 & 1) {
        current = (unsigned long *)&B_002DEBE0;
        other = (unsigned long *)((char *)current + 0xF0);
    } else {
        current = (unsigned long *)&g_2decd0;
        other = (unsigned long *)((char *)current - 0xF0);
    }
    GIFS gifsA;
    __4GIFS(&gifsA);
    AllocStatic__4DMASiP2QW(&gifsA, 2, (QW *)&B_002DFB00);
    AddPrimPack__4GIFSiiUl(&gifsA, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsA, 7, (*current & 0x1FF) << 5 | (*current >> 16 & 0x3F) << 14 | 0x6A8000000UL);
    AddPrimEnd__4GIFS(&gifsA);
    GIFS gifsB;
    __4GIFS(&gifsB);
    AllocStatic__4DMASiP2QW(&gifsB, 2, (QW *)&B_002DFB20);
    AddPrimPack__4GIFSiiUl(&gifsB, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsB, 7, (*other & 0x1FF) << 5 | (*other >> 16 & 0x3F) << 14 | 0x6A8000000UL);
    AddPrimEnd__4GIFS(&gifsB);
}
