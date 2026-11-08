// SPDX-License-Identifier: GPL-3.0-or-later
extern "C" {
extern char B_003DD040[];
extern float g_2bbb60[];
float MarkClockTickRealOnly__FP5CLOCK(void *);
}
struct Rhythm { char pad[0x58]; float dtEarly; float dtLate; };
struct Cue { char pad[0xC]; float tDue; };
// Retail: |tMusic - tDue| over the early or late window, accuracy = 1 - ratio, then a lerp between the two score limits
// g_2bbb60[0..1] by accuracy ((1 - accuracy) * low + accuracy * high). The two nops before div.s come from plain C (the
// compiler's FP hazard padding at the join, as in UCompletePingpong); the old `asm("nop")` barrier was not needed.
// NEAR 11: only the float registers of the final block differ (retail keeps 1.0 in f1, low in f3, high in f2).
extern "C" float GAccuracyRhythmCue(Rhythm *rhythm, Cue *cue)
{
    float tMusic = MarkClockTickRealOnly__FP5CLOCK(B_003DD040);
    float dtOff;
    float tDue = cue->tDue;
    float dtWindow;
    if (tMusic < tDue) {
        dtOff = tDue - tMusic;
        dtWindow = rhythm->dtEarly;
    } else {
        dtOff = tMusic - tDue;
        dtWindow = rhythm->dtLate;
    }
    float ratio = dtOff / dtWindow;
    float accuracy = 1.0f - ratio;
    float miss = 1.0f - accuracy;
    return g_2bbb60[0] * miss + accuracy * g_2bbb60[1];
}
