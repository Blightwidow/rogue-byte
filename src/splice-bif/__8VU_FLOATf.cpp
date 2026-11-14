// SPDX-License-Identifier: GPL-3.0-or-later
// source:sly1-decomp StoreFloatAsQuadword (src/main/script_machine.cpp, AGPL-3.0, same maintainers), a draft that scores 0
#include "types.h"
#include "ps2inline.h"

struct VU_FLOAT {
    u128 lanes;
    VU_FLOAT(float value);
};
VU_FLOAT::VU_FLOAT(float value)
{
    u128 r = (u128)QuadFromFloat(value);
    const s128& slot = (s128)r;
    lanes = *(const u128*)&slot;
}
