// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .rodata 0X2A6A48-0X2A6AD0 (piece rodata/stepguard-sw), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2A6A48
extern const char D_002A6A48[16] = "ioprp300.img";

// data-ok: retail's bytes at 0X2A6A58
extern const unsigned int D_002A6A58[30] = {0x20796c53, 0x42203a32, 0x20646e61, 0x5420666f, 0x76656968, 0xa9207365, 0x30303220, 0x20200a34, 0x796e6f53, 0x6d6f4320, 0x65747570, 0x6e452072, 0x74726574, 0x6d6e6961, 0x20746e65, 0x72656d41, 0x20616369, 0x20200a26, 0x6b637553, 0x50207265, 0x68636e75, 0x6f725020, 0x74637564, 0x736e6f69, 0x3a33500a, 0x20732520, 0x700a7325, 0x73706f72, 0x6425203a, 0xa0a};
