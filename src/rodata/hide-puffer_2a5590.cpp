// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A5590-0X2A55C0 (piece rodata/hide-puffer), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A5590
extern const float D_002A5590 = 3.4028235e+38f;

// data-ok: retail's bytes at 0X2A5594
extern const float D_002A5594 = 3.4028235e+38f;

// data-ok: retail's bytes at 0X2A5598
extern const float D_002A5598[2] = {3.4028235e+38f, 0.0f};

// data-ok: retail's bytes at 0X2A55A0
extern const unsigned int D_002A55A0[8] = {18, 19, 20, 21, 19, 0, 0, 0};
