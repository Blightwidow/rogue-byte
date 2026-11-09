// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D9BE0-0X2D9C70 (piece data/new_1fbf20_2d9be0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void ApplyStreamAmbParams();
extern "C" void ContinueStreamAmb();
extern "C" void GetStreamAmbKind();
extern "C" void HandleLoMessage();
extern "C" void PauseStreamAmb();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void ReplayStreamAmb();
extern "C" void StartStreamAmb();
extern "C" void StopStreamAmb();
extern "C" void StreamAmb_AddRef();
extern "C" void StreamAmb_Release();
extern "C" void UpdateStreamAmbPositional();
extern "C" void func_00114380();
extern "C" void func_001FC878();
extern "C" void func_001FC9A8();

// data-ok: retail's bytes at 0X2D9BE0
void *D_002D9BE0[36] = {0, 0, 0, (void *)StreamAmb_AddRef, 0, (void *)StreamAmb_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114380, 0, (void *)ReplayStreamAmb, 0, (void *)GetStreamAmbKind, 0, (void *)StartStreamAmb, 0, (void *)StopStreamAmb, 0, (void *)PauseStreamAmb, 0, (void *)ContinueStreamAmb, 0, (void *)ApplyStreamAmbParams, 0, (void *)func_001FC878, 0, (void *)func_001FC9A8, 0, (void *)UpdateStreamAmbPositional, 0, 0};
