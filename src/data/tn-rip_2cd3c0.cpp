// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CD3C0-0X2CD570 (piece data/tn-rip_2cd3c0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateCpattach();
extern "C" void ActivateCplcy();
extern "C" void ActivateCplook();
extern "C" void CPLCY_Destruct();
extern "C" void CPLCY_Destruct_thunk();
extern "C" void DeactivateCplcy();
extern "C" void DeactivateCplook();
extern "C" void ResetCplcy();
extern "C" void RevokeCplcy();
extern "C" void SetCplcy();
extern "C" void UpdateCpattach();
extern "C" void UpdateCplcy_thunk();
extern "C" void UpdateCplook();
extern "C" void bevy_camera_looks_activate();
extern "C" void bevy_camera_looks_deactivate();
extern "C" void bevy_camera_looks_reset();
extern "C" void bevy_camera_looks_update();
extern "C" void bevy_camera_policy_activate();
extern "C" void bevy_camera_policy_deactivate();
extern "C" void bevy_camera_policy_update();
extern "C" void bevy_classes_k30_cam_activate_2();
extern "C" void bevy_classes_k30_cam_deactivate_2();
extern "C" void bevy_classes_k30_cam_reset();
extern "C" void bevy_classes_k30_cam_update();

// data-ok: retail's bytes at 0X2CD3C0
void *D_002CD3C0[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)ActivateCpattach, 0, (void *)DeactivateCplcy, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCpattach, 0, (void *)ResetCplcy, 0, 0};

// data-ok: retail's bytes at 0X2CD408
void *D_002CD408[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)bevy_camera_policy_activate, 0, (void *)bevy_camera_policy_deactivate, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)bevy_camera_policy_update, 0, (void *)ResetCplcy, 0, 0};

// data-ok: retail's bytes at 0X2CD450
void *D_002CD450[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)bevy_camera_looks_activate, 0, (void *)bevy_camera_looks_deactivate, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)bevy_camera_looks_update, 0, (void *)ResetCplcy, 0, 0};

// data-ok: retail's bytes at 0X2CD498
void *D_002CD498[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)bevy_classes_k30_cam_activate_2, 0, (void *)bevy_classes_k30_cam_deactivate_2, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)bevy_classes_k30_cam_update, 0, (void *)bevy_classes_k30_cam_reset, 0, 0};

// data-ok: retail's bytes at 0X2CD4E0
void *D_002CD4E0[18] = {0, 0, 0, (void *)CPLCY_Destruct, 0, (void *)ActivateCplook, 0, (void *)DeactivateCplook, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCplook, 0, (void *)bevy_camera_looks_reset, 0, 0};

// data-ok: retail's bytes at 0X2CD528
void *D_002CD528[18] = {0, 0, 0, (void *)CPLCY_Destruct_thunk, 0, (void *)ActivateCplcy, 0, (void *)DeactivateCplcy, 0, (void *)SetCplcy, 0, (void *)RevokeCplcy, 0, (void *)UpdateCplcy_thunk, 0, (void *)ResetCplcy, 0, 0};
