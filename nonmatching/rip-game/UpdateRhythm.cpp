typedef int s32; typedef float f32;
struct RhythmNote { s32 a; s32 b; s32 c; f32 time; s32 d; s32 flag14; s32 flag18; s32 flag1C; s32 flag20; };
struct Rhythm {
    char pad0[0x50]; s32 mode; char pad54[0x8]; f32 window; char pad60[0x1C0-0x60]; s32 count; RhythmNote notes[1];
};
static inline f32 Second(void *base) { return ((f32 *)base)[1]; }
extern "C" {
void AddRhythmScore(Rhythm *, f32);
f32 GSmooth__FfffP3SMPPf(void *, s32, f32, f32, f32);
f32 MarkClockTickRealOnly__FP5CLOCK(void *);
void PlayDancerMove(s32, s32, s32, s32);
void UpdateLo();
void UpdateRhythmCrowd(Rhythm *);
void bevy_camera_follow_activity(void *, s32, Rhythm *);
extern char B_002DEB30;
extern char B_003DD040;
extern char g_2dded0[];
void UpdateRhythm(Rhythm *self) {
    UpdateLo();
    f32 now = MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
    switch (self->mode) {
    case 1:
        for (s32 index = 0; index < self->count; index++) {
            RhythmNote *note = &self->notes[index];
            if (note->flag14 == 0 && note->time < now) {
                PlayDancerMove(note->a, note->b, note->c, 0);
                note->flag14 = 1;
                break;
            }
        }
        break;
    case 2:
        for (s32 index = 0; index < self->count; index++) {
            RhythmNote *note = &self->notes[index];
            if (note->flag20 != 0) continue;
            if (note->flag18 == 0 && note->time < now) {
                *(s32 *)((char *)self + 0x230) = note->b;
                bevy_camera_follow_activity(&B_002DEB30, 0x34, self);
                note->flag18 = 1;
            }
            if (note->time + self->window < now) {
                note->flag20 = 1;
                if (note->flag1C == 0) {
                    PlayDancerMove(note->a, note->b, note->c, 2);
                    AddRhythmScore(self, *(f32 *)((char *)self + 0x2A4));
                }
                break;
            }
        }
        break;
    }
    *(f32 *)((char *)self + 0x288) = GSmooth__FfffP3SMPPf((char *)self + 0x28C, 0, *(f32 *)((char *)self + 0x288), *(f32 *)((char *)self + 0x284), Second(g_2dded0));
    UpdateRhythmCrowd(self);
}
}
