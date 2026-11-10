// SPDX-License-Identifier: GPL-3.0-or-later
#include "sw.h"
struct GIFS { char pad[0x30]; };
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct CLR {
    int rgba;
    CLR() {}
    CLR(int value) : rgba(value) {}
    void Set(int value) { rgba = value; }
};
// steer-ok: a helper call keeps fold from re-associating scaled * (alpha * 128) into (scaled * 128) * alpha, as retail's operand order shows
static inline int ScaleAlpha(float scale, float alpha) { return (int)(scale * alpha); }
extern "C" {
void __4GIFS(GIFS *);
void AllocStatic__4DMASiP2QW(GIFS *, int, QW *);
void AddDmaCnt__4DMAS(GIFS *);
void AddDmaRefs__4DMASiP2QW(GIFS *, int, int *);
void AddPrimPack__4GIFSiiUl(GIFS *, int, int, unsigned long);
void PackAD__4GIFSll(GIFS *, long, long);
void AddPrimEnd__4GIFS(GIFS *);
void AddDmaEnd__4DMAS(GIFS *);
void Detach__4DMASPiPP2QW(GIFS *, int, int *);
void BuildImageGifs__FiiiiiiP4GIFS(int, int, int, int, int, int, GIFS *);
void ConvertUserHsvToUserRgb__FP6VECTORT0(VECTOR *, VECTOR *);
void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(int, int);
long AllocZpr(int, int);
extern VECTOR B_003E1300[];
extern int D_002C3680[];
extern int g_2de598;
void func_001EA9F0(SW *self, int arg1)
{
    if (arg1 != 0 || (self->gs & (0xFFFCUL << 35))) {
        float alpha[3];
        CLR colors[3];
        VECTOR rgb;
        for (int color = 0; color < 3; color++) {
            ConvertUserHsvToUserRgb__FP6VECTORT0(&B_003E1300[color], &rgb);
            colors[color].Set((int)rgb.x | ((int)rgb.y << 8) | ((int)rgb.z << 16));
            alpha[color] = ((float *)B_003E1300)[color - 3] * 0.003921569f;
        }
        CLR palette[0x100];
        GIFS gifs;
        char buffer[0x800];
        int handle;
        QW *dmaBuffer = (QW *)buffer;
        int *dmaDone = &handle;
        CLR *out = palette;
        int count = 0;
        int limit = 0;
        do {
            int step = 0;
            do {
                for (int lane = 0; lane < 8; lane++) {
                    int index = count & 0x7F;
                    index -= 1;
                    if (index < 0) index = 0;
                    float level = (float)index * 0.007936508f;
                    float scaled = level > 0.0f ? level : 0.0f;
                    switch (count & 0x81) {
                    case 0x81:
                        *out++ = CLR(colors[2].rgba | (ScaleAlpha(scaled, alpha[2] * 128.0f) << 24));
                        break;
                    case 0x80:
                        *out++ = CLR(colors[0].rgba | (ScaleAlpha(scaled, alpha[0] * 128.0f) << 24));
                        break;
                    case 1:
                        *out++ = CLR(colors[1].rgba | (ScaleAlpha(scaled, alpha[1] * 128.0f) << 24));
                        break;
                    case 0:
                        out++->Set(0);
                        break;
                    }
                    count++;
                }
                count += D_002C3680[step];
                step++;
            } while (step < 4);
            limit += 0x20;
        } while (limit < 0x100);
        if (arg1 != 0)
            self->gs = (AllocZpr(arg1, 4) << 37) | (((0x8000UL << 37) | 0xD800) << 9);
        __4GIFS(&gifs);
        AllocStatic__4DMASiP2QW(&gifs, 0x80, dmaBuffer);
        AddDmaCnt__4DMAS(&gifs);
        BuildImageGifs__FiiiiiiP4GIFS((int)((self->gs >> 37) & 0x3FFF), 1, 0, 0x10, 0x10, 0x40, &gifs);
        AddDmaRefs__4DMASiP2QW(&gifs, 0x40, (int *)palette);
        AddPrimPack__4GIFSiiUl(&gifs, 0, 1, 0xE);
        PackAD__4GIFSll(&gifs, 0x3F, 0);
        PackAD__4GIFSll(&gifs, 0x61, 0);
        AddPrimEnd__4GIFS(&gifs);
        AddDmaEnd__4DMAS(&gifs);
        Detach__4DMASPiPP2QW(&gifs, 0, dmaDone);
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, handle);
    }
}
}
