struct GIFS { int pad0; unsigned start; int pad8; unsigned end; char pad10[0x20]; };
typedef unsigned long u64;
extern "C" {
void AddDmaCall__4DMASP2QW(void *, void *);
void AddDmaCnt__4DMAS();
void AddPrimList__4GIFSiUl(GIFS *, int, unsigned long);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void AddVifBaseOffset__4VIFSii(void *, int, int);
void AddVifFlusha__4VIFS(void *);
void AddVifMscal__4VIFSPv(void *, void *);
void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
void AllocStatic__4DMASiP2QW(GIFS *, int, void *);
void EndDmaCnt__4DMAS(void *);
void EndPrim__4GIFSi(GIFS *, int);
void GIFS_ListXYZ(GIFS *, int, int, int);
void ListUV__4GIFSii(GIFS *, int, int);
void PackAD__4GIFSll(GIFS *, long, long);
void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int *, void **);
void __4GIFS(GIFS *);
void func_0016D698(int, GIFS *, void **);
void func_0016D6C8(GIFS *, int, void **);
extern char D_00001C48[];
extern char B_002DEA50[];
extern char B_002DF940[];
extern char B_002DFA80[];
struct SW_16DD58 { char pad[0x3E38]; int flag; };
extern SW_16DD58 B_003DD490;
extern long B_003E1330;
extern char *g_2dea4c;
extern int g_2deb70[2];
extern int g_2deb74;
void func_0016DD58(void *arg0, int unused, int arg2) {
    GIFS gifs;
    char buffer[0x2000] __attribute__((aligned(16)));
    void *cursorStart;
    void *cursor;
    AddDmaCnt__4DMAS();
    UnpackHelper__4VIFS3UPKiiPiPPUi(arg0, 5, 8, 0x1B, 0, &cursorStart);
    cursor = cursorStart;
    __4GIFS(&gifs);
    AllocStatic__4DMASiP2QW(&gifs, 0x200, buffer);
    if (arg2 != 8) {
        if (g_2deb74 != 0) {
            AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
            int xA = 0x7200;
            int xB = 0x7000;
            func_0016D698(0, &gifs, &cursor);
            int count = 0x1E0;
            PackAD__4GIFSll(&gifs, 0x4C, (long)(int)0xBFC00000 << 10);
            PackAD__4GIFSll(&gifs, 0x47, 0x31001);
            PackAD__4GIFSll(&gifs, 0x42, (0x8000L << 18) | 0xA9);
            PackAD__4GIFSll(&gifs, 1, 0x8000L << 17);
            PackAD__4GIFSll(&gifs, 0, 0x46);
            AddPrimList__4GIFSiUl(&gifs, 2, 0x55);
            do {
                GIFS_ListXYZ(&gifs, xB, 0x7900, 0);
                xB += 0x200;
                GIFS_ListXYZ(&gifs, xA, 0x8700, 0);
                count -= 0x20;
                xA += 0x200;
            } while (count >= 0);
        }
        func_0016D6C8(&gifs, 0x810095, &cursor);
        func_0016D6C8(&gifs, 0x266, &cursor);
    }
    AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
    func_0016D698(0, &gifs, &cursor);
    PackAD__4GIFSll(&gifs, 0x4C, 0);
    PackAD__4GIFSll(&gifs, 0x46, 1);
    if (arg2 != 8) {
        int base = 0;
        func_0016D698(2, &gifs, &cursor);
        PackAD__4GIFSll(&gifs, 6, 0xD500L << 19);
        PackAD__4GIFSll(&gifs, 0x14, 1);
        PackAD__4GIFSll(&gifs, 0x16, B_003E1330);
        PackAD__4GIFSll(&gifs, 0x3F, 0);
        PackAD__4GIFSll(&gifs, 0x47, 0x31001);
        PackAD__4GIFSll(&gifs, 1, (0xC040L << 17) | 0x8080);
        PackAD__4GIFSll(&gifs, 0x42, 0x44);
        PackAD__4GIFSll(&gifs, 0, 0x156);
        AddPrimList__4GIFSiUl(&gifs, 4, 0x5353);
        do {
            ListUV__4GIFSii(&gifs, (base * 0x10) | 8, 8);
            int next = base + 0x20;
            GIFS_ListXYZ(&gifs, (base + 0x700) * 0x10, 0x7900, 0);
            ListUV__4GIFSii(&gifs, (next * 0x10) | 8, 0xE08);
            int nextXyz = (base + 0x720) * 0x10;
            base = next;
            GIFS_ListXYZ(&gifs, nextXyz, 0x8700, 0);
        } while (base < 0x200);
    }
    EndPrim__4GIFSi(&gifs, 1);
    func_0016D698(-1, &gifs, &cursor);
    unsigned qwords = (gifs.end - gifs.start) >> 4;
    if ((int)qwords >= 0x100) {
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, 0xFF, (void *)gifs.start, 0x23);
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, ((gifs.end - gifs.start) >> 4) - 0xFF, (void *)(gifs.start + 0xFF0), 0x122);
    } else {
        AddVifUnpack__4VIFS3UPKiPvi(arg0, 0xC, qwords, (void *)gifs.start, 0x23);
    }
    AddVifFlusha__4VIFS(arg0);
    AddVifMscal__4VIFSPv(arg0, D_00001C48);
    AddVifFlusha__4VIFS(arg0);
    if (B_003DD490.flag != 0) {
        if (g_2dea4c == B_002DEA50) {
            AddDmaCall__4DMASP2QW(arg0, B_002DF940);
        } else {
            AddDmaCall__4DMASP2QW(arg0, B_002DFA80);
        }
        AddVifBaseOffset__4VIFSii(arg0, 0x32, 0x1E7);
    }
    EndDmaCnt__4DMAS(arg0);
    if (arg2 != 8) {
        g_2deb70[0] = 0;
        g_2deb70[1] = 0;
    }
}
}
