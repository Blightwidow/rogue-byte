// SPDX-License-Identifier: GPL-3.0-or-later
typedef struct MpegDecoder MpegDecoder;
extern void func_00251E60(MpegDecoder *decoder);
void func_00252358(MpegDecoder *decoder) {
    if ((*(volatile unsigned *)0x10002010 & 0x80004000) == 0x80000000) {
        func_00251E60(decoder);
    }
}
