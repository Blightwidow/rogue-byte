// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CD378-0X2CD3C0 (piece data/new_14d1d0_2cd378), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateCplookat();
extern "C" void CPLCY_Destruct();
extern "C" void DeactivateCplcy();
extern "C" void ResetCplcy();
extern "C" void RevokeCplcy();
extern "C" void SetCplcy();
extern "C" void UpdateCplookat();

// data-ok: retail's bytes at 0X2CD378
void *D_002CD378[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)ActivateCplookat, 0, (void *)DeactivateCplcy, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCplookat, 0, (void *)ResetCplcy, 0, 0};
