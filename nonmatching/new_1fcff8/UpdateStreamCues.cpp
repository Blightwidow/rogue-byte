typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32;
extern "C" {
struct Entry { s16 delay; char pad[6]; };
struct Sub { char pad0[0x50]; f32 limit; s32 count; Entry *entries; };
struct Cue {
    char pad0[0x40]; s32 x40; char pad44[0xA]; s16 x4E; u16 x50; u16 x52; char pad54[0xC]; Sub *sub; s64 ticks;
};
struct Obj { char pad0[0x200]; Cue *cue; char pad204[0x40]; s32 index; f32 elapsed; f32 total; };
void RunStreamCue(Obj *, Entry *);
void StopStream(Obj *);
f32 __floatdisf(s64);
extern f32 g_2ddf10;
static inline int Busy(Cue *cue) { return cue->x52 != 0 || (cue->x50 & 1); }
static inline f32 Ticks(s64 ticks) {
    if (ticks >= 0) return __floatdisf(ticks);
    return 2.0f * __floatdisf((ticks & 1) | ((u64)ticks >> 1));
}
void UpdateStreamCues(Obj *self) {
    if (self->cue != 0) {
        if (!Busy(self->cue) && self->cue->x4E <= 0) {
            Cue *cue = self->cue;
            Sub *sub = cue->sub;
            self->total = self->total + g_2ddf10;
            int idle = cue->x40 == 0 && !Busy(cue);
            if (idle != 0) {
                if (Ticks(self->cue->ticks) * 3.390842e-9f > 0.0f || sub->limit <= self->total) StopStream(self);
            } else {
                while (self->index < sub->count) {
                    Entry *entry = &sub->entries[self->index];
                    f32 delay = (f32)entry->delay * 0.016666668f;
                    if (!(Ticks(self->cue->ticks) * 3.390842e-9f >= self->elapsed + delay)) break;
                    RunStreamCue(self, entry);
                    self->index = self->index + 1;
                    self->elapsed = self->elapsed + delay;
                }
            }
        }
    }
}
}
