// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C4640-0X2C46C0 (piece data/sdk), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

extern char D_443B80[];
extern char D_444B80[];
extern char D_445B80[];
extern char D_446B80[];
extern char D_447B80[];
extern char D_447FC0[];

// data-ok: retail's bytes at 0X2C4640
unsigned int D_002C4640 = 0;

// data-ok: retail's bytes at 0X2C4644
unsigned int D_002C4644 = 0;

// data-ok: retail's bytes at 0X2C4648
unsigned int D_002C4648 = 0;

// data-ok: retail's bytes at 0X2C464C
unsigned int D_002C464C = 0;

// data-ok: retail's bytes at 0X2C4650
unsigned int D_002C4650 = 0;

// data-ok: retail's bytes at 0X2C4654
unsigned int D_002C4654 = 0;

// data-ok: retail's bytes at 0X2C4658
unsigned int D_002C4658 = 0;

// data-ok: retail's bytes at 0X2C465C
unsigned int D_002C465C = 0;

// data-ok: retail's bytes at 0X2C4660
void *D_002C4660[2] = {(void *)D_443B80, (void *)D_444B80};

// data-ok: retail's bytes at 0X2C4668
unsigned int D_002C4668[2] = {0xffc, 0xffc};

// data-ok: retail's bytes at 0X2C4670
void *D_002C4670[2] = {(void *)D_445B80, (void *)D_446B80};

// data-ok: retail's bytes at 0X2C4678
void *D_002C4678[2] = {(void *)D_447B80, (void *)D_447FC0};

// data-ok: retail's bytes at 0X2C4680
unsigned int D_002C4680 = 0;

// data-ok: retail's bytes at 0X2C4684
unsigned int D_002C4684 = 0;

// data-ok: retail's bytes at 0X2C4688
unsigned int D_002C4688[2] = {0, 0};

// data-ok: retail's bytes at 0X2C4690
unsigned int D_002C4690[5] = {0, 0, 0, 0, 0x448500};

// data-ok: retail's bytes at 0X2C46A4
unsigned int D_002C46A4 = 0;

// data-ok: retail's bytes at 0X2C46A8
unsigned int D_002C46A8[4] = {0, 0, 0, 0};

// data-ok: retail's bytes at 0X2C46B8
unsigned int D_002C46B8[2] = {0, 0};
