extern "C" {
extern char B_003DD040[];
extern float g_2bbb60[];
float MarkClockTickRealOnly__FP5CLOCK(void *);
}
struct Rhythm { char pad[0x58]; float dtEarly; float dtLate; };
struct Cue { char pad[0xC]; float tDue; };
extern "C" float GAccuracyRhythmCue(Rhythm *rhythm, Cue *cue)
{
    float tMusic = MarkClockTickRealOnly__FP5CLOCK(B_003DD040);
    float tDue = cue->tDue;
    float dtOff;
    float dtWindow;
    if (tMusic < tDue) {
        dtOff = tDue - tMusic;
        dtWindow = rhythm->dtEarly;
    } else {
        dtOff = tMusic - tDue;
        dtWindow = rhythm->dtLate;
    }
    asm volatile("nop\n\tnop");
    float ratio = dtOff / dtWindow;
    float gMiss = 1.0f - ratio;
    float gOn = 1.0f - gMiss;
    return gOn * g_2bbb60[0] + gMiss * g_2bbb60[1];
}
