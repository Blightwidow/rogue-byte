extern "C" {
struct Rgba { unsigned char r, g, b, a; };
void CopyBmpHeader(void *, void *);
void CopyPaletteHeader(void *, void *, int, int, int, int, int, int);
void CreateSlotheapSwAlign(void *, int, int, int);
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_002DD500[], B_002DD520[], B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];
extern Rgba RO_0029A7C0[];
extern char RO_0027A778[], RO_0029A790[];

static inline void Grey(Rgba *entry, int alpha) {
    entry->r = 0x67;
    entry->g = 0x67;
    entry->b = 0x67;
    entry->a = alpha;
}

void InitStaticBitmapA(int flag, int id) {
    if (id == 0xFFFF && flag != 0) {
        Rgba *entry = RO_0029A7C0;
        entry->r = 0;
        entry->a = 0xF;
        entry->g = 0;
        entry->b = 0;
        Grey(++entry, 0x7D);
        Grey(++entry, 0x54);
        Grey(++entry, 0x3F);
        Grey(++entry, 0x2A);
        Grey(++entry, 0x76);
        Grey(++entry, 0x6E);
        Grey(++entry, 0x1F);
        Grey(++entry, 0x4D);
        Grey(++entry, 0x80);
        Grey(++entry, 0x47);
        Grey(++entry, 0x12);
        Grey(++entry, 0x60);
        Grey(++entry, 0x36);
        ++entry;
        entry->a = 0x80;
        entry->r = 0;
        entry->g = 0;
        entry->b = 0;
        ++entry;
        entry->b = 0x67;
        entry->r = 0x67;
        entry->g = 0x67;
        entry->a = 0;
        CopyPaletteHeader(B_002DD500, RO_0027A778, 0x3F, 0x2A, 0x76, 0x6E, 0x1F, 0x4D);
        CopyBmpHeader(B_002DD520, RO_0029A790);
        if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
        if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
        if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
        if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
        if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
        if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
    }
}
}
