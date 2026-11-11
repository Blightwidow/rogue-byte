// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A76F8-0X2A7720 (piece rodata/new_1c3df8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A76F8
extern const char D_002A76F8[16] = "oidPoCurrent";

// data-ok: retail's bytes at 0X2A7708
extern const float D_002A7708[2] = {3.4028235e+38f, 0.0f};

// data-ok: retail's bytes at 0X2A7710
extern const float D_002A7710[4] = {3.4028235e+38f, 0.0f, 0.0f, 0.0f};
