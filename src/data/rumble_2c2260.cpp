// SPDX-License-Identifier: GPL-3.0-or-later
// Typed by hand (make_data_files.py keeps this file).
// Read by TriggerRumbleRumk (record rumk * 0x104, passed on as a RUMPAT) and UpdateRumble / SetRumbleRums: a rumble pattern is a
// count (crumins) followed by 8-byte steps: the two actuator bytes sent to scePadSetActDirect, then the step's duration in seconds.
// 11 patterns of 32 steps; steps past the count are unused.
#include "types.h"

typedef struct RUMINS {
    u8 actuators[2];
    u8 field_0x2[2];
    f32 duration;
} RUMINS;

typedef struct RUMPAT {
    s32 crumins;
    RUMINS arumins[32];
} RUMPAT;

// data-ok: typed from TriggerRumbleRumk and UpdateRumble
RUMPAT D_002C2260[11] = {
    {1, {{{1, 0}, {0, 0}, 0.0500000007f}}},
    {2, {{{0, 150}, {0, 0}, 0.0500000007f}, {{0, 0}, {0, 0}, 0.0500000007f}}},
    {2, {{{0, 210}, {0, 0}, 0.0500000007f}, {{0, 0}, {0, 0}, 0.100000001f}}},
    {2, {{{0, 255}, {0, 0}, 0.100000001f}, {{0, 0}, {0, 0}, 0.100000001f}}},
    {7, {{{0, 210}, {0, 0}, 0.100000001f}, {{0, 190}, {0, 0}, 0.00999999978f}, {{0, 170}, {0, 0}, 0.00999999978f}, {{0, 150}, {0, 0}, 0.00999999978f}, {{0, 130}, {0, 0}, 0.00999999978f}, {{0, 110}, {0, 0}, 0.00999999978f}, {{0, 0}, {0, 0}, 0.25f}}},
    {2, {{{1, 255}, {0, 0}, 0.100000001f}, {{1, 0}, {0, 0}, 0.0500000007f}}},
    {2, {{{0, 170}, {0, 0}, 0.0500000007f}, {{0, 0}, {0, 0}, 0.100000001f}}},
    {2, {{{0, 170}, {0, 0}, 0.0500000007f}, {{0, 0}, {0, 0}, 0.100000001f}}},
    {2, {{{0, 170}, {0, 0}, 0.0500000007f}, {{0, 0}, {0, 0}, 0.100000001f}}},
    {3, {{{0, 160}, {0, 0}, 0.150000006f}, {{0, 0}, {0, 0}, 0.100000001f}, {{0, 90}, {0, 0}, 0.0500000007f}}},
    {5, {{{0, 255}, {0, 0}, 0.200000003f}, {{0, 0}, {0, 0}, 0.0799999982f}, {{0, 200}, {0, 0}, 0.129999995f}, {{0, 0}, {0, 0}, 0.0599999987f}, {{0, 150}, {0, 0}, 0.109999999f}}},
};
