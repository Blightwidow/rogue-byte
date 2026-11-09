// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CF508-0X2CF520 (piece data/gifs), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void EndPrim__4GIFSi();

// data-ok: retail's bytes at 0X2CF508
void *D_002CF508[6] = {0, 0, 0, (void *)EndPrim__4GIFSi, 0, 0};
