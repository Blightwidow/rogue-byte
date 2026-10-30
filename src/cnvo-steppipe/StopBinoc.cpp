// SPDX-License-Identifier: GPL-3.0-or-later
struct BINOCSTATE_19CCE8 { int binocs; };
struct BINOC_19CCE8 { char pad[0x38]; BINOCSTATE_19CCE8 *pstate; };
extern "C" void SetBinocState(BINOC_19CCE8 *, int);
extern "C" void StopBinoc(BINOC_19CCE8 *pbinoc)
{
    if (pbinoc->pstate != 0) {
        switch (pbinoc->pstate->binocs) {
        case 0:
        case 8:
        case 9:
        case 10:
            return;
        }
    }
    SetBinocState(pbinoc, 2);
}
