// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D8C08-0X2D8C48 (piece data/splice-ref-crv_2d8c08), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void HandleSeqnodeMessage();
extern "C" void PostLoMessage();
extern "C" void PostScriptMessage();
extern "C" void Seqnode_AddRef();
extern "C" void Seqnode_Release();
extern "C" void func_00113A10();

// data-ok: retail's bytes at 0X2D8C08
void *D_002D8C08[16] = {0, 0, 0, (void *)Seqnode_AddRef, 0, (void *)Seqnode_Release, 0, (void *)PostScriptMessage, 0, (void *)PostLoMessage, 0, (void *)HandleSeqnodeMessage, 0, (void *)func_00113A10, 0, 0};
