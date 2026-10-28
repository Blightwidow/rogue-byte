// SPDX-License-Identifier: GPL-3.0-or-later
struct LANGS { char b[0x38]; };
extern "C" const LANGS RO_002A69E8;
extern "C" {
void func_001A2C48(int *, int **);
void func_001A2BD0(int);
}
void func_001A2DA0(int nScf)
{
    struct { LANGS langs; int pad[2]; int clanguage; int *ailanguage; } l;
    l.langs = RO_002A69E8;
    int *pscf = (int *)&l.langs;
    for (int ilanguage = 0; ilanguage < 14; ilanguage++) {
        if (nScf == *pscf) {
            func_001A2C48(&l.clanguage, &l.ailanguage);
            for (int iEntry = 0; iEntry < l.clanguage; iEntry++) {
                if (ilanguage == l.ailanguage[iEntry]) {
                    func_001A2BD0(ilanguage);
                    return;
                }
            }
        }
        pscf++;
    }
    func_001A2BD0(-1);
}
