struct GIFS { char pad[0x30]; };
struct QW;
extern "C" void __4GIFS(GIFS *);
extern "C" void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddPrimEnd__4GIFS(GIFS *);
extern "C" void BuildClearGifs__FP2QWG4RGBAi(QW *pqw, unsigned char *rgba, int clear)
{
    GIFS gifs;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 0x25, pqw);
    int prim = (*(signed char *)(rgba + 3) >= 0) ? 0x46 : 6;
    AddPrimPack__4GIFSiiUl(&gifs, prim, 1, 0xE);
    PackAD__4GIFSll(&gifs, 1, (unsigned long)rgba[0] | ((unsigned long)rgba[1] << 8) | ((unsigned long)rgba[2] << 16) | ((unsigned long)rgba[3] << 24));
    long test;
    switch (clear) {
    case 1: test = 0x31001; break;
    case 2: test = 0x32001; break;
    case 3: test = 0x30000; break;
    }
    PackAD__4GIFSll(&gifs, 0x47, test);
    PackAD__4GIFSll(&gifs, 0x42, 0x44);
    for (int x = 0; x < 0x200; x += 0x20) {
        PackAD__4GIFSll(&gifs, 5, ((x + 0x700) << 4) | (0x790L << 20));
        PackAD__4GIFSll(&gifs, 5, ((x + 0x720) << 4) | (0x870L << 20));
    }
    PackAD__4GIFSll(&gifs, 0x47, 0x70000);
    AddPrimEnd__4GIFS(&gifs);
}
