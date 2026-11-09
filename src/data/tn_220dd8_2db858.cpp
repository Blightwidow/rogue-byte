// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2DB858-0X2DB8A0 (piece data/tn_220dd8_2db858), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateCptn__FP4CPTNPv();
extern "C" void DeactivateCptn();
extern "C" void ResetCplcy();
extern "C" void RevokeCplcy();
extern "C" void SetCplcy();
extern "C" void UpdateCptn__FP4CPTNP6CPDEFIP3JOYf();
extern "C" void bevy_camera_follow_new();

// data-ok: retail's bytes at 0X2DB858
void *D_002DB858[18] = {0, 0, 0, (void *)bevy_camera_follow_new, 0, (void *)ActivateCptn__FP4CPTNPv, 0, (void *)DeactivateCptn, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCptn__FP4CPTNP6CPDEFIP3JOYf, 0, (void *)ResetCplcy, 0, 0};
