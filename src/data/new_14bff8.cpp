// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2BD4E0-0X2BD810 (piece data/new_14bff8), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_002BE26C[];
extern char D_3DD050[];
extern "C" void OnCodeGrantGadget();
extern "C" void OnCodeGrantGadgetIf100Percent();
extern "C" void OnCodeWarpToEpisode();
extern "C" void func_0014C140();

// data-ok: retail's bytes at 0X2BD4E0
void *D_002BD4E0[8] = {(void *)0x2bd4c8, (void *)6, (void *)func_0014C140, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD500
unsigned int D_002BD500[6] = {0x2000, 0x8000, 0x1000, 0x1000, 0x1000, 8};

// data-ok: retail's bytes at 0X2BD518
void *D_002BD518[8] = {(void *)&D_002BD500, (void *)6, (void *)OnCodeWarpToEpisode, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD538
unsigned int D_002BD538[6] = {0x4000, 8, 0x8000, 0x2000, 8, 0x4000};

// data-ok: retail's bytes at 0X2BD550
void *D_002BD550[8] = {(void *)&D_002BD538, (void *)6, (void *)OnCodeWarpToEpisode, (void *)1, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD570
unsigned int D_002BD570[6] = {8, 0x8000, 0x2000, 8, 0x8000, 0x4000};

// data-ok: retail's bytes at 0X2BD588
void *D_002BD588[8] = {(void *)&D_002BD570, (void *)6, (void *)OnCodeWarpToEpisode, (void *)2, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD5A8
unsigned int D_002BD5A8[6] = {0x1000, 0x8000, 0x2000, 0x8000, 0x4000, 0x1000};

// data-ok: retail's bytes at 0X2BD5C0
void *D_002BD5C0[8] = {(void *)&D_002BD5A8, (void *)6, (void *)OnCodeWarpToEpisode, (void *)3, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD5E0
unsigned int D_002BD5E0[6] = {0x1000, 0x2000, 0x2000, 0x1000, 0x8000, 0x8000};

// data-ok: retail's bytes at 0X2BD5F8
void *D_002BD5F8[8] = {(void *)&D_002BD5E0, (void *)6, (void *)OnCodeWarpToEpisode, (void *)4, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD618
unsigned int D_002BD618[6] = {0x8000, 8, 0x4000, 0x4000, 0x1000, 0x2000};

// data-ok: retail's bytes at 0X2BD630
void *D_002BD630[8] = {(void *)&D_002BD618, (void *)6, (void *)OnCodeWarpToEpisode, (void *)5, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD650
unsigned int D_002BD650[6] = {0x4000, 0x1000, 8, 8, 0x8000, 0x4000};

// data-ok: retail's bytes at 0X2BD668
void *D_002BD668[8] = {(void *)&D_002BD650, (void *)6, (void *)OnCodeWarpToEpisode, (void *)6, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD688
unsigned int D_002BD688[6] = {0x8000, 0x8000, 0x8000, 0x4000, 0x4000, 8};

// data-ok: retail's bytes at 0X2BD6A0
void *D_002BD6A0[8] = {(void *)&D_002BD688, (void *)6, (void *)OnCodeWarpToEpisode, (void *)7, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD6C0
unsigned int D_002BD6C0[6] = {0x4000, 0x1000, 0x8000, 0x8000, 8, 0x2000};

// data-ok: retail's bytes at 0X2BD6D8
void *D_002BD6D8[8] = {(void *)&D_002BD6C0, (void *)6, (void *)OnCodeWarpToEpisode, (void *)8, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD6F8
unsigned int D_002BD6F8[6] = {0x8000, 8, 8, 0x4000, 0x4000, 0x8000};

// data-ok: retail's bytes at 0X2BD710
void *D_002BD710[8] = {(void *)&D_002BD6F8, (void *)6, (void *)0x14c1f0, (void *)D_3DD050, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD730
unsigned int D_002BD730[6] = {0x2000, 8, 0x4000, 8, 0x4000, 0x4000};

// data-ok: retail's bytes at 0X2BD748
void *D_002BD748[8] = {(void *)&D_002BD730, (void *)6, (void *)0x14c1f0, (void *)D_002BE26C, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD768
unsigned int D_002BD768[6] = {0x2000, 0x8000, 0x2000, 0x8000, 8, 0x8000};

// data-ok: retail's bytes at 0X2BD780
void *D_002BD780[8] = {(void *)&D_002BD768, (void *)6, (void *)OnCodeGrantGadgetIf100Percent, 0, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD7A0
unsigned int D_002BD7A0[6] = {0x8000, 0x8000, 0x4000, 0x2000, 0x8000, 0x2000};

// data-ok: retail's bytes at 0X2BD7B8
void *D_002BD7B8[8] = {(void *)&D_002BD7A0, (void *)6, (void *)OnCodeGrantGadget, (void *)41, 0, 0, 0, 0};

// data-ok: retail's bytes at 0X2BD7D8
unsigned int D_002BD7D8[6] = {0x4000, 0x4000, 0x1000, 0x4000, 0x2000, 0x8000};

// data-ok: retail's bytes at 0X2BD7F0
void *D_002BD7F0[8] = {(void *)&D_002BD7D8, (void *)6, (void *)OnCodeGrantGadget, (void *)42, 0, 0, 0, 0};
