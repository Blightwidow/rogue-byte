// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D4240-0X2D4260 (piece data/mpeg-memcard_2d4240), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CQueueOutputIop_CbWrite();
extern "C" void FAsyncDrain__15CQueueOutputIop();

// data-ok: retail's bytes at 0X2D4240
void *D_002D4240[8] = {0, 0, 0, (void *)CQueueOutputIop_CbWrite, 0, (void *)FAsyncDrain__15CQueueOutputIop, 0, 0};
