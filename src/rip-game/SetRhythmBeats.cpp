#include "sly2.h"
void CopyAb(void *, void *, unsigned int);
extern "C" void SetRhythmState(void *, int);
struct BEAT { float time; char pad[0xC]; VECTOR pos; int hit; char pad2[0xC]; };
struct RHYTHM { char pad[0x60]; int count; char pad2[0xC]; BEAT beat[6]; char pad3[0x190 - 0x70 - 6 * 0x30]; int cursorState; int cursorBeat; char pad4[8]; VECTOR cursor; };
extern "C" void SetRhythmBeats(RHYTHM *rhythm, int state, int count, void *beats)
{
    rhythm->count = count;
    if (count != 0) {
        BEAT *list = rhythm->beat;
        CopyAb(list, beats, count * 0x30);
        VECTOR *first_cursor = &rhythm->cursor;
        float first = rhythm->beat[0].time;
        float last = rhythm->beat[rhythm->count - 1].time;
        float span = last - first;
        rhythm->cursor.x = 100.0f;
        first_cursor->y = 468.80002f;
        first_cursor->z = 0.0f;
        float scale = 440.0f / span;
        for (int i = 0; i < rhythm->count; i++) {
            list[i].pos = rhythm->cursor;
            list[i].hit = 0;
            list[i].pos.x = list[i].pos.x + scale * (list[i].time - first);
        }
        VECTOR *second = &rhythm->cursor;
        second->x = 10.0f;
        second->y = 468.80002f;
        second->z = 0.0f;
        rhythm->cursorState = 0;
        rhythm->cursorBeat = 0;
    }
    SetRhythmState(rhythm, state);
}
