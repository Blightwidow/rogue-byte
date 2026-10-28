#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""parse_banks.py <disc image> - finds the 989snd sound banks (`SBlk`) in a disc image and checks them against the layout of the
version 2 reader in OpenGOAL's 989snd (ISC): header, sound table, grain table, and the tone, LFO, play-sound and plugin
structures in the grain data. Prints one line per bank and a summary; writes nothing and keeps nothing from the banks.

  python3 -I scripts/sound/parse_banks.py "Sly 2.iso"       (from the repository root)

A bank passes when its tables are consistent with the counts in the header and every tone has a sample offset inside the VAG data,
map low <= map high and a zero reserved word."""
import collections
import mmap
import struct
import sys

WINDOW = 1 << 20
GRAIN_TYPES = {
    0: 'null', 1: 'tone', 2: 'xref_id', 3: 'xref_num', 4: 'lfo', 5: 'start_child', 6: 'stop_child', 7: 'plugin', 8: 'branch',
    9: 'tone2', 20: 'control_null', 21: 'loop_start', 22: 'loop_end', 23: 'loop_continue', 24: 'stop', 25: 'rand_play',
    26: 'rand_delay', 27: 'rand_pb', 28: 'pb', 29: 'add_pb', 30: 'set_register', 31: 'set_register_rand', 32: 'inc_register',
    33: 'dec_register', 34: 'test_register', 35: 'marker', 36: 'goto_marker', 37: 'goto_random_marker', 38: 'wait_for_all_voices',
    39: 'play_cycle', 40: 'add_register', 41: 'key_off_voices', 42: 'kill_voices', 43: 'on_stop_marker', 44: 'copy_register',
}
TONE_TYPES, PLAY_TYPES = (1, 9), (5, 6, 8)


def find_banks(image):
    position = 0
    while True:
        position = image.find(b'SBlk', position)
        if position < 0:
            return
        yield position
        position += 4


def check_bank(image, base):
    """Returns a dict describing the bank at base, or None when the header does not fit the layout."""
    blob = image[base:base + WINDOW]
    magic, version, flags, bank_id = struct.unpack_from('<4sIII', blob, 0)
    if version != 3 or flags != 4:
        return None
    sound_count, grain_count, vag_count = struct.unpack_from('<3h', blob, 22)
    first_sound, first_grain, vags_in_sram, vag_data_size, sram_size, next_block, grain_data = struct.unpack_from('<7I', blob, 28)
    if first_grain + grain_count * 8 != grain_data or grain_data + 24 > len(blob):
        return None
    result = dict(base=base, version=version, flags=flags, sounds=sound_count, grains=grain_count, vags=vag_count,
                  vag_data_size=vag_data_size, grain_types=collections.Counter(), tones=0, bad_tones=0, play=0, bad_play=0,
                  lfo=0, plugin=0, problems=[], max_grain_data_end=0, named_children=0)
    if first_sound + sound_count * 12 != first_grain:
        result['problems'].append('sound table does not end at the grain table')
    for index in range(grain_count):
        result['grain_types'][GRAIN_TYPES.get(blob[first_grain + index * 8 + 3], 'unknown')] += 1
    for sound in range(sound_count):
        _, _, _, grain_total, _, _, first_sfx_grain = struct.unpack_from('<bbhbbHI', blob, first_sound + sound * 12)
        if grain_total == 0:
            continue
        if first_sfx_grain + grain_total * 8 > grain_count * 8:
            result['problems'].append(f'sound {sound}: grains outside the table')
            continue
        for grain in range(grain_total):
            opcode, _ = struct.unpack_from('<Ii', blob, first_grain + first_sfx_grain + grain * 8)
            kind, value = opcode >> 24, opcode & 0xFFFFFF
            at = grain_data + value
            if kind in TONE_TYPES:
                if at + 24 > len(blob):
                    result['bad_tones'] += 1
                    continue
                result['tones'] += 1
                _, _, _, _, _, map_low, map_high, _, _, _, _, _, sample_offset, reserved = struct.unpack_from('<bbbbhbbbbHHHII', blob, at)
                if sample_offset >= vag_data_size or map_low > map_high or reserved:
                    result['bad_tones'] += 1
                result['max_grain_data_end'] = max(result['max_grain_data_end'], value + 24)
            elif kind in PLAY_TYPES:
                result['play'] += 1
                if at + 32 > len(blob):
                    result['bad_play'] += 1
                    continue
                _, _, _, sound_id = struct.unpack_from('<ii4si', blob, at)
                name = blob[at + 16:at + 32].split(b'\0')[0]
                if name:
                    result['named_children'] += 1
                if (name and not all(32 <= byte < 127 for byte in name)) or (not name and not -1 <= sound_id < sound_count):
                    result['bad_play'] += 1
                result['max_grain_data_end'] = max(result['max_grain_data_end'], value + 32)
            elif kind == 4:
                result['lfo'] += 1
                result['max_grain_data_end'] = max(result['max_grain_data_end'], value + 16)
            elif kind == 7:
                result['plugin'] += 1
                result['max_grain_data_end'] = max(result['max_grain_data_end'], value + 32)
    return result


def main():
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    with open(sys.argv[1], 'rb') as handle:
        image = mmap.mmap(handle.fileno(), 0, access=mmap.ACCESS_READ)
        banks = [check_bank(image, base) for base in find_banks(image)]
    found = [bank for bank in banks if bank]
    print(f'{len(banks)} SBlk magics, {len(found)} headers fit the layout')
    print(f'{"offset":>12} {"sector":>8} {"+":>5} {"sounds":>6} {"grains":>6} {"vags":>5} {"tones":>7} {"bad":>6} {"play":>5} {"badp":>5} {"lfo":>5} {"plug":>5}')
    passing = 0
    for bank in found:
        ok = not bank['bad_tones'] and not bank['bad_play'] and not bank['problems'] and 'unknown' not in bank['grain_types']
        passing += ok
        print(f'{bank["base"]:#12x} {bank["base"] // 2048:8d} {bank["base"] % 2048:5d} {bank["sounds"]:6d} {bank["grains"]:6d} {bank["vags"]:5d} '
              f'{bank["tones"]:7d} {bank["bad_tones"]:6d} {bank["play"]:5d} {bank["bad_play"]:5d} {bank["lfo"]:5d} {bank["plugin"]:5d} {"ok" if ok else "BAD"}')
    print(f'banks that pass every check: {passing} of {len(found)}')
    kinds = collections.Counter()
    for bank in found:
        kinds.update(bank['grain_types'])
    print('grain types over all banks:', dict(sorted(kinds.items(), key=lambda item: -item[1])))


if __name__ == '__main__':
    main()
