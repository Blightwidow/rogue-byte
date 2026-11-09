// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CAF48-0X2CAF88 (piece data/aseg), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void Asega_AddRef();
extern "C" void Asega_Release();
extern "C" void HandleLoMessage();
extern "C" void PostScriptMessage();
extern "C" void SendAsegaMessage();
extern "C" void func_00114270();

// data-ok: retail's bytes at 0X2CAF48
void *D_002CAF48[16] = {0, 0, 0, (void *)Asega_AddRef, 0, (void *)Asega_Release, 0, (void *)PostScriptMessage, 0, (void *)SendAsegaMessage, 0, (void *)HandleLoMessage, 0, (void *)func_00114270, 0, 0};
