// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D9C70-0X2D9D90 (piece data/sound), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void AMB_AddRef();
extern "C" void AMB_Release();
extern "C" void ApplyAmbParams();
extern "C" void ContinueAmbVoice();
extern "C" void GetAmbKind();
extern "C" void HandleLoMessage();
extern "C" void OnLoAdd__FP2LO();
extern "C" void PauseAmbVoice();
extern "C" void PollAmb();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void SetAmbSilent();
extern "C" void StartAmb();
extern "C" void StopSound__FP3AMBi();
extern "C" void UpdateAmbPositional();
extern "C" void func_00114380();
extern "C" void func_00132B08();
extern "C" void func_001FB0C0();
extern "C" void func_0023C820();

// data-ok: retail's bytes at 0X2D9C70
void *D_002D9C70[36] = {0, 0, 0, (void *)AMB_AddRef, 0, (void *)AMB_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114380, 0, (void *)func_001FB0C0, 0, (void *)GetAmbKind, 0, (void *)StartAmb, 0, (void *)StopSound__FP3AMBi, 0, (void *)PauseAmbVoice, 0, (void *)ContinueAmbVoice, 0, (void *)ApplyAmbParams, 0, (void *)PollAmb, 0, (void *)SetAmbSilent, 0, (void *)UpdateAmbPositional, 0, 0};

// data-ok: retail's bytes at 0X2D9D00
void *D_002D9D00[36] = {0, 0, 0, (void *)OnLoAdd__FP2LO, 0, (void *)func_00132B08, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114380, 0, (void *)func_001FB0C0, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)func_0023C820, 0, (void *)UpdateAmbPositional, 0, 0};
