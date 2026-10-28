struct GIFS { char pad[0x30]; };
struct MAT { char pad[0x24]; int ctex; };
struct MATREF { char pad[4]; unsigned short flags; short pad2; MAT *pmat; };
void *memset(void *, int, unsigned int);
extern "C" long func_001EA6C8(MATREF *, int, int);
extern "C" void PackAD__4GIFSll(GIFS *, long, long);
struct TEX1 { unsigned long lcm : 1; unsigned long pad0 : 4; unsigned long mmag : 1; unsigned long mmin : 3; };
struct CLAMP { unsigned long wms : 2; unsigned long wmt : 2; };
extern "C" void func_001EA750(MATREF *pref, int pass, GIFS *pgifs)
{
    TEX1 tex1;
    CLAMP clamp;
    MAT *pmat = pref->pmat;
    for (int itex = pmat->ctex - 1; itex >= 0; itex--)
        PackAD__4GIFSll(pgifs, 6, func_001EA6C8(pref, itex, pass));
    memset(&tex1, 0, 8);
    tex1.lcm = 1;
    if (pass == 2) {
        tex1.mmag = 0;
        tex1.mmin = 0;
    } else {
        tex1.mmag = 1;
        tex1.mmin = 1;
    }
    PackAD__4GIFSll(pgifs, 0x14, *(long *)&tex1);
    memset(&clamp, 0, 8);
    if (pref->flags & 1)
        clamp.wms = 1;
    if (pref->flags & 2)
        clamp.wmt = 1;
    PackAD__4GIFSll(pgifs, 8, *(long *)&clamp);
}
