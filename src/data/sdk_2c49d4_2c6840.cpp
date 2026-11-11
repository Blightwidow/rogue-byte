// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Read by sceCdRead: a 0x18-byte request it fills (three words, three bytes at 0xC, two pointers at 0x10 and 0x14) and
// passes on as the send buffer. The rest of the 4 KB it lives in is not touched and stays assembly.
#include "types.h"

typedef struct CDREADREQUEST {
    s32 field_0x0;
    s32 field_0x4;
    s32 field_0x8;
    u8 field_0xC[4];
    void *field_0x10;
    void *field_0x14;
} CDREADREQUEST;

// data-ok: typed from sceCdRead
CDREADREQUEST D_002C6840 = {0, 0, 0, {0, 0, 0, 0}, 0, 0};
