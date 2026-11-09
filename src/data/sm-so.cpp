// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C3738-0X2C3BA0 (piece data/sm-so), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// data-ok: retail's bytes at 0X2C3738
unsigned int D_002C3738[4] = {92, 101, 102, 105};

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C3748
unsigned int D_002C3748[136] = {0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 8, 0x3e4ccccd, 30, 0x45a, 30, 0x45b, 15, 0x460, 15, 0x461, 5, 0x45d, 5, 0x45e, 4, 8, 0x3e4ccccd, 30, 0x45d, 30, 0x45e, 15, 0x463, 15, 0x464, 5, 0x466, 5, 0x467, 4, 8, 0x3e4ccccd, 30, 0x45d, 30, 0x45e, 15, 0x463, 15, 0x464, 5, 0x466, 5, 0x467, 4, 8, 0x3e4ccccd, 30, 0x466, 30, 0x467, 15, 0x469, 15, 0x46a, 5, 0x46f, 5, 0x470, 4, 8, 0x3e4ccccd, 30, 0x466, 30, 0x467, 15, 0x469, 15, 0x46a, 5, 0x46f, 5, 0x470, 4, 8, 0x3e4ccccd, 30, 0x46f, 30, 0x470, 15, 0x46c, 15, 0x46d, 5, 0x475, 5, 0x476, 4, 8, 0x3e4ccccd, 30, 0x46f, 30, 0x470, 15, 0x46c, 15, 0x46d, 5, 0x475, 5, 0x476, 4, 8, 0x3e4ccccd, 30, 0x46c, 30, 0x46d, 15, 0x475, 15, 0x476, 5, 0x472, 5, 0x473, 0};

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C3968
unsigned int D_002C3968[138] = {0, 0, 0, 0, 0xffffffff, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 12, 0x3ecccccd, 30, 0x45c, 30, 0x45b, 15, 0x462, 15, 0x461, 5, 0x45f, 5, 0x45e, 6, 12, 0x3ecccccd, 30, 0x45f, 30, 0x45e, 15, 0x465, 15, 0x464, 5, 0x468, 5, 0x467, 6, 12, 0x3ecccccd, 30, 0x45f, 30, 0x45e, 15, 0x465, 15, 0x464, 5, 0x468, 5, 0x467, 6, 12, 0x3ecccccd, 30, 0x468, 30, 0x467, 15, 0x46b, 15, 0x46a, 5, 0x471, 5, 0x470, 6, 12, 0x3ecccccd, 30, 0x468, 30, 0x467, 15, 0x46b, 15, 0x46a, 5, 0x471, 5, 0x470, 6, 12, 0x3ecccccd, 30, 0x471, 30, 0x470, 15, 0x46e, 15, 0x46d, 5, 0x477, 5, 0x476, 6, 12, 0x3ecccccd, 30, 0x471, 30, 0x470, 15, 0x46e, 15, 0x46d, 5, 0x477, 5, 0x476, 6, 12, 0x3ecccccd, 30, 0x46e, 30, 0x46d, 15, 0x477, 15, 0x476, 5, 0x474, 5, 0x473, 0, 0, 0};

// data-ok: retail's bytes at 0X2C3B90
float D_002C3B90[4] = {4e+02f, 0.0f, 0.0f, 0.0f};
