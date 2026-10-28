#include "sly2.h"
void *memmove(void *, const void *, unsigned int);
struct LM;
extern "C" char B_002DE578;
extern "C" char B_002DEB30;
extern "C" float D_002BDBE0[3];
extern "C" float g_2bbb60[2];
extern "C" float GetSuck(void *);
float GLimitLm(LM *, float);
extern "C" float GMeanRhythmScore(void *);
extern "C" void bevy_camera_follow_activity(void *, int, void *);
struct RHYTHM { char pad[0x234]; char lm[8]; int count; float score[16]; float gap; float mean; };
extern "C" void AddRhythmScore(RHYTHM *rhythm, float score)
{
    if (score < 0.0f) {
        float suck = GetSuck(&B_002DE578);
        float scale = D_002BDBE0[0] + suck * (D_002BDBE0[1] + suck * D_002BDBE0[2]);
        float low = g_2bbb60[0];
        float high = g_2bbb60[1];
        if (scale < low) {
            scale = low;
        } else if (high < scale) {
            scale = high;
        }
        score = score * scale;
    }
    float *slot;
    int count = rhythm->count;
    if (count == 16) {
        memmove(&rhythm->score[0], &rhythm->score[1], 0x3C);
        slot = &rhythm->score[rhythm->count - 1];
    } else {
        slot = &rhythm->score[count];
        rhythm->count = count + 1;
    }
    *slot = GLimitLm((LM *)rhythm->lm, score);
    rhythm->mean = GMeanRhythmScore(rhythm);
    bevy_camera_follow_activity(&B_002DEB30, 0x36, rhythm);
}
