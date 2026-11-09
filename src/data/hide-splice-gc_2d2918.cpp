// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D2918-0X2D2938 (piece data/hide-splice-gc_2d2918), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CBinaryFileStream_Close();
extern "C" void CBinaryFileStream_Pump();

// data-ok: retail's bytes at 0X2D2918
void *D_002D2918[8] = {0, 0, 0, (void *)CBinaryFileStream_Pump, 0, (void *)CBinaryFileStream_Close, 0, 0};
