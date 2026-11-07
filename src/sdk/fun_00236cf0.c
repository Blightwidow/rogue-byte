// SPDX-License-Identifier: GPL-3.0-or-later
struct Entry { int words[16]; };
struct Ring { int pad0[5]; struct Entry *entries; int count; int pad1c[2]; int cursor; };
struct Entry *func_00236CF0(struct Ring *ring) {
    ring->cursor = ring->cursor % ring->count;
    return &ring->entries[ring->cursor++];
}
