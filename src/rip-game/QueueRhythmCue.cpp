struct Cue { int a; int b; int c; float d; float tick; int z1; int z2; int z3; int z0; };
struct Rhythm { char pad[0x1C0]; int count; Cue cues[3]; };
extern "C" {
void *memmove(void *, const void *, unsigned int);
extern char B_003DD040;
float MarkClockTickRealOnly__FP5CLOCK(void *);
void QueueRhythmCue(Rhythm *self, int a, int b, int c, float d)
{
    int ccue = self->count;
    Cue *cue;
    if (ccue == 3) {
        int cb = 0x24;
        memmove(&self->cues[0], &self->cues[1], 0x48);
        cue = (Cue *)((char *)self + (self->count * cb + 0x1A0));
    } else {
        self->count = ccue + 1;
        cue = &self->cues[ccue];
    }
    cue->a = a;
    cue->b = b;
    cue->c = c;
    cue->d = d;
    cue->tick = MarkClockTickRealOnly__FP5CLOCK(&B_003DD040);
    cue->z1 = 0;
    cue->z2 = 0;
    cue->z3 = 0;
    cue->z0 = 0;
}
}
