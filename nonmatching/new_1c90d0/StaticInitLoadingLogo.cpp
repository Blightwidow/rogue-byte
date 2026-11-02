typedef unsigned char u8;
extern "C" void *memset(void *, int, unsigned long);
extern "C" void CreateSlotheapSwAlign(void *, int, int, int);
struct Col { u8 r, g, b, a; };
struct Entry { int id; const char *name; Col c; };
extern Entry B_003D3A00[5];
extern char RO_002C1740[], RO_002C19C0[], RO_002C1AC8[], RO_002C1B50[], RO_002C1BD8[];
extern int B_002DD2E0, B_002DD2E4, B_002DD2E8, B_002DD2EC, B_002DD2F0, B_002DD2F4;
extern char B_004520A8[], B_004520D0[], B_004520F8[], B_00452120[], B_00452148[], B_00452170[];

void StaticInitLoadingLogo(int arg0, int arg1) {
    if (arg1 == 0xFFFF && arg0 != 0) {
        Entry *p = B_003D3A00;
        u8 *q;
        memset(p, 0, 12);
        p->id = 0x35; q = (u8 *)p + 8; p->name = RO_002C1740; p->c.r = 0x2F;
        q[1] = 0x3A; q[3] = 0x7F; q[2] = 0x7F;
        p++;
        memset(p, 0, 12);
        p->id = 0x16; q = (u8 *)p + 8; p->name = RO_002C19C0; p->c.r = 0x2F;
        q[1] = 0x3A; q[3] = 0x7F; q[2] = 0x7F;
        p++;
        memset(p, 0, 12);
        p->id = 0xB; q = (u8 *)p + 8; p->name = RO_002C1AC8; p->c.r = 0x5F;
        q[3] = 0x7F; q[1] = 0x5F; q[2] = 0x5F;
        p++;
        memset(p, 0, 12);
        p->id = 0xB; q = (u8 *)p + 8; p->name = RO_002C1B50; p->c.r = 0x5F;
        q[3] = 0x7F; q[1] = 0x5F; q[2] = 0x5F;
        p++;
        memset(p, 0, 12);
        p->id = 0x3E; q = (u8 *)p + 8; p->name = RO_002C1BD8; p->c.r = 0x5F;
        q[3] = 0x7F; q[2] = 0x5F; q[1] = 0x5F;
        if (++B_002DD2E0 == 1) CreateSlotheapSwAlign(B_004520A8, 0x14, 0x2000, 0x10);
        if (++B_002DD2E4 == 1) CreateSlotheapSwAlign(B_004520D0, 0x18, 0x800, 0x10);
        if (++B_002DD2E8 == 1) CreateSlotheapSwAlign(B_004520F8, 0x28, 0x200, 0x10);
        if (++B_002DD2EC == 1) CreateSlotheapSwAlign(B_00452120, 0x1C, 0x800, 0x10);
        if (++B_002DD2F0 == 1) CreateSlotheapSwAlign(B_00452148, 0xC, 0xC8, 0x10);
        if (++B_002DD2F4 == 1) CreateSlotheapSwAlign(B_00452170, 0x14, 0x100, 0x10);
    }
}
