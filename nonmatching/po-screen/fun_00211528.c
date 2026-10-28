#include "m2c_macros.h"

M2C_UNK AddPrimBulk__4GIFSiiiUlPP2QW(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AddPrimEnd__4GIFS(M2C_UNK *);               /* extern */
M2C_UNK AddPrimPack__4GIFSiiUl(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK AllocStatic__4DMASiP2QW(M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK PackAD__4GIFSll(M2C_UNK *, M2C_UNK, s64);   /* extern */
M2C_UNK __4GIFS(M2C_UNK *);                         /* extern */
extern s64 B_002DEBF0;
extern M2C_UNK B_004421B0;
extern M2C_UNK B_00442210;
extern M2C_UNK B_00442240;
extern M2C_UNK B_004424B0;
extern M2C_UNK B_004424D0;
extern M2C_UNK B_004424F0;
extern M2C_UNK B_00442520;
extern M2C_UNK B_00442560;
extern M2C_UNK B_004425A0;
extern s64 g_2dece0;
extern s32 g_2dedb0;

void func_00211528(void) {
    char sp[0x400];
    M2C_UNK sp30;
    M2C_UNK sp60;
    M2C_UNK sp90;
    M2C_UNK spC0;
    M2C_UNK spF0;
    M2C_UNK sp120;
    M2C_UNK sp150;
    M2C_UNK sp180;
    M2C_UNK *sp1B0;
    M2C_UNK *sp1B4;
    s32 sp1B8;
    s32 var_s4;
    s32 var_s5;
    s64 *var_v0;
    s64 temp_a2;
    s64 temp_a2_2;
    s64 temp_s0;
    void *temp_s1;

    var_s4 = 0x1E0;
    var_s5 = 0x7000;
    __4GIFS(sp);
    temp_s1 = &B_004421B0 - 0x10;
    AllocStatic__4DMASiP2QW(sp, 7, &B_004421B0);
    M2C_FIELD(&B_004421B0, s64 *, -0x10) = (s64) (0x8000 << 0x2D);
    M2C_FIELD(temp_s1, s64 *, 8) = 5;
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x44, 0, 1);
    M2C_FIELD(temp_s1, s64 *, 0x10) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x10) | 1);
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x84, 0, 1);
    M2C_FIELD(temp_s1, s64 *, 0x20) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x20) | 1);
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x45, 0, 1);
    M2C_FIELD(temp_s1, s64 *, 0x30) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x30) | 1);
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x85, 0, 1);
    M2C_FIELD(temp_s1, s64 *, 0x40) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x40) | 1);
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x42, 0, 1);
    sp1B8 = 0x7200;
    M2C_FIELD(temp_s1, s64 *, 0x50) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x50) | 1);
    AddPrimBulk__4GIFSiiiUlPP2QW(sp, 0x82, 0, 1);
    M2C_FIELD(temp_s1, s64 *, 0x60) = (s64) (M2C_FIELD(temp_s1, s64 *, 0x60) | 1);
    __4GIFS(&sp30);
    AllocStatic__4DMASiP2QW(&sp30, 0x27, &B_00442240);
    AddPrimPack__4GIFSiiUl(&sp30, 0x46, 1, 0xE);
    PackAD__4GIFSll(&sp30, 0x4A, 1);
    PackAD__4GIFSll(&sp30, 0x42, 0x4A);
    PackAD__4GIFSll(&sp30, 0x47, 0x31001);
    sp1B0 = &sp120;
    sp1B4 = &sp150;
    do {
        temp_a2 = var_s5 | 0x79000000;
        var_s5 += 0x200;
        PackAD__4GIFSll(&sp30, 5, temp_a2);
        var_s4 -= 0x20;
        temp_a2_2 = sp1B8 | (0x8700 << 0x10);
        sp1B8 += 0x200;
        PackAD__4GIFSll(&sp30, 5, temp_a2_2);
    } while (var_s4 >= 0);
    PackAD__4GIFSll(&sp30, 0x4A, 0);
    PackAD__4GIFSll(&sp30, 0x42, 0x44);
    PackAD__4GIFSll(&sp30, 0x47, 0x50000);
    AddPrimEnd__4GIFS(&sp30);
    __4GIFS(&sp60);
    if (g_2dedb0 & 1) {
        var_v0 = &g_2dece0;
    } else {
        var_v0 = &B_002DEBF0;
    }
    temp_s0 = *var_v0;
    AllocStatic__4DMASiP2QW(&sp60, 3, &B_00442210);
    AddPrimPack__4GIFSiiUl(&sp60, 0, 1, 0xE);
    PackAD__4GIFSll(&sp60, 0x3F, 0);
    PackAD__4GIFSll(&sp60, 0x4E, (temp_s0 & 0x1FF) | 0x3A000000);
    AddPrimEnd__4GIFS(&sp60);
    __4GIFS(&sp90);
    AllocStatic__4DMASiP2QW(&sp90, 2, &B_004424B0);
    AddPrimPack__4GIFSiiUl(&sp90, 0, 1, 0xE);
    PackAD__4GIFSll(&sp90, 0x4C, 0);
    AddPrimEnd__4GIFS(&sp90);
    __4GIFS(&spC0);
    AllocStatic__4DMASiP2QW(&spC0, 2, &B_004424D0);
    AddPrimPack__4GIFSiiUl(&spC0, 0, 1, 0xE);
    PackAD__4GIFSll(&spC0, 0x4C, -1 << 0x38);
    AddPrimEnd__4GIFS(&spC0);
    __4GIFS(&spF0);
    AllocStatic__4DMASiP2QW(&spF0, 4, &B_00442560);
    AddPrimPack__4GIFSiiUl(&spF0, 0, 1, 0xE);
    PackAD__4GIFSll(&spF0, 0x4A, 0);
    PackAD__4GIFSll(&spF0, 0x42, 0x44);
    PackAD__4GIFSll(&spF0, 0x47, 0x50000);
    AddPrimEnd__4GIFS(&spF0);
    __4GIFS(sp1B0);
    AllocStatic__4DMASiP2QW(sp1B0, 3, &B_004425A0);
    AddPrimPack__4GIFSiiUl(sp1B0, 0, 1, 0xE);
    PackAD__4GIFSll(sp1B0, 0x42, 0x44);
    PackAD__4GIFSll(sp1B0, 0x47, 0x74000);
    AddPrimEnd__4GIFS(sp1B0);
    __4GIFS(sp1B4);
    AllocStatic__4DMASiP2QW(sp1B4, 3, &B_004424F0);
    AddPrimPack__4GIFSiiUl(sp1B4, 0, 1, 0xE);
    PackAD__4GIFSll(sp1B4, 0x42, 0x4A);
    PackAD__4GIFSll(sp1B4, 0x47, 0x30000);
    AddPrimEnd__4GIFS(sp1B4);
    __4GIFS(&sp180);
    AllocStatic__4DMASiP2QW(&sp180, 4, &B_00442520);
    AddPrimPack__4GIFSiiUl(&sp180, 0, 1, 0xE);
    PackAD__4GIFSll(&sp180, 0x4A, 1);
    PackAD__4GIFSll(&sp180, 0x42, 0x4A);
    PackAD__4GIFSll(&sp180, 0x47, 0x31001);
    AddPrimEnd__4GIFS(&sp180);
}
