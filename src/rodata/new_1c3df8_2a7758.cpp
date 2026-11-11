// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A7758-0X2A7768 (piece rodata/new_1c3df8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A7758
extern const float g_2a7758 = 3.4028235e+38f;

// data-ok: retail's bytes at 0X2A775C
extern const float D_002A775C = -3.4028235e+38f;

// data-ok: retail's bytes at 0X2A7760
extern const float D_002A7760[2] = {3.4028235e+38f, 0.0f};
