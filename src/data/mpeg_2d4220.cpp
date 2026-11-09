// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2D4220-0X2D4240 (piece data/mpeg_2d4220), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void CbWrite__15CQueueOutputIpuiPv();
extern "C" void FAsyncDrain__15CQueueOutputIpu();

// data-ok: retail's bytes at 0X2D4220
void *D_002D4220[8] = {0, 0, 0, (void *)CbWrite__15CQueueOutputIpuiPv, 0, (void *)FAsyncDrain__15CQueueOutputIpu, 0, 0};
