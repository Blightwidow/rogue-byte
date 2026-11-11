// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Read by GadgetMenu_SetPage (entries/entryCount of the gadget menu page; entry+0x10 is reset to -1 when the page closes, +0x14 and
// +0x18 are a float pair summed to pick the first entry, +0x1C holds flag bits tested with & 4) and by the 0x1D9C00 splice-gc-wipe
// routine, which steps through it 0x20 bytes at a time (id at +0): 9 records.
#include "gadgetmenu.h"

// data-ok: typed from GadgetMenu_SetPage
GADGETMENUENTRY D_002C3028[9] = {
    {7, {893, 892, 894}, -1, 175.0f, 155.0f, 1},
    {9, {903, 902, 904}, -1, 285.0f, 155.0f, 1},
    {11, {913, 912, 914}, -1, 395.0f, 155.0f, 1},
    {13, {923, 922, 924}, -1, 505.0f, 155.0f, 1},
    {10, {908, 907, 909}, -1, 175.0f, 235.0f, 1},
    {12, {918, 917, 919}, -1, 285.0f, 235.0f, 1},
    {8, {898, 897, 899}, -1, 395.0f, 235.0f, 1},
    {14, {928, 927, 929}, -1, 505.0f, 235.0f, 1},
    {36, {1043, 1042, 1044}, -1, 175.0f, 315.0f, 0}
};
