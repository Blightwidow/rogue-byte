// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" int FAddRsmg__FP4RSMGiPii3OIDN24(void *, char *, int, char *, int, int, int, int);
extern "C" char B_003DD490;
extern "C" void Spawn_AddRsmg(char *self, int oid1, int oid2, int oid3, int oid4)
{
    if (oid1 != 0)
        FAddRsmg__FP4RSMGiPii3OIDN24(&B_003DD490, self + 0xE4, 4, self + 0xE0, oid1, oid2, oid3, oid4);
}
