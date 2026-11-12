// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
struct MpegDecoder_250E98 {
    char pad0[0x12C];
    int field12C;
    char pad130[0x820 - 0x130];
    int flip;
    char pad824[0x848 - 0x824];
    int field848;
    int field84C;
    char pad850[0x868 - 0x850];
    int field868;
    char pad86C[0x878 - 0x86C];
    int field878;
};
struct MacroblockCounters_250E98 {
    int count;
    int remaining;
    int first;
    int second;
};
struct MacroblockScratch_250E98 {
    char head[0x20];
    char first[0x10];
    char second[0x10];
};
void func_0024B6E8(int);
void func_0024F8D0(void);
void func_0024F970(MpegDecoder_250E98 *, int);
void func_0024FA38(MpegDecoder_250E98 *, const char *);
int func_00250360(MpegDecoder_250E98 *, int, int, int, int, MacroblockScratch_250E98 *, char *, char *);
void func_00250A38(MpegDecoder_250E98 *, int);
int func_00251790(MpegDecoder_250E98 *, int *, int *, char *, MacroblockScratch_250E98 *, char *, char *);
int func_00251CE8(MpegDecoder_250E98 *);
int func_00252230(MpegDecoder_250E98 *, int);
void func_00252358(MpegDecoder_250E98 *);
int func_00252398(MpegDecoder_250E98 *, MacroblockScratch_250E98 *, int *, char *, int *);
int func_00253518(MpegDecoder_250E98 *, int, int *, int *, MacroblockScratch_250E98 *);

int func_00250E98(MpegDecoder_250E98 *decoder, int limit)
{
    MacroblockScratch_250E98 scratch;
    MacroblockCounters_250E98 state;
    char tail[0x10];
    int ok;
    int result;
    int value;
    long wide;
    int status;
    state.count = 0;
    state.remaining = 0;
    status = func_00253518(decoder, limit, &state.count, &state.remaining, &scratch);
    if (status != 0) {
        return status;
    }
    decoder->field12C = 0;
    for (;;) {
        if (state.count >= limit) {
            return 0;
        }
        ok = 1;
        *(int *)((char *)decoder + decoder->flip * 0x140 + 0x6DC) = 0;
        func_00252358(decoder);
        if (*(volatile int *)0x1000B020 != 0 && (*(volatile int *)0x10002010 & 0x4000) == 0) {
            for (;;) {
                if (*(volatile int *)0x1000B420 == 0 && (*(volatile int *)0x1000B400 & 0x100) == 0) {
                    func_0024B6E8(decoder->field868);
                }
                if (decoder->field878 != 0) {
                    func_0024F8D0();
                    result = 0;
                    goto check;
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
        result = ok;
    check:
        if (result == 0) {
            return decoder->field878 == 0 ? 2 : 4;
        }
        if (state.remaining == 0) {
            if (func_00252230(decoder, 0x17) == 0 || decoder->field12C != 0) {
                decoder->field12C = 0;
                return 3;
            }
            state.remaining = func_00251CE8(decoder);
            if (decoder->field12C != 0) {
                decoder->field12C = 0;
                return 1;
            }
        }
        if (state.count >= limit) {
            func_0024FA38(decoder, "Too many macroblocks in picture");
            return 2;
        }
        if (state.remaining == 1) {
            if (func_00251790(decoder, &state.first, &state.second, tail, &scratch, scratch.first, scratch.second) == 0) {
                decoder->field12C = 0;
                return 1;
            }
        } else if (func_00252398(decoder, &scratch, &state.second, scratch.first, &state.first) == 0) {
            decoder->field12C = 0;
            return 2;
        }
        if (func_00250360(decoder, state.count, state.remaining, state.first, state.second, &scratch, scratch.first, scratch.second) == 0) {
            decoder->field12C = 0;
            return 2;
        }
        if (state.count != 0) {
            func_00250A38(decoder, decoder->flip ^ 1);
        }
        state.count += 1;
        decoder->flip ^= 1;
        state.remaining -= 1;
        continue;
    }
}
}
