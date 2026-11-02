struct GIFS { char pad[0x30]; };
struct QW;
struct VECTOR { float x, y, z, w; } __attribute__((aligned(16)));
struct LOCALS { int table[8]; VECTOR vec; int palette[0x100]; GIFS gifs; char buffer[0x800]; int handle; QW *dmaBuf; int *dmaDone; };
struct SW { char pad0[0x3EA0]; unsigned long gs; };
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
        LOCALS l;
        l.dmaBuf = (QW *)l.buffer;
        l.dmaDone = &l.handle;
        for (int wait = 2; wait != -1; wait--) {
        }
        int *rgbOut = &l.table[4];
        for (int color = 0; color < 3; color++) {
            ConvertUserHsvToUserRgb__FP6VECTORT0(&B_003E1300[color], &l.vec);
            rgbOut[color] = (int)l.vec.x | ((int)l.vec.y << 8) | ((int)l.vec.z << 16);
            ((float *)rgbOut)[color - 4] = ((float *)B_003E1300)[color - 3] * 0.003921569f;
        }
        for (int wait = 0xFF; wait != -1; wait--) {
        }
        int *out = l.palette;
        int count = 0;
        int limit = 0;
        do {
            int step = 0;
            do {
                int lane = 7;
                do {
                    int idx = count & 0x7F;
                    idx -= 1;
                    if (idx < 0) idx = 0;
                    float level = (float)idx * 0.007936508f;
                    float scaled = level > 0.0f ? level : 0.0f;
                    int base;
                    float alphaValue;
                    switch (count & 0x81) {
                    case 0x81:
                        base = l.table[6];
                        alphaValue = ((float *)l.table)[2];
                        break;
                    case 0x80:
                        base = l.table[4];
                        alphaValue = ((float *)l.table)[0];
                        break;
                    case 1:
                        base = l.table[5];
                        alphaValue = ((float *)l.table)[1];
                        break;
                    case 0:
                        *out++ = 0;
                        goto next;
                    default:
                        goto next;
                    }
                    *out++ = base | ((int)(scaled * (alphaValue * 128.0f)) << 24);
                next:
                    count++;
                    lane--;
                } while (lane >= 0);
                count += D_002C3680[step];
                step++;
            } while (step < 4);
            limit += 0x20;
        } while (limit < 0x100);
        if (arg1 != 0)
            self->gs = (AllocZpr(arg1, 4) << 37) | (((0x8000UL << 37) | 0xD800) << 9);
        __4GIFS(&l.gifs);
        AllocStatic__4DMASiP2QW(&l.gifs, 0x80, l.dmaBuf);
        AddDmaCnt__4DMAS(&l.gifs);
        BuildImageGifs__FiiiiiiP4GIFS((int)((self->gs >> 37) & 0x3FFF), 1, 0, 0x10, 0x10, 0x40, &l.gifs);
        AddDmaRefs__4DMASiP2QW(&l.gifs, 0x40, l.palette);
        AddPrimPack__4GIFSiiUl(&l.gifs, 0, 1, 0xE);
        PackAD__4GIFSll(&l.gifs, 0x3F, 0);
        PackAD__4GIFSll(&l.gifs, 0x61, 0);
        AddPrimEnd__4GIFS(&l.gifs);
        AddDmaEnd__4DMAS(&l.gifs);
        Detach__4DMASPiPP2QW(&l.gifs, 0, l.dmaDone);
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, l.handle);
    }
}
}
