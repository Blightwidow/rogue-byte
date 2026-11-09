// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CAB90-0X2CABD8 (piece data/missile-proxy), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CPLCY_Destruct();
extern "C" void CplcyCamobj_Update();
extern "C" void ResetCplcy();
extern "C" void RevokeCplcy();
extern "C" void SetCplcy();
extern "C" void bevy_classes_k30_cam_activate();
extern "C" void bevy_classes_k30_cam_deactivate();

// data-ok: retail's bytes at 0X2CAB90
void *D_002CAB90[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)bevy_classes_k30_cam_activate, 0, (void *)bevy_classes_k30_cam_deactivate, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)CplcyCamobj_Update, 0, (void *)ResetCplcy, 0, 0};
