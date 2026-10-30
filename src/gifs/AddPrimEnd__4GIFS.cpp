struct GIFS;
struct GIFS_VT { char pad[8]; short delta; short unused; void (*fn)(void *, int); };
struct GIFS { char pad[0x18]; GIFS_VT *vt; int field_0x1C; };
extern "C" void AddPrimPack__4GIFSiiUl(GIFS *, int, int, int);

extern "C" void AddPrimEnd__4GIFS(GIFS *gifs)
{
    if (gifs->field_0x1C != 0) {
        gifs->vt->fn((char *)gifs + gifs->vt->delta, 1);
        return;
    }
    AddPrimPack__4GIFSiiUl(gifs, 0, 1, 0xE);
    gifs->vt->fn((char *)gifs + gifs->vt->delta, 1);
}
