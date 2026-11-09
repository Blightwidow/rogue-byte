// SPDX-License-Identifier: GPL-3.0-or-later
// Two 16-byte vectors read by HitFx_GIntensity (src/crv-lo/HitFx_GIntensity.cpp declares them extern): retail's .data at 0x2BDCE0-0x2BDD00.
// config/us/data_files.tsv places this object's .data there and scripts/build/link_image.py proves the bytes.

// data-ok: retail's bytes at 0x2BDCE0 (a unit vector along x, 4 floats)
float g_2bdce0[4] = {1.0f, 0.0f, 0.0f, 0.0f};

// data-ok: retail's bytes at 0x2BDCF0 (the intensity polynomial 0.15, 1.1, -0.25 and a zero pad lane)
float g_2bdcf0[4] = {0.15f, 1.1f, -0.25f, 0.0f};
