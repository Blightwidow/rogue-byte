// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Reader: sceCdMmode and its sibling CD-RPC wrappers pass this as the receive buffer of sceSifCallRpc and then read the
// reply through an uncached alias with lw at +0, +0x4, +0x8 and +0xC: an array of s32 words (the rest is never read).
#include "types.h"

// data-ok: typed from sceCdMmode
s32 D_002C7940[272] = {0};
