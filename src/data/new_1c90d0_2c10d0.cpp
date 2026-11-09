// SPDX-License-Identifier: GPL-3.0-or-later
// Retail .data 0X2C10D0-0X2C1EF4 (piece data/new_1c90d0), one global per Splat label: written by scripts/build/make_data_files.py,
// listed in config/us/data_files.tsv (link_image.py links it at its address and checks the bytes).

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C10D0
unsigned int D_002C10D0[412] = {0x3e8cd59a, 0xbe271b48, 0x3efd64a8, 0xbe724805, 0x3ed93a4b, 0xbdb70d9c, 0x3efd64a8, 0xbd2e4ee6, 0x3ee70b2d, 0x3b7dcfc2, 0x3dc80f73, 0x3e102842, 0x3dc0befe, 0x3e108ffe, 0x3a61719f, 0x3dc3aa7a, 0xbdbfa91e, 0x3e108ffe, 0xbdc6f993, 0x3e102842, 0xbee6c5b5, 0x3b7dcfc2, 0xbefceb22, 0xbd2e4ee6, 0xbed928e1, 0xbdb70d9c, 0xbefceb22, 0xbe724805, 0xbe8c5c14, 0xbe271b48, 0xbdc6f993, 0xbe58ae6b, 0xbb2ac4a0, 0xbe5ffee0, 0x3e73e097, 0xbd9d0be7, 0x3d95ac77, 0x3db299a9, 0x3ec55117, 0xbca35039, 0xbd949698, 0x3db299a9, 0xbe7355a7, 0xbd9d0be7, 0xbec4d791, 0xbca35039, 0xbc70ae53, 0x3dd30e20, 0xbc70ae53, 0xbe5fc1d6, 0x3e7da153, 0x3dcb9838, 0x3e7da1b3, 0xbe32061c, 0x3eee162a, 0xbc22c968, 0x3ebe1a79, 0x3d3ec92c, 0x3eddbfa8, 0x3c67ab75, 0x3ea97188, 0x3d866248, 0x3e9e75a9, 0x3d99ae92, 0x3dfe1aa9, 0x3e0aa1ce, 0x3e3e5754, 0x3df4e05e, 0x3d7f0d54, 0x3e009b0a, 0x3dfe19e9, 0xbe546828, 0x3e3e5754, 0xbe463976, 0x3d7f0d54, 0xbe5ce4f4, 0xbe7cae47, 0x3dcbe31e, 0xbe7cae47, 0xbe321457, 0xbdfc3492, 0x3e0ab8a6, 0xbd7b4126, 0x3e009c2a, 0xbe3d6448, 0x3df51d09, 0xbdfc3492, 0xbe547d20, 0xbd7b4126, 0xbe5cee51, 0xbe3d6448, 0xbe46528d, 0xbeedcf33, 0xbc22c968, 0xbebda0f3, 0x3d3f9665, 0xbea92c10, 0x3d866248, 0xbe9dfc23, 0x3d9a07b3, 0xbedd4623, 0x3c6b4c33, 0xbd4e26d5, 0x3e1e6110, 0xbb4bb92b, 0x3e4c4bfa, 0x388ccf12, 0x3e4ebbe1, 0x3a61719f, 0x3e4ebbe1, 0x3d505293, 0x3e1e6110, 0x3b84320b, 0x3e198082, 0xbbe428ae, 0x3e49954b, 0xbbe428ae, 0x3e199bd9, 0xbd0467f8, 0x3e341e61, 0xbc9069cb, 0x3e416d21, 0xbcaf7600, 0x3e3e419b, 0xbd12f0ea, 0x3e306c0a, 0xbd12f0ea, 0x3e1c16fc, 0xbd34c4a8, 0x3e26cfa2, 0xbcaf7600, 0x3e1a83a8, 0x3d06b4ab, 0x3e341e61, 0x3cb3cd7d, 0x3e3e5ab2, 0x3c9607d7, 0x3e416d21, 0x3bf592a1, 0x3e49d256, 0x3cb3cd7d, 0x3e1a8169, 0x3bf586a4, 0x3e199cf8, 0x3d36f1e6, 0x3e26cfa2, 0x3d151ca9, 0x3e307089, 0x3d151ca9, 0x3e1c169c, 0xbec4d791, 0xbca35039, 0xbe7355a7, 0xbd9d0be7, 0xbd949698, 0x3db299a9, 0xbe34c1a9, 0xbc832a66, 0xbe34c1a9, 0x3d52ea2d, 0xbe1ed04a, 0x3bac6811, 0xbe34c1a9, 0x3bac6811, 0xbe9f48b0, 0x3bac6811, 0xbe8f9c33, 0x3c814210, 0xbe8f9c33, 0x3bac6811, 0xbe8f9c33, 0xbd763ee4, 0x3e73e097, 0xbd9d0be7, 0x3d95ac77, 0x3db299a9, 0x3ec55117, 0xbca35039, 0x3e356f6c, 0xbc843e06, 0x3e356f6c, 0x3d52ea2d, 0x3e1f5b99, 0x3bac6811, 0x3e356f6c, 0x3bac6811, 0x3e9fb60a, 0x3bac6811, 0x3e90047e, 0x3c814210, 0x3e90047e, 0x3bac6811, 0x3e90047e, 0xbd7602f9, 0xbdf3cfbd, 0x3e4d2b2c, 0xbe73cf5d, 0x3e19305e, 0xbe7cae47, 0x3dcbe31e, 0xbe3d6448, 0x3df51d09, 0xbe975494, 0x3df3d07d, 0xbe9dfc23, 0x3d9a07b3, 0xbeb6db6e, 0x3da47155, 0xbea92c10, 0x3d866248, 0xbec58c72, 0x3d73ce3d, 0xbebda0f3, 0x3d3f9665, 0xbed55535, 0x3d0e7e76, 0xbedd4623, 0x3c6b4c33, 0xbee6c5b5, 0x3b7dcfc2, 0x3a61719f, 0x3dc3aa7a, 0x3a61719f, 0x3e74867d, 0xbdc6f993, 0x3e102842, 0xbcee8713, 0x3e6ba9d2, 0xbdfc3492, 0x3e0ab8a6, 0xbd7b4126, 0x3e009c2a, 0xbdbfa91e, 0x3e108ffe, 0xbc70ae53, 0x3dd30e20, 0x3dc80f73, 0x3e102842, 0x3df3cefd, 0x3e4d5dba, 0x3d7f0d54, 0x3e009b0a, 0x3dc0befe, 0x3e108ffe, 0x3ebe1a79, 0x3d3ec92c, 0x3ec5d12a, 0x3d73ce3d, 0x3e3e5754, 0x3df4e05e, 0x3e979a6b, 0x3df3cfbd, 0x3dfe1aa9, 0x3e0aa1ce, 0x3e73cf5d, 0x3e1974e6, 0x3e7da153, 0x3dcb9838, 0x3eb6db6e, 0x3da52ed3, 0x3ea97188, 0x3d866248, 0x3e9e75a9, 0x3d99ae92, 0x3eddbfa8, 0x3c67ab75, 0x3ed55535, 0x3d1054d3, 0x3ee70b2d, 0x3b7dcfc2, 0xbd4e26d5, 0x3e1e6110, 0xbd12f0ea, 0x3e1c16fc, 0x3b84320b, 0x3e198082, 0x3d151ca9, 0x3e1c169c, 0x3d505293, 0x3e1e6110, 0xbd34c4a8, 0x3e26cfa2, 0xbd12f0ea, 0x3e306c0a, 0x3a61719f, 0x3e4ebbe1, 0x3d36f1e6, 0x3e26cfa2, 0xbcaf7600, 0x3e1a83a8, 0x3cb3cd7d, 0x3e1a8169, 0xbbe428ae, 0x3e199bd9, 0x3bf586a4, 0x3e199cf8, 0x3c9607d7, 0x3e416d21, 0x3bf592a1, 0x3e49d256, 0x3cb3cd7d, 0x3e3e5ab2, 0x3d06b4ab, 0x3e341e61, 0x3d151ca9, 0x3e307089, 0xbb4bb92b, 0x3e4c4bfa, 0xbbe428ae, 0x3e49954b, 0x388ccf12, 0x3e4ebbe1, 0xbcaf7600, 0x3e3e419b, 0xbd0467f8, 0x3e341e61, 0xbc9069cb, 0x3e416d21, 0x3f000000, 0xbf000000, 0x3f000000, 0x3f000000, 0xbf000000, 0x3f000000, 0xbf000000, 0xbf000000, 0x3ee70b2d, 0x3b7dcfc2, 0x3efd64a8, 0xbd2e4ee6, 0x3ed93a4b, 0xbdb70d9c, 0x3efd64a8, 0xbe724805, 0x3e8cd59a, 0xbe271b48, 0xbdc6f993, 0xbe58ae6b, 0x3b79f91a, 0xbe5ffe81, 0xbe8c5c14, 0xbe271b48, 0xbefceb22, 0xbe724805, 0xbed928e1, 0xbdb70d9c, 0xbefceb22, 0xbd2e4ee6, 0xbee6c5b5, 0x3b7dcfc2, 0xbb4bb92b, 0x3e734e2a, 0x3a61719f, 0x3e74867d, 0x3ee90f9a, 0, 0xbee8ca22, 0, 0xbcee8713, 0x3e6ba9d2, 0x3eb6db6e, 0x3da52ed3, 0x3ec5d12a, 0x3d73ce3d, 0x3ed55535, 0x3d1054d3, 0x3e73cf5d, 0x3e1974e6, 0x3e979a6b, 0x3df3cfbd, 0x3df3cefd, 0x3e4d5dba, 0xbeb6db6e, 0x3da47155, 0xbdf3cfbd, 0x3e4d2b2c, 0xbe975494, 0x3df3d07d, 0xbe73cf5d, 0x3e19305e, 0xbec58c72, 0x3d73ce3d, 0xbed55535, 0x3d0e7e76, 0xbcee8713, 0xbe5f3447, 0x3ef3cf2d, 0xbcb21b15, 0x3e73cfbd, 0xbe358f41, 0x3df3ce3d, 0xbe554db8, 0x3e701648, 0xbe36dced, 0x3e36db6e, 0xbe483605, 0x3d382df8, 0xbe5e4f16, 0xbdf3cefd, 0xbe553800, 0xbe73cf5d, 0xbe354ab9, 0xbe6f5bc9, 0xbe36db6e, 0xbe36db6e, 0xbe480fd2, 0xbef3cf2d, 0xbd5f296b, 0xbef3cf2d, 0xbcb7713a, 0xbef3cf2d, 0xbe4be13f};

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C1740
struct {
    char m0[4];
    char m1[4];
    unsigned int m2[158];
} D_002C1740 = {
    "\015",
    "\014",
    {14, 1, 0, 2, 11, 46, 12, 2, 4, 27, 2, 27, 3, 2, 19, 29, 2, 29, 4, 10, 50, 12, 10, 12, 46, 47, 22, 50, 22, 12, 50, 47, 48, 20, 47, 20, 22, 49, 38, 20, 49, 20, 48, 42, 40, 20, 42, 20, 38, 40, 9, 20, 9, 8, 20, 8, 41, 20, 41, 23, 20, 22, 21, 14, 22, 14, 12, 21, 45, 39, 21, 39, 14, 20, 43, 45, 20, 45, 21, 20, 44, 15, 20, 15, 43, 20, 23, 24, 20, 24, 44, 7, 16, 24, 7, 24, 23, 16, 7, 37, 7, 34, 35, 7, 35, 37, 35, 34, 18, 17, 36, 18, 36, 35, 18, 17, 0, 26, 17, 26, 36, 19, 2, 0, 19, 0, 17, 19, 18, 29, 18, 28, 29, 28, 18, 30, 18, 25, 31, 18, 31, 30, 18, 32, 33, 18, 33, 25, 32, 18, 5, 18, 34, 6, 18, 6, 5, 0}
};

// data-ok: retail's bytes at 0X2C19C0
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[4];
    char m10[4];
    char m11[4];
    char m12[4];
    char m13[4];
    char m14[4];
    char m15[4];
    char m16[4];
    char m17[4];
    char m18[4];
    char m19[4];
    char m20[4];
    char m21[4];
    char m22[4];
    char m23[4];
    char m24[4];
    char m25[4];
    char m26[4];
    char m27[4];
    char m28[4];
    char m29[4];
    char m30[4];
    char m31[4];
    char m32[4];
    char m33[4];
    char m34[4];
    char m35[4];
    char m36[4];
    char m37[4];
    char m38[4];
    char m39[4];
    char m40[4];
    char m41[4];
    char m42[4];
    char m43[4];
    char m44[4];
    char m45[4];
    char m46[4];
    char m47[4];
    char m48[4];
    char m49[4];
    char m50[4];
    char m51[4];
    char m52[4];
    char m53[4];
    char m54[4];
    char m55[4];
    char m56[4];
    char m57[4];
    char m58[4];
    char m59[4];
    char m60[4];
    char m61[4];
    char m62[4];
    char m63[4];
    char m64[4];
    char m65[4];
} D_002C19C0 = {
    "7",
    "J",
    "H",
    "3",
    "@",
    "\077",
    "I",
    "H",
    "J",
    "I",
    "J",
    "F",
    "\077",
    "@",
    ">",
    "\077",
    ">",
    "A",
    "I",
    "F",
    "B",
    "A",
    ">",
    ";",
    "A",
    ";",
    "=",
    "C",
    "B",
    "F",
    "C",
    "F",
    "G",
    "D",
    "C",
    "G",
    "D",
    "G",
    "8",
    "E",
    "D",
    "8",
    "E",
    "8",
    ":",
    "E",
    ":",
    "A",
    "E",
    "A",
    "6",
    "5",
    "6",
    "A",
    "5",
    "A",
    "4",
    "4",
    "A",
    "9",
    "<",
    "9",
    "A",
    "<",
    "A",
    "="
};

// data-ok: retail's bytes at 0X2C1AC8
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[4];
    char m10[4];
    char m11[4];
    char m12[4];
    char m13[4];
    char m14[4];
    char m15[4];
    char m16[4];
    char m17[4];
    char m18[4];
    char m19[4];
    char m20[4];
    char m21[4];
    char m22[4];
    char m23[4];
    char m24[4];
    char m25[4];
    char m26[4];
    char m27[4];
    char m28[4];
    char m29[4];
    char m30[4];
    char m31[4];
    char m32[4];
    char m33[4];
} D_002C1AC8 = {
    "U",
    "R",
    "T",
    "N",
    "Q",
    "P",
    "P",
    "O",
    "M",
    "S",
    "T",
    "R",
    "Q",
    "S",
    "O",
    "U",
    "N",
    "L",
    "R",
    "U",
    "K",
    "O",
    "P",
    "Q",
    "S",
    "Q",
    "T",
    "N",
    "T",
    "Q",
    "T",
    "N",
    "U",
    ""
};

// data-ok: retail's bytes at 0X2C1B50
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[4];
    char m10[4];
    char m11[4];
    char m12[4];
    char m13[4];
    char m14[4];
    char m15[4];
    char m16[4];
    char m17[4];
    char m18[4];
    char m19[4];
    char m20[4];
    char m21[4];
    char m22[4];
    char m23[4];
    char m24[4];
    char m25[4];
    char m26[4];
    char m27[4];
    char m28[4];
    char m29[4];
    char m30[4];
    char m31[4];
    char m32[4];
    char m33[4];
} D_002C1B50 = {
    "]",
    "X",
    "`",
    "Y",
    "[",
    "\134",
    "[",
    "W",
    "Z",
    "^",
    "]",
    "_",
    "\134",
    "Z",
    "^",
    "Y",
    "\134",
    "_",
    "`",
    "_",
    "]",
    "Z",
    "\134",
    "[",
    "^",
    "_",
    "\134",
    "`",
    "V",
    "Y",
    "_",
    "`",
    "Y",
    ""
};

// TODO: a plain word array over 64 elements is not ruled as typed data yet (docs/contributing/exceptions.md "Game data defined in
// source"); its type is Splat's guess, not recovered from the code that reads it
// data-ok: retail's bytes at 0X2C1BD8
struct {
    char m0[4];
    char m1[4];
    char m2[4];
    char m3[4];
    char m4[4];
    char m5[4];
    char m6[4];
    char m7[4];
    char m8[4];
    char m9[4];
    char m10[4];
    char m11[4];
    char m12[4];
    char m13[4];
    char m14[4];
    char m15[4];
    char m16[4];
    char m17[4];
    char m18[4];
    char m19[4];
    char m20[4];
    char m21[4];
    char m22[4];
    char m23[4];
    char m24[4];
    char m25[4];
    char m26[4];
    char m27[4];
    char m28[4];
    char m29[4];
    char m30[4];
    char m31[4];
    char m32[4];
    char m33[4];
    char m34[4];
    char m35[4];
    unsigned int m36[150];
} D_002C1BD8 = {
    "a",
    "d",
    "b",
    "c",
    "b",
    "d",
    "b",
    "c",
    "e",
    "c",
    "f",
    "e",
    "g",
    "e",
    "h",
    "e",
    "f",
    "h",
    "h",
    "j",
    "g",
    "g",
    "j",
    "i",
    "m",
    "k",
    "l",
    "l",
    "k",
    "j",
    "i",
    "j",
    "k",
    "d",
    "a",
    "r",
    {135, 115, 116, 116, 112, 97, 97, 112, 114, 120, 110, 139, 139, 110, 138, 138, 110, 145, 145, 110, 147, 147, 110, 117, 147, 117, 137, 137, 117, 146, 146, 117, 144, 115, 136, 117, 117, 136, 144, 115, 135, 136, 118, 121, 119, 119, 149, 111, 142, 111, 149, 149, 119, 148, 148, 119, 150, 150, 119, 151, 151, 119, 152, 152, 119, 143, 143, 119, 139, 139, 119, 121, 139, 121, 120, 130, 129, 122, 129, 123, 122, 129, 130, 125, 125, 130, 131, 131, 128, 125, 124, 127, 128, 127, 125, 128, 127, 124, 119, 119, 124, 126, 118, 119, 126, 134, 132, 133, 132, 122, 133, 122, 123, 133, 142, 155, 111, 113, 111, 155, 155, 153, 113, 113, 153, 154, 113, 135, 97, 116, 97, 135, 135, 113, 140, 140, 113, 141, 141, 113, 157, 157, 113, 156, 156, 113, 158, 113, 154, 158}
};

// data-ok: retail's bytes at 0X2C1EC0
float D_002C1EC0 = 1.25e+03f;

// data-ok: retail's bytes at 0X2C1EC4
float g_2c1ec4 = 1.5e+02f;

// data-ok: retail's bytes at 0X2C1EC8
float g_2c1ec8 = 1.8f;

// data-ok: retail's bytes at 0X2C1ECC
float g_2c1ecc = 25.0f;

// data-ok: retail's bytes at 0X2C1ED0
unsigned int g_2c1ed0[4] = {9, 0, 0, 0};

// data-ok: retail's bytes at 0X2C1EE0
unsigned int D_002C1EE0[4] = {0, 0, 0xc50ca000, 0};

// data-ok: retail's bytes at 0X2C1EF0
float g_2c1ef0 = 4e+02f;
