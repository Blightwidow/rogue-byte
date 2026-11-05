// SPDX-License-Identifier: GPL-3.0-or-later
struct MpegDecoder_254678 {
    char pad[0x154];
    int field154;
    int field158;
    int field15C;
};
extern "C" int func_00252148(MpegDecoder_254678 *, int);
extern "C" void func_00254678(MpegDecoder_254678 *decoder)
{
    func_00252148(decoder, 3);
    if (func_00252148(decoder, 1) != 0) {
        func_00252148(decoder, 8);
        func_00252148(decoder, 8);
        decoder->field154 = func_00252148(decoder, 8);
    }
    decoder->field158 = func_00252148(decoder, 0xE);
    func_00252148(decoder, 1);
    decoder->field15C = func_00252148(decoder, 0xE);
}
