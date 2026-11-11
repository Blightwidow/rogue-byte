// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Reader: the stdio library's setup (the code that fills a CreateSema parameter block) stores this address as a
// semaphore name; the bytes are 17 NUL-padded names of 24 bytes ("SceStdio...Sema") then a 16-byte tail of two strings.
#include "types.h"

struct StdioSemaNames {
    char names[17][24];
    char tail[16];
};

// data-ok: typed from the stdio setup code that names its semaphores
extern const StdioSemaNames D_002AAB28 = {
    {
        "SceStdioIoctlSema",
        "SceStdioIoctl2Sema",
        "SceStdioCCodeSema",
        "SceStdioMkdirSema",
        "SceStdioFormatSema",
        "SceStdioAddDrvSema",
        "SceStdioDcloseSema",
        "SceStdioDreadSema",
        "SceStdioGetstatSema",
        "SceStdioChstatSema",
        "SceStdioRenameSema",
        "SceStdioSyncSema",
        "SceStdioMountSema",
        "SceStdioLseek64Sema",
        "SceStdioDevctlSema",
        "SceStdioSymlinkSema",
        "SceStdioReadlinkSema",
    },
    "....\0\0\0\0all"
};
