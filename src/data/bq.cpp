// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2CBE20-0X2CBE38 (piece data/bq), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CbRead__17CQueueInputMemoryiPv();

// data-ok: retail's bytes at 0X2CBE20
void *D_002CBE20[6] = {0, 0, 0, (void *)CbRead__17CQueueInputMemoryiPv, 0, 0};
