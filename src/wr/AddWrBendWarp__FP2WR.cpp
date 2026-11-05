typedef int s32; typedef float f32; typedef int s128 __attribute__((mode(TI)));
struct BENDWARP { s32 active; char pad4[0xC]; s128 rowA; s128 rowB; char pad30[8]; f32 half38; char pad3C[0x4C]; f32 half88; char pad8C[0x44]; };
struct WR { char pad0[0x54]; s32 cwarp; s32 cwarpTotal; char pad5C[4]; BENDWARP warps[1]; };
struct WRCOUNT { char pad0[0x6E0]; s32 count; };
extern "C" {
extern s128 g_2a2db0;
extern s128 g_2a2dc0;

void AddWrBendWarp__FP2WR(WR *wr) {
    BENDWARP *warp = &wr->warps[wr->cwarp++];
    ((WRCOUNT *)wr)->count++;
    warp->active = 1;
    warp->rowA = g_2a2db0;
    warp->rowB = g_2a2dc0;
    warp->half38 = 0.5f;
    warp->half88 = 0.5f;
    wr->cwarpTotal = wr->cwarpTotal + 1;
}
}
