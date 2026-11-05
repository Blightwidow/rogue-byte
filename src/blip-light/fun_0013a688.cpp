// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" char g_2dea28[];
extern "C" char B_002DDF40[];
extern "C" float g_2dded0;
extern "C" void UnpackHelper__4VIFS3UPKiiPiPPUi(void *, int, int, int, int *, void *);
extern "C" void AddVifUnpack__4VIFS3UPKiPvi(void *, int, int, void *, int);
extern "C" void AddVifUnpackRefs__4VIFS3UPKiPviPPPv(void *, int, int, void *, int, void *);


void func_0013A688(char *pblipg)
{
    float *pqwConstants;
    unsigned *pqwCounts;
    UnpackHelper__4VIFS3UPKiiPiPPUi(g_2dea28, 0xC, 1, 5, 0, &pqwConstants);
    char *pbBase = B_002DDF40;
    pqwConstants[0] = *(float *)(pbBase + 0x100);
    pqwConstants[1] = *(float *)(pbBase + 0x114);
    pqwConstants[2] = *(float *)(pblipg + 0x440);
    char *pgClock = (char *)&g_2dded0;
    pqwConstants[3] = *(float *)pgClock;
    UnpackHelper__4VIFS3UPKiiPiPPUi(g_2dea28, 0xC, 1, 6, 0, &pqwCounts);
    pqwCounts[0] = 0;
    if (*(int *)(pblipg + 0x434) != 0)
        pqwCounts[0] |= 1;
    pqwCounts[1] = *(unsigned int *)(pblipg + 0x3B0);
    pqwCounts[2] = *(unsigned int *)(pblipg + 0x1A0);
    ((float *)pqwCounts)[3] = *(float *)(pgClock + 0x40);
    int ccolor = *(int *)(pblipg + 0x3B0);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 0xE, ccolor, pblipg + 0x3B4, 0x30 - ccolor);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 8, 1, pblipg + 0x130, 1);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 8, 1, pblipg + 0x110, 2);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 8, 1, pblipg + 0x140, 3);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 8, 1, pblipg + 0x150, 4);
    AddVifUnpack__4VIFS3UPKiPvi(g_2dea28, 0xC, 4, *(void **)(pblipg + 0x438), 0x30);
    AddVifUnpackRefs__4VIFS3UPKiPviPPPv(g_2dea28, 0xC, *(int *)(pblipg + 0x1A0), pblipg + 0x1B0, 0xF, 0);
}
