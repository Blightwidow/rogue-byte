// SPDX-License-Identifier: GPL-3.0-or-later
struct TGT_1C48C0 { char pad[8]; int *pn; };
struct ALO_1C48C0 { char pad[0xE4]; TGT_1C48C0 *ptgt; };
struct OWNER_1C48C0 { char pad[0x3EFC]; int n; char pad2[0x4778 - 0x3F00]; int calo; ALO_1C48C0 *apalo[1]; };
extern "C" void func_001A58D0(ALO_1C48C0 *, int, int);
extern "C" void func_001C48C0(OWNER_1C48C0 *powner)
{
    for (int i = 0; i < powner->calo; i++) {
        ALO_1C48C0 *palo = powner->apalo[i];
        *palo->ptgt->pn = powner->n;
        func_001A58D0(palo, powner->n, 0);
    }
}
