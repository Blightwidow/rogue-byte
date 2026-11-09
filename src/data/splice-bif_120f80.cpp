// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BBB70-0X2BBB90 (piece data/splice-bif_120f80), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern "C" void RadNormalize__Ff();
extern "C" void acosf();
extern "C" void asinf();
extern "C" void atanf();
extern "C" void cosf();
extern "C" void sinf();
extern "C" void sqrtf();
extern "C" void tanf();

// data-ok: retail's bytes at 0X2BBB70
void *D_002BBB70[8] = {(void *)sqrtf, (void *)sinf, (void *)cosf, (void *)tanf, (void *)asinf, (void *)acosf, (void *)atanf, (void *)RadNormalize__Ff};
