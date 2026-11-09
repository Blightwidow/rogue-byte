// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CD570-0X2CD5B8 (piece data/cm-tn_2cd570), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateCplcy();
extern "C" void CPLCY_Destruct();
extern "C" void DeactivateCplcy();
extern "C" void ResetCplcy();
extern "C" void RevokeCplcy();
extern "C" void SetCplcy();
extern "C" void UpdateCplcy();

// data-ok: retail's bytes at 0X2CD570
void *D_002CD570[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)ActivateCplcy, 0, (void *)DeactivateCplcy, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCplcy, 0, (void *)ResetCplcy, 0, 0};
