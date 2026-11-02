#include "sly2.h"
struct GIFS_211528 { char pad[0x30]; };
extern "C" {
void AddPrimBulk__4GIFSiiiUlPP2QW(GIFS_211528 *, int, int, int, unsigned long, QW **);
void AddPrimEnd__4GIFS(GIFS_211528 *);
void AddPrimPack__4GIFSiiUl(GIFS_211528 *, int, int, unsigned long);
void AllocStatic__4DMASiP2QW(GIFS_211528 *, int, void *);
void PackAD__4GIFSll(GIFS_211528 *, long, long);
void __4GIFS(GIFS_211528 *);
extern long B_002DEBF0;
extern char B_004421B0[];
extern char B_00442210[];
extern char B_00442240[];
extern char B_004424B0[];
extern char B_004424D0[];
extern char B_004424F0[];
extern char B_00442520[];
extern char B_00442560[];
extern char B_004425A0[];
extern long g_2dece0;
extern int g_2dedb0;
}
extern "C" void func_00211528(void)
{
    GIFS_211528 gifsBulk;
    __4GIFS(&gifsBulk);
    char *pb = B_004421B0;
    long *tag = (long *)(pb - 0x10);
    AllocStatic__4DMASiP2QW(&gifsBulk, 7, pb);
    *(long *)(pb - 0x10) = 0x8000L << 45;
    tag[1] = 5;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x44, 0, 1, 1, 0);
    tag[2] |= 1;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x84, 0, 1, 1, 0);
    tag[4] |= 1;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x45, 0, 1, 1, 0);
    tag[6] |= 1;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x85, 0, 1, 1, 0);
    tag[8] |= 1;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x42, 0, 1, 1, 0);
    tag[10] |= 1;
    AddPrimBulk__4GIFSiiiUlPP2QW(&gifsBulk, 0x82, 0, 1, 1, 0);
    tag[12] |= 1;

    GIFS_211528 gifsClut;
    __4GIFS(&gifsClut);
    AllocStatic__4DMASiP2QW(&gifsClut, 0x27, B_00442240);
    AddPrimPack__4GIFSiiUl(&gifsClut, 0x46, 1, 0xE);
    PackAD__4GIFSll(&gifsClut, 0x4A, 1);
    PackAD__4GIFSll(&gifsClut, 0x42, 0x4A);
    PackAD__4GIFSll(&gifsClut, 0x47, 0x31001);
    for (int y = 0; y < 0x200; y += 0x20) {
        PackAD__4GIFSll(&gifsClut, 5, (0x7000 + y * 0x10) | 0x79000000L);
        PackAD__4GIFSll(&gifsClut, 5, (0x7200 + y * 0x10) | 0x87000000L);
    }
    PackAD__4GIFSll(&gifsClut, 0x4A, 0);
    PackAD__4GIFSll(&gifsClut, 0x42, 0x44);
    PackAD__4GIFSll(&gifsClut, 0x47, 0x50000);
    AddPrimEnd__4GIFS(&gifsClut);

    GIFS_211528 gifsDither;
    __4GIFS(&gifsDither);
    long *pdimx = (g_2dedb0 & 1) ? &g_2dece0 : &B_002DEBF0;
    long dimx = *pdimx;
    AllocStatic__4DMASiP2QW(&gifsDither, 3, B_00442210);
    AddPrimPack__4GIFSiiUl(&gifsDither, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsDither, 0x3F, 0);
    PackAD__4GIFSll(&gifsDither, 0x4E, (dimx & 0x1FF) | 0x3A000000);
    AddPrimEnd__4GIFS(&gifsDither);

    GIFS_211528 gifsA;
    __4GIFS(&gifsA);
    AllocStatic__4DMASiP2QW(&gifsA, 2, B_004424B0);
    AddPrimPack__4GIFSiiUl(&gifsA, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsA, 0x4C, 0);
    AddPrimEnd__4GIFS(&gifsA);

    GIFS_211528 gifsB;
    __4GIFS(&gifsB);
    AllocStatic__4DMASiP2QW(&gifsB, 2, B_004424D0);
    AddPrimPack__4GIFSiiUl(&gifsB, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsB, 0x4C, -1L << 0x38);
    AddPrimEnd__4GIFS(&gifsB);

    GIFS_211528 gifsC;
    __4GIFS(&gifsC);
    AllocStatic__4DMASiP2QW(&gifsC, 4, B_00442560);
    AddPrimPack__4GIFSiiUl(&gifsC, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsC, 0x4A, 0);
    PackAD__4GIFSll(&gifsC, 0x42, 0x44);
    PackAD__4GIFSll(&gifsC, 0x47, 0x50000);
    AddPrimEnd__4GIFS(&gifsC);

    GIFS_211528 gifsD;
    __4GIFS(&gifsD);
    AllocStatic__4DMASiP2QW(&gifsD, 3, B_004425A0);
    AddPrimPack__4GIFSiiUl(&gifsD, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsD, 0x42, 0x44);
    PackAD__4GIFSll(&gifsD, 0x47, 0x74000);
    AddPrimEnd__4GIFS(&gifsD);

    GIFS_211528 gifsE;
    __4GIFS(&gifsE);
    AllocStatic__4DMASiP2QW(&gifsE, 3, B_004424F0);
    AddPrimPack__4GIFSiiUl(&gifsE, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsE, 0x42, 0x4A);
    PackAD__4GIFSll(&gifsE, 0x47, 0x30000);
    AddPrimEnd__4GIFS(&gifsE);

    GIFS_211528 gifsF;
    __4GIFS(&gifsF);
    AllocStatic__4DMASiP2QW(&gifsF, 4, B_00442520);
    AddPrimPack__4GIFSiiUl(&gifsF, 0, 1, 0xE);
    PackAD__4GIFSll(&gifsF, 0x4A, 1);
    PackAD__4GIFSll(&gifsF, 0x42, 0x4A);
    PackAD__4GIFSll(&gifsF, 0x47, 0x31001);
    AddPrimEnd__4GIFS(&gifsF);
}
