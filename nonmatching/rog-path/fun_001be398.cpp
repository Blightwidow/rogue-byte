#include "sly2.h"
struct GIFS { char pad[0x30]; };
struct Pool { int f0, f4, top; };
struct Target { int w, h; long tex; int f10, f14, f18, f1c; };
extern "C" {
void __4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS *, long, long);
void PackXYZ__4GIFSiii(GIFS *, int, int, int);
void AddPrimEnd__4GIFS(GIFS *);
void DMAS_DetachCopyPermanent(GIFS *, int *, int, int *);
int AllocZpr(Pool *, int);
int NLog2__FUi(unsigned);
}
extern "C" void func_001BE398(Target *target, Pool *pool)
{
    int tile = 0x40;
    target->w = 0x80;
    target->h = 0x80;
    int tiles = target->w / tile;
    int addr = AllocZpr(pool, 0x100);
    target->tex = (long)(((((target->tex & ~0x3FFFL) | (addr & 0x3FFF)) & 0xFFFFFFFFFFF03FFFL) | 0x8000) & 0xFFFFFFFFFC0FFFFFL);
    target->tex = (target->tex & 0xFFFFFFFFC3FFFFFFL) | ((long)(NLog2__FUi(target->w) & 0xF) << 26);
    target->tex = (target->tex & ~(0xFL << 30)) | ((long)(NLog2__FUi(target->h) & 0xF) << 30) | (0x8000L << 19);
    int base = (pool->top - 0x100) >> 5;
    GIFS gifs;
    QW buf[0x40];
    __4GIFS(&gifs);
    int x0 = 0x800 - target->w / 2;
    int y0 = 0x800 - target->h / 2;
    int x = x0;
    AllocStatic__4DMASiP2QW(&gifs, 0x40, buf);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    int span = target->w > 0x40 ? target->w : 0x40;
    PackAD__4GIFSll(&gifs, 0x4C, (addr >> 5) | ((long)(span / 0x40) << 16));
    PackAD__4GIFSll(&gifs, 0x4E, base | 0x30000000);
    PackAD__4GIFSll(&gifs, 0x18, (x0 * 0x10) | ((long)(y0 * 0x10) << 32));
    PackAD__4GIFSll(&gifs, 0x40, ((long)(target->w - 1) << 16) | ((long)(target->h - 1) << 48));
    PackAD__4GIFSll(&gifs, 0x47, 0x30000);
    PackAD__4GIFSll(&gifs, 1, 0);
    AddPrimPack__4GIFSiiUl(&gifs, 6, 1, 5);
    if (x < x + target->w) {
        do {
            PackXYZ__4GIFSiii(&gifs, x * 0x10, y0 * 0x10, 0);
            x += 0x20;
            PackXYZ__4GIFSiii(&gifs, x * 0x10, (y0 + target->h) * 0x10, 0);
        } while (x < x0 + target->w);
    }
    AddPrimEnd__4GIFS(&gifs);
    DMAS_DetachCopyPermanent(&gifs, &target->f10, 0, &target->f14);
    AllocStatic__4DMASiP2QW(&gifs, 0x40, buf);
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    PackAD__4GIFSll(&gifs, 6, target->tex);
    PackAD__4GIFSll(&gifs, 0x14, 0x60);
    PackAD__4GIFSll(&gifs, 8, 5);
    AddPrimEnd__4GIFS(&gifs);
    DMAS_DetachCopyPermanent(&gifs, &target->f18, 0, &target->f1c);
}
