#include "sly2.h"
extern "C" void AddPrimPack__4GIFSiiUl(int, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(int, int, long);
extern "C" void AddPrimList__4GIFSiUl(int, int, unsigned long);
extern "C" void ListUV__4GIFSii(int, int, int);
extern "C" void GIFS_ListXYZ(int, int, int, int);
extern "C" void func_0016D698(int, int, int);
extern "C" void func_0016D6C8(int pgifs, int flags, int arg2)
{
    AddPrimPack__4GIFSiiUl(pgifs, 0x200, 1, 0xE);
    func_0016D698((flags & 4) ? 4 : 5, pgifs, arg2);
    if (flags & 0x200) {
        PackAD__4GIFSll(pgifs, 0x4D, ((0xFFFCL << 20) | 0x8000L) << 10);
    } else if (flags & 0x100) {
        PackAD__4GIFSll(pgifs, 0x4D, ((-0x80000000L << 5) | 0x8000L) << 10);
    } else {
        unsigned int mask = (flags & 0x800000) ? 0x7FFFFFFF : 0xFFFFFFFF;
        if (flags & 0x400000)
            mask &= 0xFF7FFFFF;
        if (flags & 0x200000)
            mask &= 0xFFBFFFFF;
        if (flags & 0x100000)
            mask &= 0xFFDFFFFF;
        if (flags & 0x80000)
            mask &= 0xFFEFFFFF;
        if (flags & 0x40000)
            mask &= 0xFFF0FFFF;
        if (flags & 0x20000)
            mask &= 0xFFFF7FFF;
        long value = (long)mask << 32;
        if (flags & 0x10000) {
            mask &= 0xFFFFBFFF;
            value = (long)mask << 32;
        }
        PackAD__4GIFSll(pgifs, 0x4D, value | 0x02000000);
    }
    func_0016D698((flags & 1) ? 6 : 7, pgifs, arg2);
    PackAD__4GIFSll(pgifs, 7, 0xEA82L << 20);
    PackAD__4GIFSll(pgifs, 0x15, 1);
    PackAD__4GIFSll(pgifs, 0x3F, 0);
    PackAD__4GIFSll(pgifs, 0x45, 0);
    PackAD__4GIFSll(pgifs, 0x19, 0);
    PackAD__4GIFSll(pgifs, 0x41, ((0xE000L << 31) | 0x8000L) << 10);
    PackAD__4GIFSll(pgifs, 0x48, 0x31001);
    PackAD__4GIFSll(pgifs, 0x43, 0x2A);
    PackAD__4GIFSll(pgifs, 0x3B, 0x8000L << 24);
    PackAD__4GIFSll(pgifs, 1, (0xC040L << 17) | 0x8080L);
    PackAD__4GIFSll(pgifs, 0, 0x356);
    AddPrimList__4GIFSiUl(pgifs, 4, 0x5353);
    int column = (flags & 0x40) ? 0 : 8;
    if (column < 0x200) {
        int row = ((flags & 0x10) ? 0 : 8) * 0x10;
        int uvA = row + 8;
        int xyzB = column * 0x10 + 0x80;
        int uvB = row + 0x88;
        do {
            int current = uvA;
            uvA += 0x100;
            ListUV__4GIFSii(pgifs, current, 8);
            GIFS_ListXYZ(pgifs, column * 0x10, 0, 0);
            column += 0x10;
            int currentB = uvB;
            uvB += 0x100;
            ListUV__4GIFSii(pgifs, currentB, 0x1C08);
            GIFS_ListXYZ(pgifs, xyzB, 0x1C00, 0);
            xyzB += 0x100;
        } while (column < 0x200);
    }
    AddPrimPack__4GIFSiiUl(pgifs, 0x200, 1, 0xE);
    PackAD__4GIFSll(pgifs, 0x41, ((0xE000L << 30) | 0x8000L) << 10);
}
