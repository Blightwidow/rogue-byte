// SPDX-License-Identifier: GPL-3.0-or-later
typedef struct Decoder_252398 {
    char pad0[0x160];
    int pictureType;
    char pad164[0x20];
    int pictureStructure;
    char pad188[0x38];
    int field1C0;
    char pad1C4[0x65C];
    int rowSelector;
} Decoder_252398;

extern void func_0024FA38(Decoder_252398 *, const char *);
extern const char RO_STR_002AC5F0[];

int func_00252398(Decoder_252398 *decoder, int *first, int *second, int *third, int *flags)
{
    int result = 1;
    int *row = (int *)((char *)decoder + decoder->rowSelector * 0x140 + 0x6DC);
    *row = 1;
    decoder->field1C0 = 1;
    if (decoder->pictureType == 2) {
        first[5] = 0;
        first[4] = 0;
        first[0] = first[1] = 0;
    }
    if (decoder->pictureStructure == 3) {
        second[0] = 2;
    } else {
        second[0] = result;
        third[0] = third[1] = (decoder->pictureStructure == 2);
    }
    if (decoder->pictureType == 1) {
        func_0024FA38(decoder, RO_STR_002AC5F0);
        result = 0;
    }
    *flags &= -2;
    return result;
}
