// SPDX-License-Identifier: GPL-3.0-or-later
struct GLOBSET; struct CBinaryInputStream;
struct GLOB { char pad[0x14]; };
struct GLOBI { char pad[0x28]; };
struct BND { char pad[0x18]; };
extern "C" void func_00169AC8(GLOBSET *, GLOB *, GLOBI *, BND *, GLOB *, GLOBI *, BND *, int, const int *, const unsigned *, CBinaryInputStream *);
extern "C" void func_001699E8(GLOBSET *set, GLOB *glob, GLOBI *globi, BND *bnd, int cdup, int cbatch, const int *acbatch, const unsigned *apbatch, CBinaryInputStream *pbis)
{
    BND *cur = bnd;
    int left = cdup;
    for (int index = 0; left > 0; index++, left--) {
        cur++;
        func_00169AC8(set, glob, globi, bnd, glob + (index + 1), globi + (index + 1), bnd ? cur : 0, cbatch, acbatch, apbatch, pbis);
    }
}
