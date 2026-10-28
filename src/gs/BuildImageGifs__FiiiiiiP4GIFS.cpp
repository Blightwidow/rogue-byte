// SPDX-License-Identifier: GPL-3.0-or-later
struct GIFS { char pad[0x30]; };
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
extern "C" void AddImage__4GIFSi(GIFS *, int);
void BuildImageGifs(int dbp, int dbw, int dpsm, int w, int h, int cqw, GIFS *pgifs)
{
    AddPrimPack__4GIFSiiUl(pgifs, 0, 1, 0xE);
    PackAD__4GIFSll(pgifs, 0x50, (long)dbp << 32 | (long)dbw << 48 | (long)dpsm << 56);
    PackAD__4GIFSll(pgifs, 0x51, 0);
    PackAD__4GIFSll(pgifs, 0x52, (long)w | (long)h << 32);
    PackAD__4GIFSll(pgifs, 0x53, 0);
    AddImage__4GIFSi(pgifs, cqw);
}
