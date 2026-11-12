// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct MpegDecoder_250C58 {
    char pad0[0x13C];
    int width;
    int height;
    char pad144[0x184 - 0x144];
    int mode;
    char pad188[0x820 - 0x188];
    int skipCount;
    int field824;
    char pad828[0x848 - 0x828];
    int field848;
    int field84C;
    char pad850[0x868 - 0x850];
    int field868;
    char pad86C[0x878 - 0x86C];
    int field878;
};
void func_0024B6E8(int);
void func_0024F8D0(void);
void func_0024F970(MpegDecoder_250C58 *, int);
void func_0024FA38(MpegDecoder_250C58 *, const char *);
void func_00250A38(MpegDecoder_250C58 *, int);
int func_00250E98(MpegDecoder_250C58 *, int);
void func_00252358(MpegDecoder_250C58 *);

static inline int SyncDisplay(MpegDecoder_250C58 *decoder)
{
    int ok;
    int value;
    long wide;
    ok = 1;
    func_00252358(decoder);
    func_00252358(decoder);
    if (*(volatile int *)0x1000B020 != 0 && (*(volatile int *)0x10002010 & 0x4000) == 0) {
        for (;;) {
            if (*(volatile int *)0x1000B420 == 0 && (*(volatile int *)0x1000B400 & 0x100) == 0) {
                func_0024B6E8(decoder->field868);
            }
            if (decoder->field878 != 0) {
                func_0024F8D0();
                return 0;
            }
            if (*(volatile int *)0x1000B020 == 0) {
                break;
            }
            if (*(volatile int *)0x10002010 & 0x4000) {
                break;
            }
        }
    }
    value = *(volatile int *)0x10002020;
    wide = *(volatile long *)0x10002030;
    decoder->field848 = (int)wide;
    if (wide < 0) {
        int low = value & 0x1F;
        decoder->field84C = low != 0 ? 0x20 - low : 0;
    } else {
        decoder->field84C = 0x20;
    }
    if (*(volatile int *)0x10002010 & 0x4000) {
        func_0024F970(decoder, value);
        ok = 0;
    }
    return ok;
}

int func_00250C58(MpegDecoder_250C58 *decoder)
{
    int status;
    int sectors;
    int result;
    decoder->skipCount = 0;
    sectors = decoder->width * decoder->height;
    decoder->field824 = 0;
    if (decoder->mode != 3) {
        sectors >>= 1;
    }
    for (;;) {
        status = func_00250E98(decoder, sectors);
        if (status == 1) {
            continue;
        }
        if (status == 3) {
            continue;
        }
        break;
    }
    result = SyncDisplay(decoder);
finish:
    if (result == 0) {
        if (decoder->field878 != 0) {
            return 4;
        }
        status = 2;
    }
    while ((*(volatile unsigned int *)0x1000D400 >> 8) & 1) {
    }
    if (status == 0) {
        func_00250A38(decoder, decoder->skipCount == 0);
    }
    if ((unsigned int)(status - 1) < 2) {
        func_0024FA38(decoder, "= Skip to the next picture =");
    }
    return status == 0;
}
}
