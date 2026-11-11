// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Read by the emitter code at 0x15C690 as GLimitLm(&D_002BDEC0, x): a pair of floats, the lower and upper limit.
#include "types.h"

typedef struct LM {
    f32 gMin;
    f32 gMax;
} LM;

// data-ok: typed from the GLimitLm caller in the emitter code at 0x15C690
LM D_002BDEC0 = {0.5f, 2.0f};
