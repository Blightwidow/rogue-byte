// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CAF08-0X2CAF48 (piece data/alo-missile_2caf08), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ActivateActseg();
extern "C" void CloneAct();
extern "C" void DeactivateActseg();
extern "C" void GetActsegPositionGoal();
extern "C" void GetActsegRotationGoal();
extern "C" void func_0012CF20();

// data-ok: retail's bytes at 0X2CAF08
void *D_002CAF08[16] = {0, 0, 0, (void *)ActivateActseg, 0, (void *)DeactivateActseg, 0, (void *)func_0012CF20, 0, (void *)GetActsegRotationGoal, 0, (void *)GetActsegPositionGoal, 0, (void *)CloneAct, 0, 0};
